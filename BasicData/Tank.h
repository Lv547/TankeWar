#pragma once
#include "MoveCircle.h"
#include "BulletFactory.h"

#ifndef ENUM_TANK_TYPE
#define  ENUM_TANK_TYPE
enum TANK_TYPE
{
	TANK_USER,
	TANK_AI_STD
};
#endif

#ifndef ENUM_TANK_OPERATION
#define  ENUM_TANK_OPERATION
enum TANK_OPERATION
{
	TANK_UP,
	TANK_DOWN,
	TANK_LEFT,
	TANK_RIGHT,
	TANK_FIRE,
	TANK_NONE
};
const int TANK_OPERATION_COUNT = 6;
#endif

class Tank:
	public MoveCircle
{
protected:
	int _hp;
	int _topHp;
	BULLET_TYPE _bulletType;
	TANK_OPERATION _nextOp;

public:
	Tank(int topHP, int hp,BULLET_TYPE bulletType,Vect2d* pos,DIRCTION dir,float spd,float r);
	~Tank(void);

	int Hp() const { return _hp; }
	void Hp(int val) { _hp = val; }

	int TopHp() const { return _topHp; }
	void TopHp(int val) { _topHp = val; }

	BULLET_TYPE BulletType() const { return _bulletType; }
	void BulletType(BULLET_TYPE val) { _bulletType = val; }

	TANK_OPERATION NextOp() const { return _nextOp; }
	void NextOp(TANK_OPERATION val) { _nextOp = val; }

	// over ride
	virtual void Operation( int dertaTime );
	
	virtual bool IsAlive();
	virtual bool IsNeedMove();

	virtual Bullet * GetBullet();
	virtual void GetHit(Bullet *bullet);

	static bool IsMoveOperation(TANK_OPERATION op);
	static bool IsSameDircetion(TANK_OPERATION op,DIRCTION dir);
	static DIRCTION TankOperationToDirction(TANK_OPERATION op);
};
