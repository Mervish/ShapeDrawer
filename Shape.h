#pragma once

#include <cmath>
#include <vector>
#include <gl/glut.h>

struct Point
{
	float coordx = 0;
	float coordy = 0;
	//Point(float x, float y) : coordx(x), coordy(y){} //Необ
	Point operator +(const Point& other)
	{
		return { coordx + other.coordx, coordy + other.coordy };
	}
	Point& operator +=(const Point& other)
	{
		this->coordx += other.coordx;
		this->coordy += other.coordy;
		return *this;
	}
};

struct GLColor
{
	GLfloat red = 1.f;
	GLfloat green = 1.f;
	GLfloat blue = 1.f;
};

struct DrawData
{
	GLenum mode;
	GLColor color;
	std::vector<Point> points;
};

class Shape
{
public:
	//Shape(Point coords, GLColor color, GLenum mode) : Shape(mode), _centr(coords)	{
		//ddata.color = color;
	//}
	Shape(GLenum mode)	{
		ddata.mode = mode;
	}
	virtual ~Shape(){}

	const DrawData& getDrawData() {
		if (!updated) {
			updateDrawData();
			updated = true;
		}
		return ddata; 
	}
	//Изменения не требующие апдейта
	void setColor(GLColor color) { ddata.color = color; }
	//Изменения требующие апдейта
	void setСenter(Point center) { 
		_center = center; 
		requireUpdate();
	}
	void move(Point increment){
		_center += increment;
		requireUpdate();
	}

protected:
	Point _center;
	DrawData ddata;
	void requireUpdate() {
		ddata.points.clear();
		updated = false;
	}

private:
	bool updated = false;
	virtual void updateDrawData() = 0;
};

class ShapeSizeable : public Shape
{
public:
	ShapeSizeable(GLenum mode, Point size) : Shape(mode), _size(size) {};
	void setSize(Point newSize) {
		_size = newSize; 
		requireUpdate();
		resized();
	};

protected:
	Point _size;

private:
	virtual void resized() {}; //На случай если нам нужно сделать что-то в случае смены размера
};
