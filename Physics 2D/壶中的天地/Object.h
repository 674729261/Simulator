#pragma once
#include "Vector2.h"

class Object
{
private:
	Vector2 position;//当前位置
	double mass;//质量
	double elec;//电荷
	
	Vector2 vel;//当前速度
	Vector2 force;//当前受力
public:
	Object();
	Object(double x, double y, double m);
	Object(double x, double y, double m, double e);//每个涉及到坐标的方法均提供Vector2和double两个版本
	Object(Vector2 pos, double m);
	Object(Vector2 pos, double m, double e);

	Vector2 get_pos();//用于获得位置速度信息输出
	Vector2 get_vel();
	double get_mass();
	double get_elec();

	void set_vel(Vector2 v);
	void set_pos(Vector2 p);//用于设置信息

	void set_vel(double x, double y);
	void set_pos(double x, double y);

	void add_force(double x, double y);
	void add_force(Vector2 f);

	void calc(double freq);//执行一次模拟计算
};