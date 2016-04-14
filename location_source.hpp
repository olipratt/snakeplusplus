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
  using runtime_error::runtime_error;
};

/// A grid of point locations that can be taken ownership of either randomly or
/// exactly, and later returned to the source.
class LocationSource
{
public:
  LocationSource(unsigned int width, unsigned int height)
    : width_{width}, height_{height}, unavailable_locations_{} {}

  unsigned int width() { return width_; }
  unsigned int height() { return height_; }

  /** Is the given location one the source controls? */
  bool contains(const Point2D<int> &point) const {
    return ((point.x() >= 0) &&
            (static_cast<unsigned int>(point.x()) < width_) &&
            (point.y() >= 0) &&
            (static_cast<unsigned int>(point.y()) < height_));
  }

  /** Return the next location to use - randomly selected. */
  Point2D<int> next_location();

  /** Take exclusive ownership of a location. */
  void take(Point2D<int> point);

  /** Return ownership of a location back to the source. */
  void give_back(Point2D<int>);

private:
  unsigned int width_;
  unsigned int height_;
  std::list<Point2D<int>> unavailable_locations_;
  std::default_random_engine generator;

  Point2D<int> new_random_location();
  bool location_unavailable(const Point2D<int>&) const;
  unsigned int size() const { return width_ * height_; }
  bool no_available_locations() const {
    return unavailable_locations_.size() == size();
  }

protected:
  virtual Point2D<int> generate_new_location();
};


/// A location source that can be seeded with locations to remove randomness
/// for testing.
class TestLocationSource : public LocationSource
{
public:
  TestLocationSource(unsigned int width, unsigned int height)
    : LocationSource(width, height), locations_{} {}

  /** Queue a location to be returned later - useful in testing. */
  void add_location(Point2D<int>);

private:
  std::queue<Point2D<int>> locations_;
  Point2D<int> generate_new_location();
};

#endif