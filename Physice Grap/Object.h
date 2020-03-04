#pragma once
#include "Vector2.h"
#include <ctime>
class Engine;


class Object
{
private:
protected:
	Vector2<double> position;//��ǰλ��
	double mass;//����
	double elec;//���
	double radius;//�ߴ�
	unsigned index;//��ţ�Ŀǰ��û���õ���������
	Vector2<double> vel;//��ǰ�ٶ�
	Vector2<double> force;//��ǰ����

	double scale;//����ϵ����������Ӧ��ֱ����Ϊ��������drawPattern���������ø��ˣ��ӣ�
	void pick_index();//�������
	bool update = false;//���������ظ�����


public:
	Object();
	Object(const double& x, const double& y, const double& m);
	Object(const double& x, const double& y, const double& m, const double& e);//ÿ���漰������ķ������ṩVector2<double>��double�����汾
	Object(const Vector2<double>& pos, const double& m);
	Object(const Vector2<double>& pos, const double& m, const double& e);

	Vector2<double> get_pos() const;//���ڻ��λ���ٶ���Ϣ���
	Vector2<double> get_vel() const;
	double get_mass() const;
	double get_elec() const;


	void set_vel(const Vector2<double>& v);
	void set_pos(const Vector2<double>& p);//����������Ϣ

	void set_vel(const double& x, const double& y);
	void set_pos(const double& x, const double& y);


	void add_force(const double& x, const double& y);//ʩ����
	void add_force(const Vector2<double>& f);

	void set_scale(double s);
	void set_update();//���������ظ�����
	virtual void calc(const double& freq);//ִ��һ��ģ�����

	virtual void drawPattern(const clock_t& time);

	void set_radius(double r);



	friend class Engine;
};