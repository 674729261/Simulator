#pragma once
#include <cmath>
template<class Type>
class Vector2  //平面向量类,没什么好说的
{
public:
	Type x, y;

	Vector2();
	Vector2(Type X, Type Y);

	Vector2<Type> operator+(const Vector2<Type>& V) const;
	Vector2<Type> operator+=(const Vector2<Type>& V);

	Vector2<Type> operator-(const Vector2<Type>& V) const;
	Vector2<Type> operator-=(const Vector2<Type>& V);

	Vector2<Type> operator*(const double& V) const;
	Vector2<Type> operator*=(const double& V);

	Vector2<Type> operator/(const double& V) const;
	Vector2<Type> operator/=(const double& V);

	Vector2<Type> operator-() const;

};


const Vector2<double> Zero = Vector2<double>{ 0.0,0.0 };


/*
这里定义Vector2<Type>类的各种运算方法
*/
template<class Type>
Vector2<Type>::Vector2()
{
	x = Type(); y = Type();
}

template<class Type>
Vector2<Type>::Vector2(Type X, Type Y)
{
	x = X; y = Y;
}

template<class Type>
inline Vector2<Type> Vector2<Type>::operator+(const Vector2<Type>& V) const
{
	return Vector2<Type>(x + V.x, y + V.y);
}

template<class Type>
inline Vector2<Type> Vector2<Type>::operator+=(const Vector2<Type>& V)
{
	x = x + V.x; y = y + V.y;
	return Vector2<Type>(*this);
}

template<class Type>
inline Vector2<Type> Vector2<Type>::operator-(const Vector2<Type>& V) const
{
	return Vector2<Type>(x - V.x, y - V.y);
}

template<class Type>
inline Vector2<Type> Vector2<Type>::operator-=(const Vector2<Type>& V)
{
	x = x - V.x; y = y - V.y;
	return Vector2<Type>(*this);
}

template<class Type>
inline Vector2<Type> Vector2<Type>::operator*=(const double& V)
{
	x = x * V; y = y * V;
	return Vector2<Type>(*this);
}

template<class Type>
inline Vector2<Type> Vector2<Type>::operator/(const double& V) const
{
	return Vector2<Type>(x / V, y / V);
}

template<class Type>
inline Vector2<Type> Vector2<Type>::operator/=(const double& V)
{
	x = x / V; y = y / V;
	return Vector2<Type>(*this);
}

template<class Type>
inline Vector2<Type> Vector2<Type>::operator-() const
{
	return Vector2<Type>(-x, -y);
}

template<class Type>
inline Vector2<Type> Vector2<Type>::operator*(const double& V) const
{
	return Vector2<Type>(x * V, y * V);
}

template<class Type>
inline Vector2<Type> operator*(double V, Vector2<Type> vec)
{
	return Vector2<Type>(vec.x * V, vec.y * V);
}

inline double Module(const Vector2<double>& v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

inline double Module2(const Vector2<double>& v)
{
	return v.x * v.x + v.y * v.y;
}
