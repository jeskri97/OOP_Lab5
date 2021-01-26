
#include <iostream>
#include <math.h>

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
int* Shape::getColor() {
	return this->color;
}

Rectangle::Rectangle(Point2D pos, int color[4], float width, float height)
	: Shape(pos, color) {
	this->width = width;
	this->height = height;
	this->halfWidth = width / 2;
	this->halfHeight = height / 2;
}
void Rectangle::render(SDL_Renderer* renderer) {
	Point2D pos = this->getPos();
	std::string sPos = pos.toString();
	int* color = this->getColor();
	printf("\nRectangle\nPos:\t%s\nWidth / Height:\t%g / %g\n", sPos.c_str(), this->width, this->height);

	// Set draw color
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	// Draw shape
	SDL_RenderDrawLine(renderer, pos.getx() + halfWidth, pos.getx() - halfHeight, pos.getx() - halfWidth, pos.getx() - halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() - halfWidth, pos.getx() - halfHeight, pos.getx() - halfWidth, pos.getx() + halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() - halfWidth, pos.getx() + halfHeight, pos.getx() + halfWidth, pos.getx() + halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() + halfWidth, pos.getx() + halfHeight, pos.getx() + halfWidth, pos.getx() - halfHeight);
}

Triangle::Triangle(Point2D pos, int color[4], float base, float height)
	: Shape(pos, color) {
	this->base = base;
	this->height = height;
	this->halfBase = base / 2;
	this->halfHeight = height / 2;
}
void Triangle::render(SDL_Renderer* renderer) {
	Point2D pos = this->getPos();
	std::string sPos = pos.toString();
	int* color = this->getColor();
	printf("\nTriangle\nPos:\t%s\nBase / Height:\t%g / %g\n", sPos.c_str(), this->base, this->height);

	// Set draw color
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	// Draw shape
	SDL_RenderDrawLine(renderer, pos.getx(), pos.getx() - halfHeight, pos.getx() - halfBase, pos.getx() + halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() - halfBase, pos.getx() + halfHeight, pos.getx() + halfBase, pos.getx() + halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() + halfBase, pos.getx() + halfHeight, pos.getx(), pos.getx() - halfHeight);
}

Circle::Circle(Point2D pos, int color[4], float radius)
	: Shape(pos, color) {
	this->radius = radius;
}
void Circle::render(SDL_Renderer* renderer) {
	Point2D pos = this->getPos();
	std::string sPos = pos.toString();
	int* color = this->getColor();
	printf("\nTriangle\nPos:\t%s\nRadius:\t%g\n", sPos.c_str(), this->radius);

	// Set draw color
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	// Draw shape
	int step = 20;
	int degree = 0;
	while (degree < 360) {
		// i = degrees
		float x1 = cos(degree * PI / 180) * this->radius * pos.getx();
		float y1 = sin(degree * PI / 180) * this->radius * pos.gety();
		degree += step;
		float x2 = cos(degree * PI / 180) * this->radius * pos.getx();
		float y2 = sin(degree * PI / 180) * this->radius * pos.gety();

		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
}