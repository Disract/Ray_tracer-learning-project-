cmake_minimum_required(VERSION 4.0)
project(Ray_tracer_learning_project_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ray_tracer_learning_project_
        camera.h
        color.h
        helper.h
        hittable.h
        hittable_list.h
        interval.h
        ray.h
        RT.cpp
        sphere.h
        vec3.h
        material.h)
