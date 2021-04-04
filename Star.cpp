#include "Star.h"

inline void Star::updateDrawData() {
	//„I„ƒ„„€„|„„x„…„u„„ „„„€„„-„w„u „p„|„s„€„‚„y„„„} „‰„„„€ „y „{„‚„…„s, 
	ddata.points.push_back({ _center.coordx, _center.coordy }); //GL_TRIANGLE_FAN „„„‚„u„q„…„u„„ „…„ƒ„„„p„~„€„r„{„y „ˆ„u„~„„„‚„p„|„„~„€„z „„„€„‰„{„y, „€„„ „{„€„„„€„‚„€„z „q„…„t„…„„ „‚„y„ƒ„€„r„p„„„„ƒ„‘ „„€„|„y„s„€„~„
	auto iterations = _ends * 2;
	for (unsigned int ii = 0; ii <= iterations; ++ii) //„N„p „€„t„~„… „y„„„u„‚„p„ˆ„y„ „q„€„|„„Š„u, „‰„„„€„q„ „†„y„s„…„‚„p „x„p„ˆ„y„{„|„y„|„p„ƒ„
	{
		float rad = _radius;
		if (ii % 2)
			rad *= 0.5;
		float theta = 2.0f * 3.1415926f * float(ii) / float(iterations);
		float x = rad * std::cosf(theta);
		float y = rad * std::sinf(theta);
		ddata.points.push_back({ _center.coordx + x, _center.coordy + y }); //„S„€„‰„{„y „†„€„‚„}„y„‚„…„„‹„y„u „€„{„‚„…„w„~„€„ƒ„„„
	}
}
