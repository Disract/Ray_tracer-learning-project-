
#include "helper.h"
#include "hittable.h"
#include "helper.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include  "material.h"
#include  <chrono>

int main()
{

	hittable_list world;
	auto material_ground = make_shared<lambertian>(color(0.6,0.6,0.6));
	auto material_center = make_shared<lambertian>(color(0.1,0.3,0.5));
	auto material_behind_center = make_shared<dielectric>(1.50);
	auto material_left = make_shared<metal>(color(0.8,0.8,0.8),0.1);
	auto material_right = make_shared<metal>(color(0.4,0.4,0.4),0.3);

	auto material_mine = make_shared<metal>(color(0.1,0.3,0.5),0.6);


	world.add(make_shared<sphere>(point3(1, -100.5, -1), 100,material_ground));
	world.add(make_shared<sphere>(point3(0, 0, -2.0), 0.5,material_behind_center));
	world.add(make_shared<sphere>(point3(-3.0, 0, -4.0), 0.5,material_left));
	world.add(make_shared<sphere>(point3(3.0, 0, -4.0), 0.5,material_right));

	world.add(make_shared<sphere>(point3(0,0,-4.0),0.5,material_center));

	world.add(make_shared<sphere>(point3(0, 1, -3.0), 0.2,material_mine));
	world.add(make_shared<sphere>(point3(0, 0.5, -3.0), 0.2,material_mine));


	camera cam;
	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 1440;
	cam.samples_per_pixel = 100;
	cam.max_depth = 75;
	cam.render(world);

}

