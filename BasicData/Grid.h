#pragma once

#include <list>
using namespace std;

#include "BulletFactory.h"
#include "TankFactory.h"


class Grid
{
private:
	int _height;
	int _width;
	
	list<AITank*> *_aiTankList;
	list<Bullet*> *_bulletList;

	UserTank *_user;

public:
	Grid(int height,int width);
	~Grid(void);

	int Height() const { return _height; }
	void Height(int val) { _height = val; }
	int Width() const { return _width; }
	void Width(int val) { _width = val; }
 	UserTank * User() const { return _user; }
 	void User(UserTank * val) { _user = val; }
	list<AITank*> * AiTankList() const { return _aiTankList; }
	void AiTankList(list<AITank*> * val) { _aiTankList = val; }
	list<Bullet*> * BulletList() const { return _bulletList; }
	void BulletList(list<Bullet*> * val) { _bulletList = val; }

	bool IsInside(Circle *obj);
};
