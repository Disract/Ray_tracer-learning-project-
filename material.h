#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"

class material {
public:
    virtual ~material() = default;

    virtual bool scatter(const ray& r_in,const hit_record& rec,color& atteation,ray& scattered) const {
        return false;
    }
};
class lambertian : public material {
private:
    color albedo;
public:
    explicit lambertian(const color& albedo) : albedo(albedo) {};

    bool scatter(const ray& r_in,const hit_record& rec,color& attenuation,ray& scattered) const override
    {
        auto scatter_direction = rec.normal + random_unit_vector();
        if (scatter_direction.near_zero())
            scatter_direction = rec.normal;
        scattered = ray(rec.p,scatter_direction);
        attenuation = albedo;
        return true;
    }

};
class metal : public material {
private:
    color albedo;
    double fuzz;
public:
    explicit metal(const color& albedo , double fuzz) : albedo(albedo) , fuzz(fuzz < 1 ? fuzz : 1){};
    bool scatter(const ray &r_in, const hit_record &rec, color &attenuation, ray &scattered) const override {
        vec3 reflected = reflect(r_in.direction(),rec.normal);
        reflected = unit_vector(reflected) + (fuzz * random_unit_vector()) ;
        scattered = ray(rec.p,reflected);
        attenuation = albedo;
        return true;
    }
};
class dielectric : public material {
private:
    double rri;
public:
    dielectric(double rrri) : rri(rri) {}
    bool scatter(const ray &r_in, const hit_record &rec, color &attenation, ray &scattered) const override {
        attenation = color(1.0,1.0,1.0);
        double ri = rec.front_face ? (1.0/rri) : rri;
        vec3 refracted = refract(unit_vector(r_in.direction()),rec.normal,ri);
        scattered = ray(rec.p,refracted);
        return true;
    };
};
#endif