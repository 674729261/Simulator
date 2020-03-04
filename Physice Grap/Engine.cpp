#include "Engine.h"
#include <iostream>
void Engine::simulate()
{
	list<Object*>::iterator it;
	for (it = SimList.begin(); it != SimList.end(); ++it)
	{
		//�Լ�����ѧ����
		(*it)->calc(freq);
	}
	
}

void Engine::paint(const clock_t& time)
{
	list<Object*>::iterator it;
	for (it = SimList.begin(); it != SimList.end(); ++it)
	{//��������õ���ֱ�Ӱ�����ԭ���Ƶ�Ҫ���ĵط����Ѵ������һ��
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
	for (double t = 0.0; t < framerate * freq / 1000.0; t += 1.0)//�����һ֡�����ʱ����Ҫ������ٴ�
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
