#include "myObject.h"
#include <easyx.h>
void FixedObj::drawPattern(const clock_t& time)
{
	if (update)
		return;
	update = true;
	circle(0, 0, int(radius * scale));
}

void Star::drawPattern(const clock_t& time)
{
	double delta = double(time % 2000) / 1000.0 * pi;
	int points[10] = { int(radius * scale * cos(delta)),int(radius * scale * sin(delta)),
		int(radius * scale * cos(pi * 2.0 / 5.0 + delta)) ,int(radius * scale * sin(pi * 2.0 / 5.0 + delta)),
		int(radius * scale * cos(pi * 4.0 / 5.0 + delta)),int(radius * scale * sin(pi * 4.0 / 5.0 + delta)),
		int(radius * scale * cos(pi * 6.0 / 5.0 + delta)),int(radius * scale * sin(pi * 6.0 / 5.0 + delta)),
		int(radius * scale * cos(pi * 8.0 / 5.0 + delta)),int(radius * scale * sin(pi * 8.0 / 5.0 + delta)),
	};
	drawpoly(5, points);
}
