#include "Engine.h"
#include <iostream>
void Engine::simulate()
{
	list<Object*>::iterator it;
	for (it = SimList.begin(); it != SimList.end(); ++it)
	{
		//自己的力学代码
		(*it)->calc(freq);
	}
	
}

void Engine::paint(const clock_t& time)
{
	list<Object*>::iterator it;
	for (it = SimList.begin(); it != SimList.end(); ++it)
	{//我这里采用的是直接把坐标原点移到要画的地方，把代码搞简洁一点
		setorigin((canvas.x) / 2 + int(scale * ((*it)->get_pos().x - viewpoint.x)),
			(canvas.y) / 2 + int(-scale * ((*it)->get_pos().y - viewpoint.y)));
		(*it)->drawPattern(time);
	}
}

void Engine::flush()
{
	list<Object*>::iterator it;
	for (it = SimList.begin(); it != SimList.end(); ++it)
	{
		(*it)->set_update();
	}
}

Engine::Engine(double f) : freq(f)
{
}

void Engine::join(Object* obj)
{
	SimList.push_back(obj);
}

void Engine::begin()
{
	for (double t = 0.0; t < framerate * freq / 1000.0; t += 1.0)//算出这一帧间隔的时间里要运算多少次
	{
		simulate();
	}
}

void Engine::init()
{
	list<Object*>::iterator it;
	for (it = SimList.begin(); it != SimList.end(); ++it)
	{
		(*it)->set_scale(scale);
	}
}
