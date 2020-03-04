#include "myEngine.h"
#include "Physics.h"

void CenteredEngine::simulate()
{
	list<Object*>::iterator it;
	for (it = SimList.begin(); it != SimList.end(); ++it)
	{
		list<Object*>::iterator it2;
		for (it2 = it; it2 != SimList.end(); ++it2)
		{
			//自己的力学代码
			if (it2 == it)
				continue;
			Physics::Gravity2(**it2, **it);
			Physics::Gravity2(**it, **it2);
		}
		Physics::Gravity2(**it, *center);
		(*it)->calc(freq);
	}
}

void CenteredEngine::paint(const clock_t& time)
{
	Engine::paint(time);
	setorigin(canvas.x / 2 + int(scale * (center->get_pos().x - viewpoint.x)), 
		int(canvas.y / 2 + int(-scale * (center->get_pos().y - viewpoint.y))));
	center->drawPattern(time);
}

void CenteredEngine::init()
{
	Engine::init();
	center->set_scale(scale);
}

void CenteredEngine::flush()
{
	Engine::flush();
	center->set_update();
}

void CenteredEngine::set_center(Object* c)
{
	center = c;
}

void MultiCenteredEngine::join_center(Object* obj)
{
	CenterList.push_back(obj);
}

void MultiCenteredEngine::init()
{
	Engine::init();
	list<Object*>::iterator it;
	for (it = CenterList.begin(); it != CenterList.end(); ++it)
	{
		(*it)->set_scale(scale);
	}
}

void MultiCenteredEngine::simulate()
{
	list<Object*>::iterator it;
	for (it = SimList.begin(); it != SimList.end(); ++it)
	{
		list<Object*>::iterator it_centers;
		for (it_centers = CenterList.begin(); it_centers != CenterList.end(); ++it_centers)
		{
			Physics::Gravity2(**it, **it_centers);
		}
		(*it)->calc(freq);
	}

}

void MultiCenteredEngine::paint(const clock_t& time)
{
	Engine::paint(time);
	list<Object*>::iterator it_centers;
	for (it_centers = CenterList.begin(); it_centers != CenterList.end(); ++it_centers)
	{
		setorigin(canvas.x / 2 + int(scale * ((*it_centers)->get_pos().x -viewpoint.x)),
			int(canvas.y / 2 + int(-scale * ((*it_centers)->get_pos().y -viewpoint.y))));
		(*it_centers)->drawPattern(time);
	}

}

void MultiCenteredEngine::flush()
{
	Engine::flush();
	list<Object*>::iterator it;
	for (it = CenterList.begin(); it != CenterList.end(); ++it)
	{
		(*it)->set_update();
	}
}

void GravityEngine::simulate()
{

	list<Object*>::iterator it;
	for (it = SimList.begin(); it != SimList.end(); ++it)
	{
		list<Object*>::iterator it2;
		for (it2 = it; it2 != SimList.end();++it2)
		{
			//自己的力学代码
			if (it2 == it)
				continue;
			Physics::Gravity2(**it2, **it);
			Physics::Gravity2(**it, **it2);
		}
		(*it)->calc(freq);
	}
}
