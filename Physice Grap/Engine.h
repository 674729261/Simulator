#pragma once
#include <easyx.h>
#include <list>
#include <ctime>
#include "Vector2.h"
#include "Object.h"
using namespace std;
using Vuint2 = Vector2<unsigned int>;

class Engine //体系，把涉及到的星球都加进来（这只是个基类，加入的星球之间没有相互作用，请自己派生一个类并改写虚函数，就和myLib里的那几个一样）
{//并不局限于万有引力，完全可以实现电磁力弹簧啥的，改写simulate函数即可
protected:
	Vuint2 canvas;//画面尺寸这个也应该直接作为参数传递下去= =
	double freq;//计算频率，不同于画面刷新频率
	double scale;//缩放系数
	list<Object*> SimList;
	unsigned int framerate;//刷新频率也应该直接作为参数传递下去= =
	Vector2<double> viewpoint;//视野位置，也应该直接作为参数传递下去，都是历史遗留问题（逃）

public:
	Engine(double);

	//void set_origin(Vector2<double>);
	//void set_origin(double x, double y);
	void join(Object*);//加入星球
	void begin();//现在这个函数已经不是用来"begin"的了
	void init();

	virtual void simulate();//对体系内的星球进行物理运算
	virtual void paint(const clock_t& time);//绘制
	virtual void flush();//用来避免重复绘制同一个对象
	friend class System;
};