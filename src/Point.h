#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Utility.h"

namespace pEng 
{
	class Point
	{
	public:
		float x;
		float y;

		Point();
		Point(const float x, const float y);
		Point(const Point &p);

		void set(const float x, const float y);
		void translate(const float x, const float y);
	};

	Point operator* (Point p1, Point p2);
	Point operator/ (Point p1, Point p2);
	Point operator+ (Point p1, Point p2);
	Point operator+ (sf::Vector2f v, Point p);
	Point operator+ (Point p, sf::Vector2f v);
	float pointDistance(const Point p1, const Point p2);
	float length(const Point p1);
	float angle(Point p1, Point p2);
	float angle(Point p1);
}
#endif // POINT_H_INCLUDED
