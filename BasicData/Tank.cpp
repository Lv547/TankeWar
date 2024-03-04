#include "StdAfx.h"
#include "Tank.h"


Tank::Tank( int topHP, int hp,BULLET_TYPE bulletType,Vect2d* pos,DIRCTION dir,float spd,float r ):
MoveCircle(pos,dir,spd,r)
{
	_hp= hp;
	_topHp = topHP;
	_bulletType = bulletType;
	_nextOp = TANK_NONE;
}


Tank::~Tank(void)
{
}

Bullet * Tank::GetBullet()
{
	if (_nextOp == TANK_FIRE)
		return BulletFactory::GetBullet(_bulletType,_position,_dirction);
	else
		return NULL;
}

bool Tank::IsAlive()
{
	return _hp>0;
}

void Tank::GetHit( Bullet *bullet )
{
	_hp-=bullet->Damage();
}


bool Tank::IsSameDircetion( TANK_OPERATION op,DIRCTION dir )
{
	switch(op)
	{
	case TANK_UP      :return dir== DIR_UP;
	case TANK_DOWN:return dir== DIR_DOWN;
	case TANK_LEFT    :return dir== DIR_LEFT;
	case TANK_RIGHT :return dir== DIR_RIGHT;
	default:return false;
	}
}

bool Tank::IsMoveOperation( TANK_OPERATION op )
{
	return !(op==TANK_NONE || op==TANK_FIRE);
}

void Tank::Operation( int dertaTime )
{
	if(_nextOp == TANK_NONE||_nextOp==TANK_FIRE) return;

	if (IsNeedMove())
		MoveCircle::Operation(dertaTime);
	else
	    _dirction = TankOperationToDirction(_nextOp);

	_nextOp = TANK_NONE;
}

bool Tank::IsNeedMove()
{
	return IsMoveOperation(_nextOp)&&IsSameDircetion(_nextOp,_dirction);
}

DIRCTION Tank::TankOperationToDirction( TANK_OPERATION op )
{
	switch(op)
	{
	case TANK_LEFT     :return DIR_LEFT;
	case TANK_RIGHT  :return DIR_RIGHT;
	case TANK_UP       :return DIR_UP ; 
	case TANK_DOWN :return DIR_DOWN;
	default: return DIR_UP;
	}
}


