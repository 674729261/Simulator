#pragma once
#include "Object.h"
#include <ctime>
#include "Physics.h"
#include <graphics.h>
class FixedObj : public Object  //λ�ö�ס�ĵ�����
{
public:
	using Object::Object;

	void calc(const double& freq) {};
	virtual void drawPattern(const clock_t& time);
};

class Star : public Object  //��Object����ûɶ���𣬾��ǳ���������Σ�Star����Ϊд��һ�����û�������(��
{
private:
	Vector2<double> angle[5];
public:
	using Object::Object;

	virtual void drawPattern(const clock_t& time);
};