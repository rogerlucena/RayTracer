#include "rt_ray.h"

RtRay::RtRay() {}

RtRay::~RtRay() {}

RtRay::RtRay(const RtVector &origin, const RtVector &direction)
    : origin_(origin), direction_(direction.unit()) {}

std::ostream &operator<<(std::ostream &s, const RtRay &r) {
  s << "[" << r.origin_ << ", " << r.direction_ << "]";
  return s;
}

RtVector RtRay::getDirection() const { return this->direction_; }

RtVector RtRay::getOrigin() const { return this->origin_; }
