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
	Rectangle(GLfloat width) :Rectangle({width, width}) {} //Квадрат - это просто равноширенной прямоугольник
	Rectangle(Point size):ShapeSizeable(GL_QUADS, size) {}

private:
	void updateDrawData()
	{
		auto halfWidth = _size.coordx / 2;
		auto halfHeight = _size.coordy / 2;

		//Обычно в графических фреймворках у прямоугольников задается левый верхний угол как начальная точка. 
		//Но в нашем примере мы будем вычислять координаты от центра.
		ddata.points.push_back({_center.coordx - halfWidth, _center.coordy + halfHeight});
		ddata.points.push_back({_center.coordx + halfWidth, _center.coordy + halfHeight});
		ddata.points.push_back({_center.coordx + halfWidth, _center.coordy - halfHeight});
		ddata.points.push_back({_center.coordx - halfWidth, _center.coordy - halfHeight});
	}
};