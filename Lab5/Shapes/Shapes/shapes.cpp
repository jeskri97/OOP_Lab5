
#include <iostream>

#include "shapes.h"

Shape::Shape(Point2D pos, int color[4]) {
	this->pos = pos;
	for (int i = 0; i < 4; i++) {
		if (color[i] < 0 || color[i] > 255) {
			printf("\nERROR: Invalid color value, setting color value of ");
			switch (i)
			{
			case 0:
				printf("Red to 0\n");
				this->color[i] = 0;
				break;
			case 1:
				printf("Green to 0\n");
				this->color[i] = 0;
				break;
			case 2:
				printf("Blue to 0\n");
				this->color[i] = 0;
				break;
			case 3:
				printf("Alpha to 0\n");
				this->color[i] = 0;
				break;
			default:
				break;
			}
		}
		else
			this->color[i] = color[i];
	}
}
Point2D Shape::getPos() {
	return this->pos;
}

Rectangle::Rectangle(Point2D pos, int color[4], float width, float height)
	: Shape(pos, color) {
	this->width = width;
	this->height = height;
}
void Rectangle::render() {
	std::string sPos = this->getPos().toString();
	printf("\nRectangle\nPos:\t%s\nWidth / Height:\t%g / %g\n", sPos.c_str(), this->width, this->height);
}

Triangle::Triangle(Point2D pos, int color[4], float base, float height)
	: Shape(pos, color) {
	this->base = base;
	this->height = height;
}
void Triangle::render() {
	std::string sPos = this->getPos().toString();
	printf("\nTriangle\nPos:\t%s\nBase / Height:\t%g / %g\n", sPos.c_str(), this->base, this->height);
}

Circle::Circle(Point2D pos, int color[4], float radius)
	: Shape(pos, color) {
	this->radius = radius;
}
void Circle::render() {
	std::string sPos = this->getPos().toString();
	printf("\nTriangle\nPos:\t%s\nRadius:\t%g\n", sPos.c_str(), this->radius);
}