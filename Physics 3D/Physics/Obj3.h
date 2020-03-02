#pragma once
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;
struct Coord3//ƽ������������
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

	Coord3 operator*(const Coord3& o)//������
	{
		return Coord3{ y * o.z - z * o.y,z * o.x - x * o.z ,x * o.y - y * o.z };
	}

	Coord3 operator-()
	{
		return Coord3{ -x, -y ,-z };
	}
};


class Object3//ÿ������
{
private:
	Coord3 cur_pos;//λ��
	Coord3 cur_force{ 0,0 };//�˿��ܵ�����
	Coord3 velocity = { 0,0 };//�ٶ�
	double mass;//����
	double elec;//���
	bool is_fixed;//λ�ù̶�
	bool is_elec;//���е��
public:
	Object3(const Coord3&, const double&);//λ��,����
	Object3(const Coord3&, const double&, const double&);//λ�ã����������

	void set_vel(const Coord3&);//�����ٶ�
	void add_vel(const Coord3&);//�����ٶ�

	void add_force(const Coord3&);//ʩ����

	Coord3 get_vel() const;
	Coord3 get_pos() const;
	const double get_mass() const;
	const double get_elec() const;

	void fix();//�̶�λ��
	void release();//����̶�

	void exec(const double&);//����һ�μ���
};