#pragma once
#include "Shape.h"
#include <corecrt_math_defines.h>

class Ellipse : public ShapeSizeable
{
public:
	Ellipse(GLfloat radius) : Ellipse({ radius, radius }) {} //„K„‚„…„s - „„„„€ „„‚„€„ƒ„„„€ „‚„p„r„~„€„Š„y„‚„u„~„~„€„z „„|„|„y„„ƒ
	Ellipse(Point size) : ShapeSizeable(GL_TRIANGLE_FAN, size) {
		resized();
	}
	void setRadius(GLfloat radius) {
		setSize({ radius, radius });
	};

private:
	int num_segments = 20;
	void updateDrawData();

protected:
	void resized();
};
