#include "Utility.h"

int sign(int number) {
	if (number < 0.0f) {
		return -1;
	} else {
		return 1;
	}
}

float toDegrees(float radian){
    return (float)(radian * 180 / PI);
}

float toRadians(float degree){
    return (float)(degree * PI / 180);
}

float angle(const sf::Vector2f p1, const sf::Vector2f p2) {
	return toDegrees(atan2(p2.y - p1.y, p2.x - p1.x));
}

float angle(const sf::Vector2f p) {
	return angle(p, sf::Vector2f(0, 0));
}

float distance(const sf::Vector2f p1, const sf::Vector2f p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float length(const sf::Vector2f p) {
	return distance(p, sf::Vector2f(0, 0));
}

sf::Vector2f makeVector(float angle, float magnitude, sf::Vector2f offset) {
	return sf::Vector2f(cos(toRadians(angle)) * magnitude, sin(toRadians(angle)) * magnitude) + offset;
}

std::string toString(int num) {
	std::ostringstream os;
	os << num;
	return os.str();
}

std::string toString(float num) {
	std::ostringstream os;
	os << num;
	return os.str();
}

std::string toString(double num) {
	std::ostringstream os;
	os << num;
	return os.str();
}

int min(int n1, int n2) {
	if (n1 < n2) {
		return n1;
	} else {
		return n2;
	}
}

float min(float n1, float n2) {
	if (n1 < n2) {
		return n1;
	} else {
		return n2;
	}
}

int max(int n1, int n2) {
	if (n1 > n2) {
		return n1;
	} else {
		return n2;
	}
}

float max(float n1, float n2) {
	if (n1 > n2) {
		return n1;
	} else {
		return n2;
	}
}

int round(float n) {
    return (int)floor(n + 0.5);
}

float distance(sf::IntRect r1, sf::IntRect r2) {
	float dx = max((float)r1.left, (float)r2.left) - min((float)(r1.left + r1.width), (float)(r2.left + r2.width));
	float dy = max((float)r1.top, (float)r2.top) - min((float)(r1.top + r1.height), (float)(r2.top + r2.height));
    if(dx < 0) { 
		return max((float)dy, (float)0);
	}
    if(dy < 0) {
		return dx;
	}
    return sqrt(dx * dx + dy * dy);
}

sf::Vector2f minimumTranslation(sf::IntRect r1, sf::IntRect r2) {
	sf::Vector2f amin = sf::Vector2f((float)r1.left, (float)r1.top);
	sf::Vector2f amax = sf::Vector2f((float)(r1.left + r1.width), (float)(r1.top + r1.height));
	sf::Vector2f bmin = sf::Vector2f((float)r2.left, (float)r2.top);
	sf::Vector2f bmax = sf::Vector2f((float)(r2.left + r2.width), (float)(r2.top + r2.height));
 
	sf::Vector2f mtd;
 
	float left = (bmin.x - amax.x);
	float right = (bmax.x - amin.x);
	float top = (bmin.y - amax.y);
	float bottom = (bmax.y - amin.y);
 
	// box dont intersect   
	if (left > 0 || right < 0 || top > 0 || bottom < 0) {
		return sf::Vector2f(0, 0);
	}
 
	// box intersect. work out the mtd on both x and y axes.
	if (abs(left) < right)
		mtd.x = left;
	else
		mtd.x = right;
 
	if (abs(top) < bottom)
		mtd.y = top;
	else
		mtd.y = bottom;
 
	// 0 the axis with the largest mtd value.
	if (abs(mtd.x) < abs(mtd.y))
		mtd.y = 0;
	else
		mtd.x = 0; 

	return mtd;
}

int randInt(float min, float max) {
	if (min == max) {
		return min;
	}
	return rand() % (int)(max - min) + min;
}

float randFloat(float min, float max) {
	return (float)rand() / (float)RAND_MAX * (max - min) + min;
}

sf::Vector2f randVector2f(sf::Vector2f min, sf::Vector2f max) {
	return sf::Vector2f((float)rand() / (float)RAND_MAX * (max.x - min.x) + min.x,
		(float)rand() / (float)RAND_MAX * (max.y - min.y) + min.y);
}

sf::Vector2f operator* (sf::Vector2f v1, sf::Vector2f v2) {
	return sf::Vector2f(v1.x * v2.x, v1.y * v2.y);
}

sf::Vector2f operator* (sf::Vector2i v1, sf::Vector2f v2) {
	return sf::Vector2f(v1.x * v2.x, v1.y * v2.y);
}

sf::Vector2f operator* (sf::Vector2f v1, sf::Vector2i v2) {
	return sf::Vector2f(v1.x * v2.x, v1.y * v2.y);
}

sf::Vector2f operator* (sf::Vector2i v1, sf::Vector2i v2) {
	return sf::Vector2f(v1.x * v2.x, v1.y * v2.y);
}

sf::Vector2f operator/ (sf::Vector2f v1, sf::Vector2f v2) {
	return sf::Vector2f(v1.x / v2.x, v1.y / v2.y);
}

sf::Vector2f operator/ (sf::Vector2i v1, sf::Vector2f v2) {
	return sf::Vector2f(v1.x / v2.x, v1.y / v2.y);
}

sf::Vector2f operator/ (sf::Vector2f v1, sf::Vector2i v2) {
	return sf::Vector2f(v1.x / v2.x, v1.y / v2.y);
}

sf::Vector2f operator/ (sf::Vector2i v1, sf::Vector2i v2) {
	return sf::Vector2f(v1.x / v2.x, v1.y / v2.y);
}

sf::ConvexShape operator+ (sf::ConvexShape s, sf::Vector2f v) {
	sf::ConvexShape shape;
	shape.setPointCount(s.getPointCount());

	for (int i = 0; i < s.getPointCount(); ++i) {
		shape.setPoint(i, s.getPoint(i) + v);
	}

	return shape;
}

sf::ConvexShape operator+ (sf::Vector2f v, sf::ConvexShape s) {
	return s + v;
}