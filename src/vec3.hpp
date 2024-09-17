#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class Vec3 {
	public:
		double v[3];

		Vec3(): v{0, 0, 0} {}
		Vec3(double x, double y, double z): v{x, y, z} {}
		
		double x() const {
			return v[0];
		}
		double y() const {
			return v[1];
		}
		double z() const {
			return v[2];
		}

		double operator[](int i) const {
			return v[i];
		}
		double& operator[](int i) {
			return v[i];
		}

		Vec3 operator-() const {
			return Vec3(-v[0], -v[1], -v[2]);
		}

		Vec3& operator+=(const Vec3& u) {
			v[0] += u.v[0];
			v[1] += u.v[1];
			v[2] += u.v[2];
			return *this;
		}

		Vec3& operator*=(double lambda) {
			v[0] *= lambda;
			v[1] *= lambda;
			v[2] *= lambda;
			return *this;
		}

		double norm() const {
			return std::sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
		}
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
    return out << v.v[0] << ' ' << v.v[1] << ' ' << v.v[2];
}

inline Vec3 operator+(const Vec3& u, const Vec3& v) {
    return Vec3(u.v[0] + v.v[0], u.v[1] + v.v[1], u.v[2] + v.v[2]);
}

inline Vec3 operator-(const Vec3& u, const Vec3& v) {
    return Vec3(u.v[0] - v.v[0], u.v[1] - v.v[1], u.v[2] - v.v[2]);
}

inline Vec3 operator*(const Vec3& u, const Vec3& v) {
    return Vec3(u.v[0] * v.v[0], u.v[1] * v.v[1], u.v[2] * v.v[2]);
}

inline Vec3 operator*(double t, const Vec3& v) {
    return Vec3(t*v.v[0], t*v.v[1], t*v.v[2]);
}

inline Vec3 operator*(const Vec3& v, double t) {
    return t * v;
}

inline double dot(const Vec3& u, const Vec3& v) {
    return u.v[0] * v.v[0]
         + u.v[1] * v.v[1]
         + u.v[2] * v.v[2];
}

inline Vec3 cross(const Vec3& u, const Vec3& v) {
    return Vec3(u.v[1] * v.v[2] - u.v[2] * v.v[1],
                u.v[2] * v.v[0] - u.v[0] * v.v[2],
                u.v[0] * v.v[1] - u.v[1] * v.v[0]);
}

inline Vec3 unit(const Vec3& v) {
    return (1.0/v.norm()) * v;
}

#endif
