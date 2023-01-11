#pragma once

struct Vector2 final
{
	int x {0}; 
	int y{ 0 };

	Vector2& operator=(const Vector2& rhs);				 
	Vector2 operator+(const Vector2& rhs) const noexcept;		 
	Vector2 operator-(const Vector2& rhs) const noexcept;
	Vector2 operator*(const Vector2& rhs) const noexcept;
	Vector2 operator/(const Vector2& rhs) const noexcept;
	Vector2 operator*(const int rhs) const noexcept;
	Vector2 operator/(const int rhs) const noexcept;
	bool operator==(const Vector2& rhs) const noexcept;

};