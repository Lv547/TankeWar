#include "StdAfx.h"
#include "ConsoleView.h"
#include <conio.h>

ConsoleView::ConsoleView(void)
{
}

ConsoleView::~ConsoleView(void)
{
}

void ConsoleView::DisplayGrid( Grid* grid )
{
	if(!grid) return;

	int h  = grid->Height();
	int w = grid->Width();
	char *data = new char[h*w];

	for (int i=0;i<h*w;i++)
		data[i] = ' ';

	for(list<Bullet*>::const_iterator iter = grid->BulletList()->begin(); iter!=grid->BulletList()->end();iter++)
	{ 
		int x = (*iter)->Position()->X();
		int y = (*iter)->Position()->Y();

		data[y*w+x] = '*';
	}

	if (grid->User())
	{
		int x = grid->User()->Position()->X();
		int y = grid->User()->Position()->Y();
		data[y*w+x] = 'A';
	}

	for(list<AITank*>::const_iterator iter = grid->AiTankList()->begin(); iter!=grid->AiTankList()->end();iter++)
	{ 
		int x = (*iter)->Position()->X();
		int y = (*iter)->Position()->Y();

		data[y*w+x] = 'o';
	}

	cout<<"======================================================"<<endl;
	for (int i=0;i<h;i++)
	{
		cout<<"||";
		for (int j=0;j<w;j++)
		{
			printf("%c",data[i*w+j]);
		}
		cout<<"||"<<endl;
	}
	cout<<"======================================================"<<endl;
}

void ConsoleView::DisplayInformation( Information* information )
{
	system("cls");
	cout<<"========Information============"<<endl;

	cout<<"Score      : "<< information->Score()<<endl;
	cout<<"Time       : "<< information->PlayTime()<<endl;
	cout<<"Enemy    : "<< information->EnemyCount()<<endl;
	cout<<" HP         : "<< information->UserHp()<<endl;      

	cout<<endl;      cout<<endl;      cout<<endl;      cout<<endl;  

	if(information->Msg()) cout<<"Message : "<<*(information->Msg())<<endl;
	if(information->AlertMsg()) cout<<"AlertMsg : "<<*(information->AlertMsg())<<endl;
}

USER_OPERATION ConsoleView::GetUserOperation()
{
	char c = _getch_nolock();

	switch(c)
	{
	case 'A':case'a':return USER_LEFT;
	case 'D':case 'd':return USER_RIGHT;
	case 'W':case 'w':return USER_UP;
	case 'S':case 's':return USER_DOWN;
	case 'L':case 'l':return USER_FIRE;

	case '1':return USER_START_STOP;
	case '2':return USER_HALT_CONTINUE;
	case '3':return USER_EXIT;

	default: return USER_NONE;
	}
}

void ConsoleView::Initialization()
{
	system("cls");
}

void ConsoleView::Clear()
{
	system("cls");
}
