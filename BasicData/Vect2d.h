#pragma once

class Vect2d
{
private:
	float _x;
	float _y;

public:
	Vect2d(void);
	Vect2d(Vect2d *val);
	Vect2d(float x,float y);
	~Vect2d(void);

	float X() const { return _x; }
	void X(float val) { _x = val; }

	float Y() const { return _y; }
	void Y(float val) { _y = val; }
	
	float R();

	void operator +(Vect2d *val);
	void operator +(Vect2d val);
	bool operator ==(Vect2d *val);
	bool operator ==(Vect2d val);

	void AddX(float dx);
	void AddY(float dy);
	
    Vect2d *Clone();
	float Distance(Vect2d *other);

	static float Distance(Vect2d *val1,Vect2d *val2);
};
