#ifndef  HELPER_H
#define  HELPER_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include "interval.h"
using std::make_shared;
using std::shared_ptr;

const double infinty = std::numeric_limits<double>::infinity();
const double pi = 3.141592653589793285;

inline double degreed_to_radians(double degrees)
{
	return degrees * pi / 180.0;
}
inline double random_double()
{
	return std::rand() / (RAND_MAX + 1.0);
}
inline double random_double(double min, double max)
{
	return min + (max - min) * random_double();
}
#include "color.h"
#include "ray.h"
#include "vec3.h"




#endif // ! HELPER_H
