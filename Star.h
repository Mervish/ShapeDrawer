#pragma once
#include "Shape.h"

class Star : public Shape
{
public:
	Star(GLfloat radius, unsigned int count) :Shape(GL_TRIANGLE_FAN),
		_radius(radius), _ends(count) {	}

private:
	float _radius;
	unsigned int _ends;
	void updateDrawData();
};