#pragma once

struct Vector2
{
	int x {0}; 
	int y{ 0 };

	Vector2& operator=(const Vector2& rhs);				 
	Vector2 operator+(const Vector2& rhs) const;		 
	Vector2 operator-(const Vector2& rhs) const;		 
	Vector2 operator*(const Vector2& rhs) const;	
	Vector2 operator/(const Vector2& rhs) const;
	Vector2 operator*(const int rhs) const;			 
	Vector2 operator/(const int rhs) const;		
	bool operator==(const Vector2& rhs) const;

};