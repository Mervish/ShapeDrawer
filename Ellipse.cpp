#include "Ellipse.h"

void Ellipse::updateDrawData() {
	int i;
	int num_segments = 20;
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;

	ddata.points.push_back({ _center.coordx, _center.coordy }); //GL_TRIANGLE_FAN требует установки центральной точки, от которой будут рисоваться полигоны
	for (i = 0; i <= num_segments; ++i) {
		auto theta = static_cast<float>(i) * twicePi / num_segments;
		ddata.points.push_back({
			_center.coordx + (_size.coordx * cos(theta)),
			_center.coordy + (_size.coordy * sin(theta))
			});
	}
	glEnd();
}

void Ellipse::resized() {
	num_segments = num_segments * std::max(_size.coordx, _size.coordy); //Уменьшим или увеличим количество сегментов в зависимости от радиуса 
	if (num_segments < 4)
		num_segments = 4;
}
