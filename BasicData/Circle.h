#pragma once
#include "Vect2d.h"

class Circle
{
protected:
	float _radius;
	Vect2d *_position;

public:
	Circle(float x,float y,float r=0);
	Circle(Vect2d *position,float radius = 0);
	~Circle(void);

	Vect2d * Position() const { return _position; }
	void Position(Vect2d * val) { _position = val; }

	float Radius() const { return _radius; }
	void Radius(float val) { _radius = val; }

	bool IsImpact(Circle *other) const;
    
	static bool IsImpact(const Circle *c1 ,const Circle *c2);
};
