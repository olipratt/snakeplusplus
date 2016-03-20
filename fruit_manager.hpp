#ifndef GRIDHPPINCLUDED
#define GRIDHPPINCLUDED

#include <cassert>

#include <exception>
#include <stdexcept>

#include <algorithm>
#include <vector>

#include <point2d.hpp>


class FruitManager
{
public:
  FruitManager(int width, int height, LocationSource *location_source) :
    width_{width}, height_{height}, location_source_{location_source} {}

  void place_fruit(const Point2D<int> point) {
    assert(!fruit_at(point));
    location_source_->take(point);
    fruit_locations_.push_back(point);
  }

  void consume_fruit(const Point2D<int> &point) {
    remove_fruit(point);

    place_fruit(location_source_->next_location());
    location_source_->give_back(point);
  }

  bool fruit_at(const Point2D<int> &point) const {
    return std::find(fruit_locations_.begin(),
                     fruit_locations_.end(),
                     point) != fruit_locations_.end();
  }

private:
  int width_;
  int height_;
  LocationSource *location_source_;
  std::vector<Point2D<int> > fruit_locations_;

  void remove_fruit(const Point2D<int> &point) {
    assert(fruit_at(point));
    fruit_locations_.erase(std::find(fruit_locations_.begin(),
                                     fruit_locations_.end(),
                                     point));
  }
};

#endif