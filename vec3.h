#ifndef VEC3_H
#define VEC3_H
#include "helper.h"
class vec3
{
public:
	double v[3];
	vec3() : v{ 0,0,0 } {}
	vec3(double v0, double v1, double v2) : v{ v0,v1,v2 } {}
	double x() const { return v[0]; }
	double y() const { return v[1]; }
	double z() const { return v[2]; }

	vec3 operator-() const { return vec3(-v[0], -v[1], -v[2]); }
	double operator[](int i) const { return v[i]; }
	double& operator[](int i) { return v[i]; }

	vec3& operator+=(const vec3& va)
	{
		v[0] += va.v[0];
		v[1] += va.v[1];
		v[2] += va.v[2];
		return *this;
	}

	vec3& operator*=(double k)
	{
		v[0] *= k;
		v[1] *= k;
		v[2] *= k;
		return *this;
	}

	vec3& operator/=(double k)
	{
		return *this *= 1 / k;
	}
	double length() const
	{
		return std::sqrt(length_squared());
	}
	double length_squared() const
	{
		return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	}
	bool near_zero() const {
		auto s = 1e-8;
		return ((std::fabs(v[0]) < s) && (std::fabs(v[1]) < s)  && (std::fabs(v[2]) < s));
	}
	static vec3 random() {
		return {random_double(), random_double(), random_double()};
	}
	static vec3 random(double const min, double const max) {
		return {random_double(min, max),random_double(min,max),random_double(min,max)};
	}
};
using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& vec)
{
	return out << vec.v[0] << ' ' << vec.v[1] << ' ' << vec[2];
}


inline vec3 operator-(const vec3& v1, const vec3 v2)
{
	return vec3(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], v1.v[2] - v2.v[2]);
}

inline vec3 operator+(const vec3& v1, const vec3 v2)
{
	return vec3(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], v1.v[2] + v2.v[2]);
}

inline vec3 operator*(const vec3& v1, const vec3 v2)
{
	return vec3(v1.v[0] * v2.v[0], v1.v[1] * v2.v[1], v1.v[2] * v2.v[2]);
}

inline vec3 operator*(double t, const vec3 vi)
{
	return vec3(vi.v[0] * t, vi.v[1] * t, vi.v[2] * t);
}
inline vec3 operator*( const vec3 vi , double t)
{
	return t * vi;
}

inline vec3 operator/(const vec3 vi, double t)
{
	return (1/t) * vi;
}

inline double dot(const vec3& v1, const vec3& v2)
{
	return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2)
{
	return{v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
				v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],
				v1.v[0] * v2.v[1] - v1.v[1] * v2.v[1]} ;
}

inline vec3 unit_vector(const vec3& v)
{
	return v / v.length();
}
inline vec3 random_unit_vector() {
	while (true) {
		auto p = vec3::random(-1,1);
		auto const p_len = p.length_squared();
		if ( 1e-160 < p_len && p_len <= 1) {
			return p/sqrt(p_len);
		}
	}
}
inline vec3 random_on_unit_sphere(const vec3& normal) {
	vec3 on_unit_sphere = random_unit_vector();
	if (dot(on_unit_sphere, normal) > 0) {
		return on_unit_sphere;
	}
	else {
		return -on_unit_sphere;
	}
}
inline vec3 reflect(const vec3& v,const vec3& n) {
	return v-2*dot(v,n)*n;
}











#endif