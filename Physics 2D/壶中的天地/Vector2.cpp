#include "Vector2.h"
/*
这里定义Vector2类的各种运算方法
*/

Vector2::Vector2()
{
	x = 0; y = 0;
}

Vector2::Vector2(double X, double Y)
{
	x = X; y = Y;
}

Vector2 Vector2::operator+(Vector2 V)
{
	return Vector2(x + V.x, y + V.y);
}

Vector2 Vector2::operator+=(Vector2 V)
{
	x = x + V.x; y = y + V.y;
	return Vector2(*this);
}

Vector2 Vector2::operator-(Vector2 V)
{
	return Vector2(x - V.x, y - V.y);
}

Vector2 Vector2::operator-=(Vector2 V)
{
	x = x - V.x; y = y - V.y;
	return Vector2(*this);
}

Vector2 Vector2::operator*=(double V)
{
	x = x * V; y = y * V;
	return Vector2(*this);
}

Vector2 Vector2::operator/(double V)
{
	return Vector2(x / V, y / V);
}

Vector2 Vector2::operator/=(double V)
{
	x = x / V; y = y / V;
	return Vector2(*this);
}

Vector2 Vector2::operator-()
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator*(double V)
{
	return Vector2(x * V, y * V);
}

Vector2 operator*(double V, Vector2 vec)
{
	return Vector2(vec.x * V, vec.y * V);
}

double Module(Vector2 v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

double Module2(Vector2 v)
{
	return v.x * v.x + v.y * v.y;
}
