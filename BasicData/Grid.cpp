#include "StdAfx.h"
#include "Grid.h"

Grid::Grid(int height,int width)
{
	_height = height;
	_width = width;

	_aiTankList = new list<AITank*>();
	_bulletList = new list<Bullet*>();
}


Grid::~Grid(void)
{
	for (list<Bullet *>::iterator iter = _bulletList->begin();iter!=_bulletList->end();iter++)
    {
		Bullet *b = (*iter);
		delete b;
    }

	for (list<AITank *>::iterator iter = _aiTankList->begin();iter!=_aiTankList->end();iter++)
	{
		AITank *t = (*iter);
        delete t;
	}

	delete _bulletList;
	delete _aiTankList;
	delete _user;
}

bool Grid::IsInside( Circle *obj )
{
	float w = _width;
	float h = _height;
	float x = obj->Position()->X();
	float y = obj->Position()->Y();
    float radius = obj->Radius();
	float l = x- radius;
	float r= x+radius;
	float t = y- radius;
	float b= y+radius;

	return!( l<0||r>w||t<0||b>h);
}
