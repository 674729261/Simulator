#pragma once
#include "Engine.h"
#include <easyx.h>
#include <ctime>
#include <list>
using namespace std;
class System
{
private:
	Vuint2 canvas;//窗口尺寸
	list<Engine*> eng;//体系
	unsigned int framerate;//绘制频率
	double scale;//缩放尺寸

	Vector2<double> viewpoint;//视野位置

public:
	System();
	System(unsigned int);

	void Regist(Engine*);//加入新的体系
	void set_scale(double);
	void set_viewpoint(double, double);
	void set_viewpoint(Vector2<double>);
	void adjust();//调整各个体系的缩放系数和视野位置，此函数的存在都是因为历史遗留问题

	void begin(bool exit_f());//开始模拟了

	void init(unsigned int x,unsigned int y);//初始化
};