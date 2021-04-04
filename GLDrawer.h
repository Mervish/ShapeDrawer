#pragma once
#include <vector>
#include <memory>

//#include <Windows.h>
//#include <GL/glut.h>

#include "Shape.h"

class GLDrawer
{
private:
	std::vector<std::unique_ptr<Shape>> _shapes;

	void drawShape(const DrawData& shapeData);

public:
	GLDrawer(int argc, char** argv);
	void drawShapes();

	void addShapeData(Shape *shape) {
		_shapes.emplace_back(shape);
	}
};

