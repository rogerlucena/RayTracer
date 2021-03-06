#define DOUBLE_COMPARE 1.0e-6

#include <stdexcept>

#include "rt_camera.h"
#include <cmath>

RtCamera::RtCamera() {}

RtCamera::~RtCamera() {}

RtCamera::RtCamera(const RtVector &eye, const RtVector &target,
                   const RtVector &up, double w, double h)
    : eye_(eye), target_(target),
      up_((up - (((target - eye) * up) * (target - eye))).unit()), dimensions_{
                                                                       w, h} {
  if (w < 0 || h < 0)
    throw std::runtime_error("Invalid dimensions.");

  double projection = fabs((target - eye).unit() * up.unit());
  if (projection >= (1.0 - DOUBLE_COMPARE) &&
      projection <= (1.0 + DOUBLE_COMPARE))
    throw std::runtime_error("Vector up cannot define orientation.");
}

std::ostream &operator<<(std::ostream &s, const RtCamera &c) {
  s << "[" << c.eye_ << ", " << c.target_ << ", " << c.up_ << ", ["
    << c.dimensions_.w << ", " << c.dimensions_.h << "]] ";
  return s;
}

RtVector RtCamera::getTarget() const { return this->target_; }
RtVector RtCamera::getEye() const { return this->eye_; }
RtVector RtCamera::getUp() const { return this->up_; }
double RtCamera::getWidth() const { return this->dimensions_.w; }
double RtCamera::getHeight() const { return this->dimensions_.h; }