#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"

class Ray {
	public:
		const Vec3 origin;
		const Vec3 dir;

		Ray() {}
		Ray(const Vec3& origin, const Vec3& dir) : origin(origin), dir(unit(dir)) {} 

		Vec3 interp(double lambda) const {
			return origin + lambda * dir;
		}
};

#endif
