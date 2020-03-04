#pragma once
#include "Vector2.h"
#include <ctime>
class Engine;


class Object
{
private:
protected:
	Vector2<double> position;//当前位置
	double mass;//质量
	double elec;//电荷
	double radius;//尺寸
	unsigned index;//序号，目前还没有用到（捂脸）
	Vector2<double> vel;//当前速度
	Vector2<double> force;//当前受力

	double scale;//缩放系数，理论上应该直接作为参数传给drawPattern函数，懒得改了（逃）
	void pick_index();//生成序号
	bool update = false;//用来避免重复绘制


public:
	Object();
	Object(const double& x, const double& y, const double& m);
	Object(const double& x, const double& y, const double& m, const double& e);//每个涉及到坐标的方法均提供Vector2<double>和double两个版本
	Object(const Vector2<double>& pos, const double& m);
	Object(const Vector2<double>& pos, const double& m, const double& e);

	Vector2<double> get_pos() const;//用于获得位置速度信息输出
	Vector2<double> get_vel() const;
	double get_mass() const;
	double get_elec() const;


	void set_vel(const Vector2<double>& v);
	void set_pos(const Vector2<double>& p);//用于设置信息

	void set_vel(const double& x, const double& y);
	void set_pos(const double& x, const double& y);


	void add_force(const double& x, const double& y);//施加力
	void add_force(const Vector2<double>& f);

	void set_scale(double s);
	void set_update();//用来避免重复绘制
	virtual void calc(const double& freq);//执行一次模拟计算

	virtual void drawPattern(const clock_t& time);

	void set_radius(double r);



	friend class Engine;
};