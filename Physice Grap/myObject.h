#pragma once
#include "Object.h"
#include <ctime>
#include "Physics.h"
#include <graphics.h>
class FixedObj : public Object  //位置定住的的天体
{
public:
	using Object::Object;

	void calc(const double& freq) {};
	virtual void drawPattern(const clock_t& time);
};

class Star : public Object  //和Object基类没啥区别，就是长得像五边形，Star是因为写到一半懒得画星星了(逃
{
private:
	Vector2<double> angle[5];
public:
	using Object::Object;

	virtual void drawPattern(const clock_t& time);
};