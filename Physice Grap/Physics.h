#pragma once
#include "Vector2.h"
#include "Object.h"
//һЩ�����������Ķ���
const double pi = 3.1415926535898;

namespace Physics
{
	const double G = 0.01;//����ϵ��
	void Gravity2(Object& object, const Object& source);//������������

}