
#include "shapes.h"
#include <iostream>
#include <vector>
#include <ctime>

void testRendering(SDL_Renderer* renderer, std::vector<Shape*> vec) {
	for (int i = 0; i < vec.size(); i++) {
		vec[i]->render(renderer);
	}
}

int main(int argc, char* argv[]) {
	std::vector<Shape*> shapes; 
	srand((unsigned)time(0));

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Lab5: Task 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderClear(renderer);

	int color[4];
	color[0] = (rand() % 256);
	color[1] = (rand() % 256);
	color[2] = (rand() % 256);
	color[3] = (rand() % 256);
	Rectangle rec(Point2D(300, 150), color, 150, 150);
	shapes.push_back(&rec);

	color[0] = (rand() % 256);
	color[1] = (rand() % 256);
	color[2] = (rand() % 256);
	color[3] = (rand() % 256);
	Triangle tri(Point2D(300, 150), color, 150, 150);
	shapes.push_back(&tri);

	color[0] = (rand() % 256);
	color[1] = (rand() % 256);
	color[2] = (rand() % 256);
	color[3] = (rand() % 256);
	Circle cir(Point2D(300, 150), color, 75);
	shapes.push_back(&cir);

	testRendering(renderer, shapes);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);

	return 0;
}

//// Part 1
//int main(int argc, char* argv[]) {
//	SDL_Init(SDL_INIT_EVERYTHING);
//	SDL_Window* window = SDL_CreateWindow("Lab5: Task 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
//
//	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//
//	SDL_RenderClear(renderer);
//
//	int color[4];
//	color[0] = 45;
//	color[1] = 255;
//	color[2] = 105;
//	color[3] = 255;
//
//	Rectangle rec(Point2D(300, 150), color, 150, 150);
//	rec.render(renderer);
//	Triangle tri(Point2D(300, 150), color, 150, 150);
//	tri.render(renderer);
//	Circle cir(Point2D(300, 150), color, 75);
//	cir.render(renderer);
//
//	SDL_RenderPresent(renderer);
//
//	SDL_Delay(3000);
//
//	return 0;
//}