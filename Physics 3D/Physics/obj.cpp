#include "Obj.h"

Object::Object(const Coord& p, const double& m)
{
	cur_pos = p;
	mass = m;
	is_elec = false;
	is_fixed = false;
}

Object::Object(const Coord& p, const double& m, const double& e)
{
	cur_pos = p;
	mass = m;
	elec = e;
	is_elec = true;
	is_fixed = false;
}

Object::Object(const double& x, const double& y, const double& m)
{
	cur_pos.x = x;
	cur_pos.y = y;
	mass = m;
	is_elec = false;
	is_fixed = false;
}

Object::Object(const double& x, const double& y, const double& m, const double& e)
{
	cur_pos.x = x;
	cur_pos.y = y;
	mass = m;
	elec = e;
	is_elec = true;
	is_fixed = false;
}

void Object::set_vel(const Coord& v)
{
	velocity = v;
}

void Object::set_vel(const double&x , const double& y)
{
	velocity.x = x;
	velocity.y = y;
}

void Object::add_vel(const Coord& v)
{
	velocity += v;
}


void Object::add_vel(const double& x, const double& y)
{
	velocity.x += x;
	velocity.y += y;
}

void Object::add_force(const Coord& f)
{
	cur_force += f;
}

void Object::add_force(const double& x, const double& y)
{
	cur_force.x += x;
	cur_force.y += y;
}

Coord Object::get_vel() const
{
	return velocity;
}

Coord Object::get_pos() const
{
	return cur_pos;
}

const double Object::get_mass() const
{
	return mass;
}

const double Object::get_elec() const
{
	return elec;
}

void Object::fix()
{
	is_fixed = true;
}

void Object::release()
{
	is_fixed = false;
}

void Object::exec(const double& dt)
{
	Coord vt = velocity + (cur_force / (dt * mass));
	cur_pos += (velocity + vt) / (2.0 * dt);
	velocity = vt;
	cur_force = Coord{ 0, 0 };
}


Coord operator*(const double& v, Coord c)
{
	return Coord{ c.x * v,c.y * v };
}