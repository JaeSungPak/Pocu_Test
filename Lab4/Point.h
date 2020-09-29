#pragma once

namespace lab4
{
	class Point
	{
	public:
		Point();
		Point(float x, float y);
		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;
		Point& operator=(const Point& other);
		friend Point operator*(float operand, const Point& point);
		bool operator==(const Point& other) const;

		float GetX() const;
		float GetY() const;

	private:
		float mX;
		float mY;
	};
}