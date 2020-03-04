#pragma once
#include "Engine.h"

class CenteredEngine : public Engine  //用于只有一个中心天体的体系，center就是中心天体，simList中的星球只受center的作用，彼此之间没作用
{
private:
	Object* center;//中心天体
public:
	using Engine::Engine;

	virtual void simulate();
	virtual void paint(const clock_t& time);
	virtual void init();
	virtual void flush();
	void set_center(Object*);
};

class MultiCenteredEngine : public Engine   //和CenteredEngine类似，只不过中心天体有多个（中心天体之间没有相互作用）
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

class GravityEngine : public Engine //这个体系中的各个星球之间均受到彼此万有引力作用（@三体问题爱好者）
{
public:
	using Engine::Engine;

	virtual void simulate();
};

class CenteredSandBoxEngine : public CenteredEngine  //未完成，也不知道要干什么（逃）
{
public:
	using CenteredEngine::CenteredEngine;
};