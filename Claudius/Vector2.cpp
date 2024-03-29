#include "Vector2.h"


Vector2& Vector2::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
};

Vector2 Vector2::operator+(const Vector2& rhs) const noexcept
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const noexcept
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const Vector2& rhs) const noexcept
{
	return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator/(const Vector2& rhs) const noexcept
{
	return Vector2(x / rhs.x, y / rhs.y);
}

Vector2 Vector2::operator*(const int rhs) const noexcept
{
	return Vector2(x * rhs, y * rhs);
}

Vector2 Vector2::operator/(const int rhs) const noexcept
{
	return Vector2(x / rhs, y / rhs);
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x = x + rhs.x;
	y = y + rhs.y;
	return *this;
}

bool Vector2::operator==(const Vector2& rhs) const noexcept
{
	return (this->x == rhs.x && this->y == rhs.y);
}


