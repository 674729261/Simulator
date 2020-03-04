#pragma once
#include <easyx.h>
#include <list>
#include <ctime>
#include "Vector2.h"
#include "Object.h"
using namespace std;
using Vuint2 = Vector2<unsigned int>;

class Engine //��ϵ�����漰�������򶼼ӽ�������ֻ�Ǹ����࣬���������֮��û���໥���ã����Լ�����һ���ಢ��д�麯�����ͺ�myLib����Ǽ���һ����
{//����������������������ȫ����ʵ�ֵ��������ɶ�ģ���дsimulate��������
protected:
	Vuint2 canvas;//����ߴ����ҲӦ��ֱ����Ϊ����������ȥ= =
	double freq;//����Ƶ�ʣ���ͬ�ڻ���ˢ��Ƶ��
	double scale;//����ϵ��
	list<Object*> SimList;
	unsigned int framerate;//ˢ��Ƶ��ҲӦ��ֱ����Ϊ����������ȥ= =
	Vector2<double> viewpoint;//��Ұλ�ã�ҲӦ��ֱ����Ϊ����������ȥ��������ʷ�������⣨�ӣ�

public:
	Engine(double);

	//void set_origin(Vector2<double>);
	//void set_origin(double x, double y);
	void join(Object*);//��������
	void begin();//������������Ѿ���������"begin"����
	void init();

	virtual void simulate();//����ϵ�ڵ����������������
	virtual void paint(const clock_t& time);//����
	virtual void flush();//���������ظ�����ͬһ������
	friend class System;
};