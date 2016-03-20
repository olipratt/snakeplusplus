#ifndef LOCATIONSOURCEHPPINCLUDED
#define LOCATIONSOURCEHPPINCLUDED

#include <exception>
#include <stdexcept>

#include <queue>
#include <list>

#include <point2d.hpp>


class LocationSource
{
public:
  LocationSource(int width, int height) :
    width_{width}, height_{height}, locations_{}, unavailable_locations_{} {}

  bool contains(const Point2D<int> &point) const {
    return ((point.x() < width_) && (point.x() >= 0) &&
            (point.y() < height_) && (point.y() >= 0));
  }

  Point2D<int> next_location();
  void add_location(Point2D<int>);

  void take(Point2D<int> point) { unavailable_locations_.push_back(point); };
  void give_back(Point2D<int>);

private:
  int width_;
  int height_;
  std::queue<Point2D<int>> locations_;
  std::list<Point2D<int>> unavailable_locations_;

  Point2D<int> new_random_location() const;
  bool location_unavailable(const Point2D<int>&) const;
};

#endif