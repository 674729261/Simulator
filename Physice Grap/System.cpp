#include "System.h"

System::System() :framerate(30), scale(1.0), viewpoint(Zero)
{
}

System::System(unsigned int rate) : framerate(rate), scale(1.0), viewpoint(Zero)
{
}

void System::Regist(Engine* e)
{
	eng.push_back(e);
}

void System::set_scale(double sca)
{
	scale = sca;
}

void System::set_viewpoint(double x, double y)
{
	viewpoint.x = x;
	viewpoint.y = y;
}

void System::set_viewpoint(Vector2<double> vp)
{
	viewpoint = vp;
}

void System::adjust()
{
	list<Engine*>::iterator it;
	for (it = eng.begin(); it != eng.end(); ++it)
	{
		(*it)->viewpoint = viewpoint;
		(*it)->scale = scale;
	}
}

void System::begin(bool exit_f())
{
	clock_t time = clock();
	clock_t start = clock();
	BeginBatchDraw();
	while (!exit_f())
	{
		if (clock() - time >= long(framerate))
		{
			list<Engine*>::iterator it;
			time = clock();
			for (it = eng.begin(); it != eng.end(); ++it)
			{
				(*it)->flush();
				(*it)->begin();
			}
			cleardevice();
			for (it = eng.begin(); it != eng.end(); ++it)
			{
				(*it)->paint(clock() - start);//传递的参数就是模拟开始到现在的毫秒数，Star类里的星星旋转效果就要用到时间
			}
			FlushBatchDraw();
		}
		
	}
	EndBatchDraw();
}

void System::init(unsigned int x, unsigned int y)
{
	canvas = Vuint2{ x,y };
	list<Engine*>::iterator it;
	initgraph(canvas.x, canvas.y);
	for (it = eng.begin(); it != eng.end(); ++it)
	{
		(*it)->scale = scale;
		(*it)->canvas = canvas;
		(*it)->framerate = framerate;
		(*it)->viewpoint = viewpoint;
		(*it)->init();
	}
}
