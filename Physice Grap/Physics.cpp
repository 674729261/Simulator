#include "Physics.h"

namespace Physics
{
	void Gravity2(Object& o, const Object& s)
	{
		Vector2<double> pos = o.get_pos() - s.get_pos();
		double dis = Module(pos);
		double M = s.get_mass();
		double force = G * M * o.get_mass() / Module2(pos);
		Vector2<double> dir = pos / dis;
		Vector2<double> F = dir * (-force);
		o.add_force(F);
	}
}