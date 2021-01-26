#pragma once

#include <iostream>
#include "point2D.h"

class Shape {
private:
	// The shapes position
	Point2D pos;
	// Red, Green, Blue, Alpha
	int color[4];
public:
	Shape(Point2D pos, int color[4]);

	virtual void render() = 0;

	Point2D getPos();
};

class Rectangle : public Shape {
private:
	float width, height;
public:
	Rectangle(Point2D pos, int color[4], float width, float height);
	void render();
};

class Triangle : public Shape {
private:
	float base, height;
public:
	Triangle(Point2D pos, int color[4], float base, float height);
	void render();
};

class Circle : public Shape {
private:
	float radius;
public:
	Circle(Point2D pos, int color[4], float radius);
	void render();
};