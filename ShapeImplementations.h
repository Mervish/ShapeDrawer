#pragma once
#include <array>

#include "Shape.h"

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