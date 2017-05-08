#pragma once
#ifndef RT_RAY_H
#define RT_RAY_H

#include <iostream>

#include "rt_vector.h"

class RtRay
{
public:
  RtRay();
  ~RtRay();
  RtRay(RtVector, RtVector);
  friend std::ostream &operator<<(std::ostream &, const RtRay &);
  RtVector getDirection();
  RtVector getPoint();

private:
  RtVector point_;
  RtVector direction_;
};

#endif /* RT_RAY_H */