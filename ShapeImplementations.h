#pragma once
#include <array>
#include <corecrt_math_defines.h>
#include "Shape.h"


class Ellipse : public ShapeSizeable
{
public:
	Ellipse(GLfloat radius) : Ellipse({ radius, radius }) {} //„K„‚„…„s - „„„„€ „„‚„€„ƒ„„„€ „‚„p„r„~„€„Š„y„‚„u„~„~„€„z „„|„|„y„„ƒ
	Ellipse(Point size) : ShapeSizeable(GL_TRIANGLE_FAN, size)	{

	}
	void setRadius(GLfloat radius) {
		setSize({ radius, radius });
	};

private:
	int num_segments = 20;
	void updateDrawData() {
		int i;
		int num_segments = 20; 
		//GLfloat radius = 0.8f; //radius
		GLfloat twicePi = 2.0f * M_PI;

		ddata.points.push_back({ _center.coordx, _center.coordy }); //GL_TRIANGLE_FAN „„„‚„u„q„…„u„„ „…„ƒ„„„p„~„€„r„{„y „ˆ„u„~„„„‚„p„|„„~„€„z „„„€„‰„{„y, „€„„ „{„€„„„€„‚„€„z „q„…„t„…„„ „‚„y„ƒ„€„r„p„„„„ƒ„‘ „„€„|„y„s„€„~„
		for (i = 0; i <= num_segments; ++i) {
			auto theta = static_cast<float>(i) * twicePi / num_segments;
			ddata.points.push_back({
				_center.coordx + (_size.coordx * cos(theta)),
				_center.coordy + (_size.coordy * sin(theta))
				});
		}
		glEnd();
	}

protected:
	void resized() {
		num_segments = num_segments * std::max(_size.coordx, _size.coordy); //„T„}„u„~„„Š„y„} „y„|„y „…„r„u„|„y„‰„y„} „{„€„|„y„‰„u„ƒ„„„r„€ „ƒ„u„s„}„u„~„„„€„r „r „x„p„r„y„ƒ„y„}„€„ƒ„„„y „€„„ „‚„p„t„y„…„ƒ„p 
		if (num_segments < 4)
			num_segments = 4;
	}
};

class Star : public Shape
{
public:
	Star(GLfloat radius, unsigned int count) :Shape(GL_TRIANGLE_FAN),
		_radius(radius), _ends(count) {	}
	 
private:
	float _radius;
	unsigned int _ends;
	void updateDrawData(){
		//„I„ƒ„„€„|„„x„…„u„„ „„„€„„-„w„u „p„|„s„€„‚„y„„„} „‰„„„€ „y „{„‚„…„s, 
		ddata.points.push_back({ _center.coordx, _center.coordy }); //GL_TRIANGLE_FAN „„„‚„u„q„…„u„„ „…„ƒ„„„p„~„€„r„{„y „ˆ„u„~„„„‚„p„|„„~„€„z „„„€„‰„{„y, „€„„ „{„€„„„€„‚„€„z „q„…„t„…„„ „‚„y„ƒ„€„r„p„„„„ƒ„‘ „„€„|„y„s„€„~„
		auto iterations = _ends * 2;
//		for (int ii = 0; ii <= iterations; ii++) //„N„p „€„t„~„… „y„„„u„‚„p„ˆ„y„ „q„€„|„„Š„u, „‰„„„€„q„ „†„y„s„…„‚„p „x„p„ˆ„y„{„|„y„|„p„ƒ„
		for (unsigned int ii = 0; ii <= iterations; ++ii) //„N„p „€„t„~„… „y„„„u„‚„p„ˆ„y„ „q„€„|„„Š„u, „‰„„„€„q„ „†„y„s„…„‚„p „x„p„ˆ„y„{„|„y„|„p„ƒ„
		{
			float rad = _radius;
			if(ii % 2)
				rad *= 0.5;
			float theta = 2.0f * 3.1415926f * float(ii) / float(iterations);
			float x = rad * std::cosf(theta);
			float y = rad * std::sinf(theta);
			ddata.points.push_back({ _center.coordx + x, _center.coordy + y }); //„S„€„‰„{„y „†„€„‚„}„y„‚„…„„‹„y„u „€„{„‚„…„w„~„€„ƒ„„„
		}
	}
};

class Quad : public Shape
{
public:
	Quad(std::array<Point, 4> points) :Shape(GL_QUADS), _points(points){}

private:
	std::array<Point, 4> _points;

	void updateDrawData(){
		for (auto& point : _points)	{
			ddata.points.push_back(point);
		}
	}
};

class Diamond : public ShapeSizeable
{
public:
	Diamond(GLfloat width) :Diamond({ width, width }) {}
	Diamond(Point size) :ShapeSizeable(GL_QUADS, size)	{	}

private:
	void updateDrawData()
	{
		auto halfWidth = _size.coordx / 2;
		auto halfHeight = _size.coordy / 2;

		ddata.points.push_back({ _center.coordx, _center.coordy + halfHeight });
		ddata.points.push_back({ _center.coordx + halfWidth, _center.coordy});
		ddata.points.push_back({ _center.coordx, _center.coordy - halfHeight });
		ddata.points.push_back({ _center.coordx - halfWidth, _center.coordy});
	}
};

class Rectangle : public ShapeSizeable
{
public:
	Rectangle(GLfloat width) :Rectangle({width, width}) {} //„K„r„p„t„‚„p„„ - „„„„€ „„‚„€„ƒ„„„€ „‚„p„r„~„€„Š„y„‚„u„~„~„€„z „„‚„‘„}„€„…„s„€„|„„~„y„{
	Rectangle(Point size):ShapeSizeable(GL_QUADS, size) {}

private:
	void updateDrawData()
	{
		auto halfWidth = _size.coordx / 2;
		auto halfHeight = _size.coordy / 2;

		//„O„q„„‰„~„€ „r „s„‚„p„†„y„‰„u„ƒ„{„y„‡ „†„‚„u„z„}„r„€„‚„{„p„‡ „… „„‚„‘„}„€„…„s„€„|„„~„y„{„€„r „x„p„t„p„u„„„ƒ„‘ „|„u„r„„z „r„u„‚„‡„~„y„z „…„s„€„| „{„p„{ „~„p„‰„p„|„„~„p„‘ „„„€„‰„{„p. 
		//„N„€ „r „~„p„Š„u„} „„‚„y„}„u„‚„u „}„ „q„…„t„u„} „r„„‰„y„ƒ„|„‘„„„ „{„€„€„‚„t„y„~„p„„„ „€„„ „ˆ„u„~„„„‚„p.
		ddata.points.push_back({_center.coordx - halfWidth, _center.coordy + halfHeight});
		ddata.points.push_back({_center.coordx + halfWidth, _center.coordy + halfHeight});
		ddata.points.push_back({_center.coordx + halfWidth, _center.coordy - halfHeight});
		ddata.points.push_back({_center.coordx - halfWidth, _center.coordy - halfHeight});
	}
};