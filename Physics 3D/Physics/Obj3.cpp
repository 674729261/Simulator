#include "Obj3.h"

Object3::Object3(const Coord3& p, const double& m)
{
	cur_pos = p;
	mass = m;
	is_elec = false;
	is_fixed = false;
}

Object3::Object3(const Coord3& p, const double& m, const double& e)
{
	cur_pos = p;
	mass = m;
	elec = e;
	is_elec = true;
	is_fixed = false;
}


void Object3::set_vel(const Coord3& v)
{
	velocity = v;
}


void Object3::add_vel(const Coord3& v)
{
	velocity += v;
}


void Object3::add_force(const Coord3& f)
{
	cur_force += f;
}


Coord3 Object3::get_vel() const
{
	return velocity;
}

Coord3 Object3::get_pos() const
{
	return cur_pos;
}

const double Object3::get_mass() const
{
	return mass;
}

const double Object3::get_elec() const
{
	return elec;
}

void Object3::fix()
{
	is_fixed = true;
}

void Object3::release()
{
	is_fixed = false;
}

void Object3::exec(const double& dt)
{
	Coord3 vt = velocity + (cur_force / (dt * mass));
	cur_pos += (velocity + vt) / (2.0 * dt);
	velocity = vt;
	cur_force = Coord3{ 0, 0,0 };
}


Coord3 operator*(const double& v, Coord3 c)
{
	return Coord3{ c.x * v,c.y * v ,c.z * v };
}