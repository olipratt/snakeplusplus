#ifndef GRIDHPPINCLUDED
#define GRIDHPPINCLUDED

#include <cassert>

#include <exception>
#include <stdexcept>

#include <algorithm>
#include <vector>

#include <point2d.hpp>


class Grid
{
public:
  Grid(int width, int height) : width_{width}, height_{height} {}

  bool contains(const Point2D<int> &point) const {
    return ((point.x() < width_) && (point.x() >= 0) &&
            (point.y() < height_) && (point.y() >= 0));
  }

  void place_fruit(const Point2D<int> point) {
    assert(!fruit_at(point));
    fruit_locations_.push_back(point);
  }

  void remove_fruit(const Point2D<int> &point) {
    assert(fruit_at(point));
    fruit_locations_.erase(std::find(fruit_locations_.begin(),
                                     fruit_locations_.end(),
                                     point));
  }

  bool fruit_at(const Point2D<int> &point) const {
    return std::find(fruit_locations_.begin(),
                     fruit_locations_.end(),
                     point) != fruit_locations_.end();
  }

private:
  int width_;
  int height_;
  std::vector<Point2D<int> > fruit_locations_;
};

#endif