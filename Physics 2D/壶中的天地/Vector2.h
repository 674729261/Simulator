#pragma once
#include <cmath>
class Vector2  //平面向量类
{
public:
	double x, y;

	Vector2();
	Vector2(double X, double Y);

	Vector2 operator+(Vector2 V);
	Vector2 operator+=(Vector2 V);

	Vector2 operator-(Vector2 V);
	Vector2 operator-=(Vector2 V);

	Vector2 operator*(double V);
	Vector2 operator*=(double V);

	Vector2 operator/(double V);
	Vector2 operator/=(double V);

	Vector2 operator-();
};

Vector2 operator*(double V, Vector2 vec);
double Module(Vector2 v);
double Module2(Vector2 v);