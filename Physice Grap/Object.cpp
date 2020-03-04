#include "Object.h"
#include <easyx.h>

void Object::pick_index()//生成序号
{
	static unsigned sequence;
	index = sequence;
	++sequence;
}

Object::Object() :position(Zero), mass(1.0), elec(0.0), scale(100.0), radius(0.5)
{
	pick_index();
}

Object::Object(const double& x, const double& y, const double& m) : position(x, y), mass(m), elec(0.0), scale(100.0), radius(0.5)
{
	pick_index();
}

Object::Object(const double& x, const double& y, const  double& m, const  double& e) : position(x, y), mass(m), elec(e), scale(100.0), radius(0.5)
{
	pick_index();
}

Object::Object(const Vector2<double>& pos, const double& m) : position(pos), mass(m), elec(0.0), scale(100.0), radius(0.5)
{
	pick_index();
}

Object::Object(const Vector2<double>& pos, const double& m, const double& e) : position(pos), mass(m), elec(e), scale(100.0), radius(0.5)
{
	pick_index();
}

Vector2<double> Object::get_pos() const
{
	return position;
}

Vector2<double> Object::get_vel() const
{
	return vel;
}

double Object::get_mass() const
{
	return mass;
}

double Object::get_elec() const
{
	return elec;
}

void Object::set_vel(const Vector2<double>& v)
{
	vel = v;
}

void Object::set_pos(const Vector2<double>& p)
{
	position = p;
}


void Object::set_vel(const double& x, const double& y)
{
	vel.x = x;
	vel.y = y;
}

void Object::set_pos(const double& x, const double& y)
{
	position.x = x;
	position.y = y;
}

void Object::add_force(const double& x, const double& y)
{
	force.x += x;
	force.y += y;
}

void Object::add_force(const Vector2<double>& f)
{
	force += f;
}

void Object::set_scale(double s)
{
	scale = s;
}

void Object::set_update()
{
	update = false;
}

void Object::set_radius(double r)
{
	radius = r;
}

void Object::calc(const double& freq)
{
	double delta = 1.0 / freq;//模拟的时间长度
	Vector2<double> vt = vel + (force / mass) * delta;//计算终末的速度
	Vector2<double> ds = ((vel + vt) * delta) / s2.0;//将每个时间段内的运动简化为匀变速运动，计算位移量

	position += ds;
	vel = vt;
	force = Zero;
}

void Object::drawPattern(const clock_t& time)
{
	if (update)
		return;
	update = true;
	circle(0, 0, (int)(radius* scale));
	
}
