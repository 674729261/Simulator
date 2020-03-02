#ifndef _OBJ_H
#define _OBJ_H
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;
struct Coord//ƽ������������
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


class Object//ÿ������
{
private:
	Coord cur_pos;//λ��
	Coord cur_force{ 0,0 };//�˿��ܵ�����
	Coord velocity = { 0,0 };//�ٶ�
	double mass;//����
	double elec;//���
	bool is_fixed;//λ�ù̶�
	bool is_elec;//���е��
public:
	Object(const Coord&,const double&);//λ��,����
	Object(const Coord&,const double&,const double&);//λ�ã����������
	Object(const double&, const double&, const double&);//x,y,����
	Object(const double&, const double&, const double&, const double&);//x,y,���������

	void set_vel(const Coord&);//�����ٶ�
	void set_vel(const double&, const double&);
	void add_vel(const Coord&);//�����ٶ�
	void add_vel(const double&, const double&);

	void add_force(const Coord&);//ʩ����
	void add_force(const double&, const double&);

	Coord get_vel() const;
	Coord get_pos() const;
	const double get_mass() const;
	const double get_elec() const;

	void fix();//�̶�λ��
	void release();//����̶�

	void exec(const double&);//����һ�μ���
};

#endif