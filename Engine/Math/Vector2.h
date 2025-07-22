#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include "Core.h"

class ENGINE_API Vector2
{
public:
	Vector2(int x = 0, int y = 0);
	~Vector2()						= default;
	
public:
	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator-(const Vector2& rhs) const;
	Vector2 operator*(const Vector2& rhs) const;
	Vector2 operator/(const Vector2& rhs) const;
	
	bool operator==(const Vector2& rhs) const;
	bool operator!=(const Vector2& rhs) const;

	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);
	Vector2& operator*=(const Vector2& rhs);
	Vector2& operator/=(const Vector2& rhs);

public:
	const char* ToString();

public:
	Vector2 Add(const Vector2& rhs) const;
	Vector2 Substract(const Vector2& rhs) const;
	Vector2 Multiply(const Vector2& rhs) const;
	Vector2 Divide(const Vector2& rhs) const;


public:
	static Vector2 Zero;
	static Vector2 One;
	static Vector2 Up;
	static Vector2 Left;
	static Vector2 Right;
	static Vector2 Down;

private:
	int _x = 0;
	int _y = 0;
};

#endif
