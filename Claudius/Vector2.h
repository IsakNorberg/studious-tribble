#pragma once

struct Vector2
{
	float x {0}; 
	float y {0};

	Vector2& operator=(const Vector2& rhs);				 
	Vector2 operator+(const Vector2& rhs) const;		 
	Vector2 operator-(const Vector2& rhs) const;		 
	Vector2 operator*(const Vector2& rhs) const;	
	Vector2 operator/(const Vector2& rhs) const;
	Vector2 operator*(const float rhs) const;			 
	Vector2 operator/(const float rhs) const;		
	bool operator==(const Vector2& rhs) const;

};