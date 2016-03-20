#ifndef LOCATIONSOURCEHPPINCLUDED
#define LOCATIONSOURCEHPPINCLUDED

#include <exception>
#include <stdexcept>

#include <random>
#include <algorithm>

#include <queue>
#include <list>

#include <point2d.hpp>

class no_available_locations_error : public std::runtime_error
{
public:
  no_available_locations_error(): runtime_error("No available locations") {}
};

class LocationSource
{
public:
  LocationSource(unsigned int width, unsigned int height) :
    width_{width}, height_{height}, locations_{}, unavailable_locations_{} {}

  bool contains(const Point2D<int> &point) const {
    return ((point.x() >= 0) &&
            (static_cast<unsigned int>(point.x()) < width_) &&
            (point.y() >= 0) &&
            (static_cast<unsigned int>(point.y()) < height_));
  }

  Point2D<int> next_location();
  void add_location(Point2D<int>);

  void take(Point2D<int> point) { unavailable_locations_.push_back(point); };
  void give_back(Point2D<int>);

private:
  unsigned int width_;
  unsigned int height_;
  std::queue<Point2D<int>> locations_;
  std::list<Point2D<int>> unavailable_locations_;
  std::default_random_engine generator;

  Point2D<int> new_random_location();
  bool location_unavailable(const Point2D<int>&) const;
  Point2D<int> generate_new_location();
};

#endif