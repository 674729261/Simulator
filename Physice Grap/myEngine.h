#pragma once
#include "Engine.h"

class CenteredEngine : public Engine  //����ֻ��һ�������������ϵ��center�����������壬simList�е�����ֻ��center�����ã��˴�֮��û����
{
private:
	Object* center;//��������
public:
	using Engine::Engine;

	virtual void simulate();
	virtual void paint(const clock_t& time);
	virtual void init();
	virtual void flush();
	void set_center(Object*);
};

class MultiCenteredEngine : public Engine   //��CenteredEngine���ƣ�ֻ�������������ж������������֮��û���໥���ã�
{
private:
	list<Object*> CenterList;

public:
	using Engine::Engine;

	void join_center(Object*);

	virtual void init();
	virtual void simulate();
	virtual void paint(const clock_t& time);
	virtual void flush();
};

class GravityEngine : public Engine //�����ϵ�еĸ�������֮����ܵ��˴������������ã�@�������Ⱞ���ߣ�
{
public:
	using Engine::Engine;

	virtual void simulate();
};

class CenteredSandBoxEngine : public CenteredEngine  //δ��ɣ�Ҳ��֪��Ҫ��ʲô���ӣ�
{
public:
	using CenteredEngine::CenteredEngine;
};