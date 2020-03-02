#ifndef _OBJ_H
#define _OBJ_H
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;
struct Coord//平面向量及运算
{
	double x;
	double y;

	Coord operator+=(const Coord& o)
	{
		x += o.x;
		y += o.y;
		return *this;
	}

	Coord operator-=(const Coord& o)
	{
		x -= o.x;
		y -= o.y;
		return *this;
	}

	Coord operator*=(const double& v)
	{
		x *= v;
		y *= v;
		return *this;
	}

	Coord operator/=(const double& v)
	{
		x /= v;
		y /= v;
		return *this;
	}

	Coord operator/(const double& v)
	{
		return Coord{ x / v,y / v };
	}

	Coord operator+(const Coord& o)
	{
		return Coord{x + o.x, y + o.y};
	}

	Coord operator-(const Coord& o)
	{
		return Coord{ x - o.x, y - o.y };
	}

	const double module()
	{
		return sqrt(x * x + y * y);
	}

	const double module2()
	{
		return (x * x + y * y);
	}

	Coord operator*(const double& v)
	{
	return Coord{ x * v,y * v };
	}


	Coord operator-()
	{
		return Coord{ -x, -y };
	}
};


class Object//每个物体
{
private:
	Coord cur_pos;//位置
	Coord cur_force{ 0,0 };//此刻受到的力
	Coord velocity = { 0,0 };//速度
	double mass;//质量
	double elec;//电荷
	bool is_fixed;//位置固定
	bool is_elec;//带有电荷
public:
	Object(const Coord&,const double&);//位置,质量
	Object(const Coord&,const double&,const double&);//位置，质量，电荷
	Object(const double&, const double&, const double&);//x,y,质量
	Object(const double&, const double&, const double&, const double&);//x,y,质量，电荷

	void set_vel(const Coord&);//设置速度
	void set_vel(const double&, const double&);
	void add_vel(const Coord&);//增加速度
	void add_vel(const double&, const double&);

	void add_force(const Coord&);//施加力
	void add_force(const double&, const double&);

	Coord get_vel() const;
	Coord get_pos() const;
	const double get_mass() const;
	const double get_elec() const;

	void fix();//固定位置
	void release();//解除固定

	void exec(const double&);//进行一次计算
};

#endif