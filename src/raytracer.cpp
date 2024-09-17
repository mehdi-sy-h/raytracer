#include "color.hpp"
#include "ray.hpp"
#include "vec3.hpp"

#include <iostream>

double hit_sphere(const Vec3& center, double radius, const Ray& r) {
	const Vec3 oc = center - r.origin; 
	auto a = dot(r.dir, r.dir);
	auto b = -2.0 * dot(r.dir, oc);
	auto c = dot(oc, oc) - radius*radius;
	auto discriminant = b*b - 4*a*c;

	if (discriminant < 0) {
		return -1.0;
	} else {
		return (-b - std::sqrt(discriminant)) / (2.0 * a);
	}
}

Color ray_color(const Ray& r) {
	const auto t = hit_sphere(Vec3(0, 0, -1), 0.5, r);
	if (t > 0.0) {
		Vec3 N = unit(r.interp(t) - Vec3(0, 0, -1));
		return 0.5 * Color(N.x() + 1, N.y() + 1, N.z() + 1);
	}

    Vec3 unit_direction = unit(r.dir);
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*Color(1.0, 1.0, 1.0) + a*Color(0.5, 0.7, 1.0);
}

int main() {
	// Image
	const double aspect_ratio = 16.0/9.0;
	const int image_width = 400;

	int image_height = int(image_width/aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	// Camera
	const double focal_length = 1.0;
	const double viewport_height = 2.0;
	const double viewport_width = viewport_height * ((double)image_width/(double)image_height);
	const auto camera_pos = Vec3();

	const auto viewport_u = Vec3(viewport_width, 0, 0);
	const auto viewport_v = Vec3(0, -viewport_height, 0);

	const auto pixel_delta_u = (1.0/image_width) * viewport_u;
	const auto pixel_delta_v = (1.0/image_height) * viewport_v;

	const auto viewport_origin = camera_pos
		- Vec3(0, 0, focal_length) - 0.5 * viewport_u - 0.5 * viewport_v;
	const auto origin_pixel = viewport_origin + 0.5 * (pixel_delta_u + pixel_delta_v);

	// Render
	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
			auto pixel_center = origin_pixel + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_pos;
            Ray r(camera_pos, ray_direction);

            Color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";
}