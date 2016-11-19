#include "Point.h"

namespace pEng 
{
	Point::Point() {
		this->x = 0.0f;
		this->y = 0.0f;
	}

	Point::Point(const float x, const float y) {
		this->x = x;
		this->y = y;
	}

	Point::Point(const Point &p) {
		this->x = p.x;
		this->y = p.y;
	}

	 void Point::set(const float x, const float y) {
		this->x = x;
		this->y = y;
	 }

	 void Point::translate(const float x, const float y) {
		this->x += x;
		this->y += y;
	 }

	 Point operator* (Point p1, Point p2) {
		 return Point(p1.x * p2.x, p1.y * p2.y);
	 }
		
	Point operator/ (Point p1, Point p2) {
		return Point(p1.x / p2.x, p1.y / p2.y);
	}

	Point operator+ (sf::Vector2f v, Point p) {
		return p + v;
	}

	Point operator+ (Point p, sf::Vector2f v) {
		return Point(p.x + v.x, p.y + v.y);
	}

	Point operator+ (Point p1, Point p2) {
		return Point(p1.x + p2.x, p1.y + p2.y);
	}

	float pointDistance(const Point p1, const Point p2) {
		return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	}

	float length(const Point p1) {
		return pointDistance(p1, Point(0, 0));
	}

	float angle(Point p1, Point p2) {
		return toDegrees(atan2(p2.y - p1.y, p2.x - p1.x));
	}

	float angle(Point p1) {
		return angle(p1, Point(0, 0));
	}
}