#include <iostream>
#include "Vector2.h"
#include "Object.h"
#include <fstream>
#include <cmath>

using namespace std;
const double freq = 8000.0;//工作频率
const double time = 8.0;//模拟时长
void Gravity0(Object&);//example
void Gravity(Object&);//example
void Gravity2(Object&);//example
void Gravity3(Object&);//example
void GravityX(Object&, double);//example
void Magn(Object&);//example
void Spring(Object&);//example

int main(void)
{
	/*
	Vector2 testV1(2.0, 3.0);
	Vector2 testV2(-1.0, 5.0);

	Vector2 r = 2.0 * testV2;
	cout << r.x << r.y;
	*/

	ofstream out("out.txt");
	Object o(2.0, 0.0, 1.0);
	o.set_vel(0.0, 1.0);
	int i = 0;
	for (double t = 0.0; t < time * freq; t += 1.0)
	{
		//o.add_force(0.0, -1.0);
		//o.add_force(0.0, -10.0);
		//Spring(o);
		GravityX(o, 1);
		o.calc(freq);

		if (i >= 6)
		{
			out << o.get_pos().x << " " << o.get_pos().y << endl;
			i = 0;
		}
		else
		{
			++i;
		}
	}
	out.close();
	return 0;
}

void Gravity0(Object& o)
{
	Vector2 pos = o.get_pos();
	double dis = Module(pos);
	double M = 1.0;
	double G = 1.0;
	double force = G * M * o.get_mass();
	Vector2 dir = pos / dis;
	Vector2 F = dir * (-force);
	o.add_force(F);
}


void Gravity(Object& o)
{
	Vector2 pos = o.get_pos();
	double dis = Module(pos);
	double M = 1.0;
	double G = 1.0;
	double force = G * M * o.get_mass() / Module2(pos);
	Vector2 dir = pos / dis;
	Vector2 F = dir * (-force);
	o.add_force(F);
}

void Gravity2(Object& o)
{
	Vector2 pos = o.get_pos();
	double dis = Module(pos);
	double M = 1.0;
	double G = 1.0;
	double force = G * M * o.get_mass() * dis;
	Vector2 dir = pos / dis;
	Vector2 F = dir * (-force);
	o.add_force(F);
}

void Gravity3(Object& o)
{
	Vector2 pos = o.get_pos();
	double dis = Module(pos);
	double M = 1.0;
	double G = 1.0;
	double force = G * M * o.get_mass() * Module2(pos);
	Vector2 dir = pos / dis;
	Vector2 F = dir * (-force);
	o.add_force(F);
}

void GravityX(Object& o, double power)
{
	Vector2 pos = o.get_pos();
	double dis = Module(pos);
	double M = 1.0;
	double G = 1.0;
	double force = G * M * o.get_mass() * pow(Module(pos), power);
	Vector2 dir = pos / dis;
	Vector2 F = dir * (-force);
	o.add_force(F);
}

void Magn(Object& o)
{
	Vector2 v = o.get_vel();
	Vector2 dir = Vector2(-v.y, v.x) / Module(v);
	double f = o.get_elec() * Module(v) * 1.0;
	Vector2 Force = f * dir;
	o.add_force(Force);
}

void Spring(Object& o)
{
	double length = 1.0;
	double k = 1.0;

	Vector2 s = -o.get_pos();
	Vector2 dir = s / Module(s);
	double f = k * (Module(s) - length);
	Vector2 Force = f * dir;
	o.add_force(Force);
}