#pragma once
#include "Vector2.h"

class Object
{
private:
	Vector2 position;//��ǰλ��
	double mass;//����
	double elec;//���
	
	Vector2 vel;//��ǰ�ٶ�
	Vector2 force;//��ǰ����
public:
	Object();
	Object(double x, double y, double m);
	Object(double x, double y, double m, double e);//ÿ���漰������ķ������ṩVector2��double�����汾
	Object(Vector2 pos, double m);
	Object(Vector2 pos, double m, double e);

	Vector2 get_pos();//���ڻ��λ���ٶ���Ϣ���
	Vector2 get_vel();
	double get_mass();
	double get_elec();

	void set_vel(Vector2 v);
	void set_pos(Vector2 p);//����������Ϣ

	void set_vel(double x, double y);
	void set_pos(double x, double y);

	void add_force(double x, double y);
	void add_force(Vector2 f);

	void calc(double freq);//ִ��һ��ģ�����
};