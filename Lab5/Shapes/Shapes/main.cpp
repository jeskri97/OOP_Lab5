
#include <iostream>
#include <vector>

#include "shapes.h"

void testRendering(std::vector<Shape*> vec) {
	for (int i = 0; i < vec.size(); i++) {
		vec[i]->render();
	}
}

int main(void) {
	std::vector<Shape*> vec;
	int color[4];
	color[0] = 45;
	color[1] = 255;
	color[2] = 105;
	color[3] = 255;
	
	Rectangle rec(Point2D(4, 5.5), color, 5.556, 1.689);
	vec.push_back(&rec);
	//rec.render();
	Triangle tri(Point2D(55.2, 6.7), color, 4.44, 5.698);
	vec.push_back(&tri);
	//tri.render();
	Circle cir(Point2D(6.89, 4.2), color, 63);
	vec.push_back(&cir);
	//cir.render();
	testRendering(vec);
}