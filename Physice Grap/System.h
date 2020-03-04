#pragma once
#include "Engine.h"
#include <easyx.h>
#include <ctime>
#include <list>
using namespace std;
class System
{
private:
	Vuint2 canvas;//���ڳߴ�
	list<Engine*> eng;//��ϵ
	unsigned int framerate;//����Ƶ��
	double scale;//���ųߴ�

	Vector2<double> viewpoint;//��Ұλ��

public:
	System();
	System(unsigned int);

	void Regist(Engine*);//�����µ���ϵ
	void set_scale(double);
	void set_viewpoint(double, double);
	void set_viewpoint(Vector2<double>);
	void adjust();//����������ϵ������ϵ������Ұλ�ã��˺����Ĵ��ڶ�����Ϊ��ʷ��������

	void begin(bool exit_f());//��ʼģ����

	void init(unsigned int x,unsigned int y);//��ʼ��
};