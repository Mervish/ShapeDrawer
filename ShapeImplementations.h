#pragma once
#include <array>
#include <corecrt_math_defines.h>
#include "Shape.h"


class Ellipse : public ShapeSizeable
{
public:
	Ellipse(GLfloat radius) : Ellipse({ radius, radius }) {} //�K�����s - ������ ������������ ���p�r�~�����y���u�~�~���z ���|�|�y����
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

		ddata.points.push_back({ _center.coordx, _center.coordy }); //GL_TRIANGLE_FAN �����u�q���u�� �������p�~���r�{�y ���u�~�����p�|���~���z �������{�y, ���� �{�����������z �q���t���� ���y�����r�p�������� �����|�y�s���~��
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
		num_segments = num_segments * std::max(_size.coordx, _size.coordy); //�T�}�u�~�����y�} �y�|�y ���r�u�|�y���y�} �{���|�y���u�����r�� ���u�s�}�u�~�����r �r �x�p�r�y���y�}�������y ���� ���p�t�y�����p 
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
		//�I�������|���x���u�� ������-�w�u �p�|�s�����y���} ������ �y �{�����s, 
		ddata.points.push_back({ _center.coordx, _center.coordy }); //GL_TRIANGLE_FAN �����u�q���u�� �������p�~���r�{�y ���u�~�����p�|���~���z �������{�y, ���� �{�����������z �q���t���� ���y�����r�p�������� �����|�y�s���~��
		auto iterations = _ends * 2;
//		for (int ii = 0; ii <= iterations; ii++) //�N�p ���t�~�� �y���u���p���y�� �q���|�����u, �������q�� ���y�s�����p �x�p���y�{�|�y�|�p����
		for (unsigned int ii = 0; ii <= iterations; ++ii) //�N�p ���t�~�� �y���u���p���y�� �q���|�����u, �������q�� ���y�s�����p �x�p���y�{�|�y�|�p����
		{
			float rad = _radius;
			if(ii % 2)
				rad *= 0.5;
			float theta = 2.0f * 3.1415926f * float(ii) / float(iterations);
			float x = rad * std::cosf(theta);
			float y = rad * std::sinf(theta);
			ddata.points.push_back({ _center.coordx + x, _center.coordy + y }); //�S�����{�y �������}�y���������y�u ���{�����w�~��������
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
	Rectangle(GLfloat width) :Rectangle({width, width}) {} //�K�r�p�t���p�� - ������ ������������ ���p�r�~�����y���u�~�~���z �������}�����s���|���~�y�{
	Rectangle(Point size):ShapeSizeable(GL_QUADS, size) {}

private:
	void updateDrawData()
	{
		auto halfWidth = _size.coordx / 2;
		auto halfHeight = _size.coordy / 2;

		//�O�q�����~�� �r �s���p���y���u���{�y�� �����u�z�}�r�����{�p�� �� �������}�����s���|���~�y�{���r �x�p�t�p�u������ �|�u�r���z �r�u�����~�y�z ���s���| �{�p�{ �~�p���p�|���~�p�� �������{�p. 
		//�N�� �r �~�p���u�} �����y�}�u���u �}�� �q���t�u�} �r�����y���|������ �{�������t�y�~�p���� ���� ���u�~�����p.
		ddata.points.push_back({_center.coordx - halfWidth, _center.coordy + halfHeight});
		ddata.points.push_back({_center.coordx + halfWidth, _center.coordy + halfHeight});
		ddata.points.push_back({_center.coordx + halfWidth, _center.coordy - halfHeight});
		ddata.points.push_back({_center.coordx - halfWidth, _center.coordy - halfHeight});
	}
};