#pragma once
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;
struct Coord3//平面向量及运算
{
	double x;
	double y;
	double z;

	Coord3 operator+=(const Coord3& o)
	{
		x += o.x;
		y += o.y;
		z += o.z;
		return *this;
	}

	Coord3 operator-=(const Coord3& o)
	{
		x -= o.x;
		y -= o.y;
		z -= o.z;
		return *this;
	}

	Coord3 operator*=(const double& v)
	{
		x *= v;
		y *= v;
		z *= v;
		return *this;
	}

	Coord3 operator/=(const double& v)
	{
		x /= v;
		y /= v;
		z /= v;
		return *this;
	}

	Coord3 operator/(const double& v)
	{
		return Coord3{ x / v,y / v ,z / v };
	}

	Coord3 operator+(const Coord3& o)
	{
		return Coord3{ x + o.x, y + o.y,z + o.z };
	}

	Coord3 operator-(const Coord3& o)
	{
		return Coord3{ x - o.x, y - o.y ,z - o.z };
	}

	const double module()
	{
		return sqrt(x * x + y * y + z * z);
	}

	const double module2()
	{
		return (x * x + y * y + z * z);
	}

	Coord3 operator*(const double& v)
	{
		return Coord3{ x * v,y * v ,z * v };
	}

	Coord3 operator*(const Coord3& o)//向量积
	{
		return Coord3{ y * o.z - z * o.y,z * o.x - x * o.z ,x * o.y - y * o.z };
	}

	Coord3 operator-()
	{
		return Coord3{ -x, -y ,-z };
	}
};


class Object3//每个物体
{
private:
	Coord3 cur_pos;//位置
	Coord3 cur_force{ 0,0 };//此刻受到的力
	Coord3 velocity = { 0,0 };//速度
	double mass;//质量
	double elec;//电荷
	bool is_fixed;//位置固定
	bool is_elec;//带有电荷
public:
	Object3(const Coord3&, const double&);//位置,质量
	Object3(const Coord3&, const double&, const double&);//位置，质量，电荷

	void set_vel(const Coord3&);//设置速度
	void add_vel(const Coord3&);//增加速度

	void add_force(const Coord3&);//施加力

	Coord3 get_vel() const;
	Coord3 get_pos() const;
	const double get_mass() const;
	const double get_elec() const;

	void fix();//固定位置
	void release();//解除固定

	void exec(const double&);//进行一次计算
};