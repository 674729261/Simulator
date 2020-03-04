#pragma once
#include "Vector2.h"
#include "Object.h"
//一些方便物理计算的东西
const double pi = 3.1415926535898;

namespace Physics
{
	const double G = 0.01;//引力系数
	void Gravity2(Object& object, const Object& source);//计算万有引力

}