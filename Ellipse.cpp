#include "Ellipse.h"

inline void Ellipse::updateDrawData() {
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

inline void Ellipse::resized() {
	num_segments = num_segments * std::max(_size.coordx, _size.coordy); //�T�}�u�~�����y�} �y�|�y ���r�u�|�y���y�} �{���|�y���u�����r�� ���u�s�}�u�~�����r �r �x�p�r�y���y�}�������y ���� ���p�t�y�����p 
	if (num_segments < 4)
		num_segments = 4;
}
