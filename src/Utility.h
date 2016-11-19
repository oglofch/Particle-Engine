#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <cmath>

#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>

#include "Semaphore.h"
#include "Constants.h"

int sign(int number);

float toDegrees(float radian);
float toRadians(float degree);

float angle(const sf::Vector2f p);
float angle(const sf::Vector2f p1, const sf::Vector2f p2);
float distance(const sf::Vector2f p1, const sf::Vector2f p2);
float length(const sf::Vector2f p);

sf::Vector2f makeVector(float angle, float magnitude, sf::Vector2f offset = sf::Vector2f(0, 0));

std::string toString(int num);
std::string toString(float num);
std::string toString(double num);

int min(int n1, int n2);
float min(float n1, float n2);
int max(int n1, int n2);
float max(float n1, float n2);

int round(float n);

float distance(sf::IntRect r1, sf::IntRect r2);
sf::Vector2f minimumTranslation(sf::IntRect r1, sf::IntRect r2);

int randInt(float min, float max);
float randFloat(float min, float max);
sf::Vector2f randVector2f(sf::Vector2f min, sf::Vector2f max);

sf::Vector2f operator* (sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f operator* (sf::Vector2i v1, sf::Vector2f v2);
sf::Vector2f operator* (sf::Vector2f v1, sf::Vector2i v2);
sf::Vector2f operator* (sf::Vector2i v1, sf::Vector2i v2);

sf::Vector2f operator/ (sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f operator/ (sf::Vector2i v1, sf::Vector2f v2);
sf::Vector2f operator/ (sf::Vector2f v1, sf::Vector2i v2);
sf::Vector2f operator/ (sf::Vector2i v1, sf::Vector2i v2);

sf::ConvexShape operator+ (sf::ConvexShape s, sf::Vector2f v);
sf::ConvexShape operator+ (sf::Vector2f v, sf::ConvexShape s);

#endif