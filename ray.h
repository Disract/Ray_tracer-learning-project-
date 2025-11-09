#ifndef  RAY_H
#define RAY_H

#include "helper.h"
class ray
{	private:
	point3 orig;
	vec3 dir;
	public:
		ray() {}
		ray(const point3& orgin, const vec3 direction) : orig(orgin), dir(direction) {}
		const point3& orgin() const { return orig; }
		const vec3& direction() const { return dir; }

		point3 at(double t) const
		{
			return orig + t * dir;
		}

};
#endif // ! RAY_H
