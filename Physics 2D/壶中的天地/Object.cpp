#include "Object.h"

Object::Object()
{
	position = Vector2{ 0.0,0.0 };
	mass = 0.0;
	elec = 0.0;
}

Object::Object(double x, double y, double m)
{
	position.x = x;
	position.y = y;
	mass = m;
	elec = 0.0;
}

Object::Object(double x, double y, double m, double e)
{
	position.x = x;
	position.y = y;
	mass = m;
	elec = e;
}

Object::Object(Vector2 pos, double m)
{
	position = pos;
	mass = m;
	elec = 0.0;
}

Object::Object(Vector2 pos, double m, double e)
{
	position = pos;
	mass = m;
	elec = e;
}

Vector2 Object::get_pos()
{
	return position;
}

Vector2 Object::get_vel()
{
	return vel;
}

double Object::get_mass()
{
	return mass;
}

double Object::get_elec()
{
	return elec;
}

void Object::set_vel(Vector2 v)
{
	vel = v;
}

void Object::set_pos(Vector2 p)
{
	position = p;
}


void Object::set_vel(double x, double y)
{
	vel.x = x;
	vel.y = y;
}

void Object::set_pos(double x, double y)
{
	position.x = x;
	position.y = y;
}

void Object::add_force(double x, double y)
{
	force.x += x;
	force.y += y;
}

void Object::add_force(Vector2 f)
{
	force += f;
}


void Object::calc(double freq)
{
	double delta = 1.0 / freq;//模拟的时间长度
	Vector2 vt = vel + (force / mass) * delta;//计算终末的速度
	Vector2 ds = ((vel + vt) * delta) / 2.0;//将每个时间段内的运动简化为匀变速运动，计算位移量

	position += ds;
	vel = vt;
	force = Vector2{ 0.0,0.0 };
}
