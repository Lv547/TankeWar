
#include "StdAfx.h"
#include "ModelB.h"

ModelB::ModelB(void)
{
	_wave = _totalTime = _score = 0;
	_grid = NULL;
	_msg = NULL;
}

ModelB::~ModelB(void)
{
	delete _grid;
	delete _msg;
	_grid = NULL;
	_msg = NULL;
}

Grid* ModelB::GetGird()
{
	return _grid;
}

Information* ModelB::GetInformation()
{
	Information* info = new Information();

	info->Msg(_msg);
	info->Score(_score);
	info->AlertMsg(NULL);
	info->PlayTime(_totalTime/CLOCKS_PER_SEC);

	if (_grid)
	{
		info->EnemyCount(_grid->AiTankList()->size());
		info->UserHp(_grid->User()->Hp());
	}

	return info;
}

void ModelB::Initialization()
{
	_wave = _totalTime = 0;
	_grid = new Grid(GIRD_HEIGHT,GIRD_WIDTH);
	_grid->User((UserTank *)(TankFactory::GetTank(TANK_USER,new Vect2d(_grid->Width()/2,_grid->Height()/2),DIR_UP,TANK_RADIUS)));
	_msg = NULL;
}

void ModelB::Clear()
{
	_wave = _totalTime = _score = 0;
	delete _grid;
	delete _msg;
	_grid = NULL;
	_msg = NULL;
}

bool ModelB::IsWin()
{
	if (_grid && _wave)
		return _grid->AiTankList()->size() == 0;
	else
		return false;
}

bool ModelB::IsLose()
{
	if (_grid)
		return (_grid->AiTankList()->size() >TOP_ENIMY_COUNT) ||(! (_grid->User()->IsAlive()));
	else
		return false;
}

void ModelB::FrameStart( int dertaTime, TANK_OPERATION op )
{
	if (_grid)
	{
		_totalTime+=dertaTime;
		UserOperation(dertaTime,op);
		BulletsOperation(dertaTime);
		TanksOperation(dertaTime);

		if(NeedNewWave()) NewWave();
	}
}

void ModelB::UserOperation(  int dertaTime,TANK_OPERATION op )
{
	UserTank* tank = _grid->User();
	list<AITank *> *tanklist = _grid->AiTankList();

	tank->LoadOperation(op);

	// Operation: if need move first check can the user's tank move? else just do the operation
	if (tank->IsNeedMove())
	{	
		//can move?
		Circle* c = tank->GetNextPosition(dertaTime);
		if ( _grid->IsInside(c))
		{
			// check impact with other tanks
			bool isImpact = false;
			for ( list<AITank *>::iterator iter = tanklist->begin();iter!=tanklist->end();iter++)
				if (c->IsImpact(*iter)){isImpact = true;break;}

				// if next position inside the area and not impact with other tanks move
			if (!isImpact)  tank->Operation(dertaTime);
		}
	}
	else
	{
		//other operation such as fire or turn or just do nothing
		tank->Operation(dertaTime);
	}

	// fire
	Bullet *b = tank->GetBullet();
	if (b)  _grid->BulletList()->push_back(b);
	// 子弹太多就去掉最老的
	if (_grid->BulletList()->size()>50)
	{
		Bullet *b =*( _grid->BulletList()->begin());
		_grid->BulletList()->pop_front();
		delete b;
	}
}

void ModelB::BulletsOperation( int dertaTime )
{
	UserTank* user_tank = _grid->User();
	list<AITank *> *tanklist = _grid->AiTankList();
	list<Bullet *> *bulletlist = _grid->BulletList();
	list<AITank *>::iterator titer;
	list<Bullet *>::iterator biter;

	// for every bullet
	for (biter = bulletlist->begin();biter!=bulletlist->end();biter++)
	{
		Bullet *b = (*biter);
		b->Operation(dertaTime);//move

		if (!(_grid->IsInside(b)))// out of area
		{
			list<Bullet *>::iterator tmp = biter++;
			Bullet *b = *tmp;
			delete b;
			bulletlist->erase(tmp);break;
		}

		if (b->IsFromUser())//hit tanks
		{
			// if form user check all AI tanks
			bool isImapct = false;
			for (titer = tanklist->begin();titer!=tanklist->end();titer++)
			{
				AITank *t = (*titer);
				if (b->IsImpact(t))
				{
					t->GetHit(b);

					if (!(t->IsAlive()))// user kill ai tank
					{
						_score++;
						list<AITank *>::iterator temp = titer ++;
						AITank *b = *temp;
						delete b;
						tanklist->erase(temp);
					}

					list<Bullet *>::iterator tmp = biter++;
					Bullet *b = *tmp;
					delete b;
					bulletlist->erase(tmp);
					isImapct = true;break;
				}
			}
			if(isImapct) break;
		} 
		else
		{
			//if not from user only check user's tank
			if (b->IsImpact(user_tank))
			{
				user_tank->GetHit(b);
				list<Bullet *>::iterator tmp = biter++;
				Bullet *b = *tmp;
				delete b;
				bulletlist->erase(tmp);break;
			}
		}
	}
}

void ModelB::TanksOperation( int dertaTime )
{
	UserTank* user_tank = _grid->User();
	list<AITank *> *tanklist = _grid->AiTankList();
	list<AITank *>::iterator i,j;

	for (i = tanklist->begin();i!=tanklist->end();i++)
	{
		AITank *t = (*i);
		t->GetAIOperation();

		if (t->IsNeedMove())
		{
			Circle *c = t->GetNextPosition(dertaTime);

			//if inside grid
			if(!_grid->IsInside(c)) break;

			// if impact user tank break
			if (c->IsImpact(user_tank)) break;

			// if impact other AI tank break
			bool isImpact = false;
			for (j = tanklist->begin();j!=tanklist->end();j++)
			{
				if(i!=j && c->IsImpact(*j)) 
				{
					isImpact = true;break;
				}
			}
			if(!isImpact)//move
				t->Operation(dertaTime);
		} 
		else
		{
			t->Operation(dertaTime);
		}

		Bullet *b = t->GetBullet();
		if(b) _grid->BulletList()->push_back(b);

		// 子弹太多就去掉最老的
		if (_grid->BulletList()->size()>50)
		{
			Bullet *b =*( _grid->BulletList()->begin());
            _grid->BulletList()->pop_front();
			delete b;
		}
	}
}

void ModelB::NewWave()
{
	// 3 tanks per 10 second
	_wave++;
	list<AITank *> *tanklist = _grid->AiTankList();
	UserTank* user_tank = _grid->User();
	list<AITank *>::iterator j;

   int count = 0;
   while(count<WAVE_COUNT)
   {
       int x = (clock()+rand())%(_grid->Width()-2*(TANK_RADIUS+1))+TANK_RADIUS+1;
	   int y =  (clock()+rand())%(_grid->Height()-2*(TANK_RADIUS+1))+TANK_RADIUS+1;
	   Circle *c = new Circle(new Vect2d(x,y),TANK_RADIUS);

	   if (c->IsImpact(user_tank)) continue;// not impact user tank

	   bool isImpact = false; // not impact existed ai tanks
	   for (j = tanklist->begin();j!=tanklist->end();j++)
		   if( c->IsImpact(*j)) 
		   {  
			   isImpact = true;
			   break;
		   }

	   if(isImpact) continue;

	   tanklist->push_back((AITank*)(TankFactory::GetTank(TANK_AI_STD,new Vect2d(x,y),DIR_UP,TANK_RADIUS)));
	   count++;
   }
}

bool ModelB::NeedNewWave()
{
	// 3 tanks per 10 second
	return (_wave*10)<(_totalTime/CLOCKS_PER_SEC);
}
