#include "Star.h"

void Star::updateDrawData() {
	//Использует тот-же алгоритм что и круг, 
	ddata.points.push_back({ _center.coordx, _center.coordy }); //GL_TRIANGLE_FAN требует установки центральной точки, от которой будут рисоваться полигоны
	auto iterations = _ends * 2;
	for (unsigned int ii = 0; ii <= iterations; ++ii) //На одну итерацию больше, чтобы фигура зациклилась
	{
		float rad = _radius;
		if (ii % 2)
			rad *= 0.5;
		float theta = 2.0f * 3.1415926f * float(ii) / float(iterations);
		float x = rad * std::cosf(theta);
		float y = rad * std::sinf(theta);
		ddata.points.push_back({ _center.coordx + x, _center.coordy + y }); //Точки формирующие окружность
	}
}
