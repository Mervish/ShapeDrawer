#pragma once

#include <cmath>
#include <vector>
#include <gl/glut.h>

struct Point
{
	float coordx = 0;
	float coordy = 0;
	//Point(float x, float y) : coordx(x), coordy(y){} //„N„u„€„q
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
	//„I„x„}„u„~„u„~„y„‘ „~„u „„„‚„u„q„…„„‹„y„u „p„„t„u„z„„„p
	void setColor(GLColor color) { ddata.color = color; }
	//„I„x„}„u„~„u„~„y„‘ „„„‚„u„q„…„„‹„y„u „p„„t„u„z„„„p
	void set„Renter(Point center) { 
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

private:
	void requireUpdate() {
		ddata.points.clear();
		updated = false;
	}
	bool updated = false;
	virtual void updateDrawData() = 0;
};

class ShapeSizeable : public Shape
{
public:
	ShapeSizeable(GLenum mode, Point size) : Shape(mode), _size(size) {};
	void setSize(Point newSize) {
		_size = newSize; 
		resized();
	};

protected:
	Point _size;

private:
	virtual void resized() {}; //„N„p „ƒ„|„…„‰„p„z „u„ƒ„|„y „~„p„} „~„…„w„~„€ „ƒ„t„u„|„p„„„ „‰„„„€-„„„€ „r „ƒ„|„…„‰„p„u „ƒ„}„u„~„ „‚„p„x„}„u„‚„p
};
