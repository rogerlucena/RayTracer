#include <stdexcept>

#include "rt_camera.h"

RtCamera::RtCamera() {}

RtCamera::~RtCamera() {}

RtCamera::RtCamera(const RtVector &eye, const RtVector &target,
                   const RtVector &up, double w, double h)
    : eye_(eye), target_(target), up_(up), dimensions_{w, h} {
  if (w < 0 || h < 0)
    throw std::runtime_error("Invalid dimensions.");
}

std::ostream &operator<<(std::ostream &s, const RtCamera &c) {
  s << "[" << c.eye_ << ", " << c.target_ << ", " << c.up_ << ", ["
    << c.dimensions_.w << ", " << c.dimensions_.h << "]] ";
  return s;
};