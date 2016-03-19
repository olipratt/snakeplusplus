#ifndef LOCATIONSOURCEHPPINCLUDED
#define LOCATIONSOURCEHPPINCLUDED

#include <cassert>

#include <exception>
#include <stdexcept>

#include <queue>

#include <point2d.hpp>


class LocationSource
{
public:
  Point2D<int> next_location();
  void add_location(Point2D<int>);

private:
  Point2D<int> new_random_location();

  std::queue<Point2D<int> > locations_;
};

#endif