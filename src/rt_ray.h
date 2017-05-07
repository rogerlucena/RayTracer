#pragma once
#ifndef RT_RAY_H
#define RT_RAY_H

#include <iostream>
#include "rt_vector.h"

class RtRay
{
public:
  RtRay(double, double, double, RtVector &);
  RtRay();
  ~RtRay();
  void print();
  friend std::ostream &operator<<(std::ostream &, const RtRay &);

private:
  struct point_struct { double x, y, z;} point_;
  RtVector direction_;
};

#endif /* RT_RAY_H */