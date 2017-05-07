#include <stdexcept>

#include "rt_sphere.h"

RtSphere::RtSphere() {}

RtSphere::~RtSphere() {}

RtSphere::RtSphere(double x, double y, double z, double rad, int r, int g, int b) : center_{x,y,z}, radius_(rad), color_{r,g,b}
{
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        throw std::runtime_error("Invalid color.");
    if (rad < 0)
        throw std::runtime_error("Negative raius.");
}

void RtSphere::print()
{
    std::cout<<"Sphere with center (" << center_.x << ", " << center_.y << ", " << center_.z << "), radius = " << radius_ << " and color [" << color_.r << ", " << color_.g << ", " << color_.b << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const RtSphere &sp){
    s << "[(" << sp.center_.x << ", " << sp.center_.y << ", " << sp.center_.z << "), " << sp.radius_ << ", [" << sp.color_.r << ", " << sp.color_.g << ", " << sp.color_.b << "]]";
    return s;
};
