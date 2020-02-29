#include "Obj.h"
#include "Obj3.h"
#include <iostream>
const double G = 3;
const double dt = 200000;//每秒进行的运算次数
const double time = 64;//模拟总时长

void GField(Object&);

int main()
{
	//Object planet(4, 0, 3);
	//planet.set_vel(0, 1);

	ofstream of("out1.txt");
	ofstream of2("out2.txt");
	ofstream of3("out3.txt");

	Object3 m1({ 1,0,0 }, 1.5);
	Object3 m2({ -2,0,0 }, 1);
	Object3 m3({ 0,3,1 }, 2.5);

	m1.set_vel({ 1,0,0 });
	m2.set_vel({ 0,1,0 });
	m3.set_vel({ 0,1,1 });
	double f = 0.0;
	Coord3 dir = { 0,0,0 };
	Coord3 k = { 0,0,0 };
	for (double n = 0.0, i = 0.0; i <= time * dt; i = i + 1.0)
	{
		/*GField(planet);
		planet.exec(dt);//每次循环进行一次运算
		//planet.add_force(Coord{ 0,1 });
		if (i - n >= 4000.0)
		{
			of << planet.get_pos().x << ' ' << planet.get_pos().y << endl;
			n = i;
		}
		*/
		Coord3 p1 = m1.get_pos(), p2 = m2.get_pos(), p3 = m3.get_pos();
		double n1 = m1.get_mass(), n2 = m2.get_mass(), n3 = m3.get_mass();
		k = p2 - p1;
		dir = k / k.module();
		f = G * n1 * n2 / k.module2();
		m1.add_force(dir * f);

		k = p3 - p1;
		dir = k / k.module();
		f = G * n1 * n3 / k.module2();
		m1.add_force(dir * f);

		k = p1 - p2;
		dir = k / k.module();
		f = G * n2 * n1 / k.module2();
		m2.add_force(dir * f);

		k = p3 - p2;
		dir = k / k.module();
		f = G * n2 * n3 / k.module2();
		m2.add_force(dir * f);

		k = p1 - p3;
		dir = k / k.module();
		f = G * n3 * n1 / k.module2();
		m3.add_force(dir * f);

		k = p2 - p3;
		dir = k / k.module();
		f = G * n3 * n2 / k.module2();
		m3.add_force(dir * f);

		m1.exec(dt);
		m2.exec(dt);
		m3.exec(dt);
		if (i - n >= 32000.0)
		{
			of << m1.get_pos().x/4.0 << ' ' << m1.get_pos().y/4.0 << ' ' << m1.get_pos().z/4.0<< endl;
			of2 << m2.get_pos().x / 4.0 << ' ' << m2.get_pos().y / 4.0 << ' ' << m2.get_pos().z / 4.0 << endl;
			of3 << m3.get_pos().x / 4.0 << ' ' << m3.get_pos().y / 4.0 << ' ' << m3.get_pos().z / 4.0 << endl;
			n = i;
		}

	}
	of.close();
	of2.close();
	of3.close();
	return 0;
}

void GField(Object& o) //用函数表示一个力场，此为万有引力场
{
	const double mass = 10.0;
	Coord p = o.get_pos();
	double f = G * o.get_mass() * mass / p.module2();
	Coord dir{ -p.x / p.module(),-p.y / p.module() };
	o.add_force(dir * f);
}