#include <cassert>

#include <random>
#include <algorithm>

#include <location_source.hpp>

Point2D<int> LocationSource::new_random_location() const
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution_width(0, width_);
  std::uniform_int_distribution<int> distribution_height(0, height_);
  Point2D<int> point{0, 0};

  do
  {
    point = Point2D<int> {distribution_width(generator),
                          distribution_height(generator)};
  }
  while(location_unavailable(point));

  return point;
}

Point2D<int> LocationSource::next_location()
{
  if (locations_.empty())
  {
    return new_random_location();
  }
  else
  {
    auto new_location = locations_.front();
    locations_.pop();
    return new_location;
  }
}

void LocationSource::add_location(Point2D<int> new_location)
{
  locations_.push(new_location);
}

bool LocationSource::location_unavailable(const Point2D<int> &location) const
{
  return std::find(unavailable_locations_.begin(),
                   unavailable_locations_.end(),
                   location) != unavailable_locations_.end();
}

void LocationSource::give_back(Point2D<int> point)
{
  auto locations_entry = std::find(unavailable_locations_.begin(),
                                   unavailable_locations_.end(),
                                   point);
  assert(locations_entry != unavailable_locations_.end());
  unavailable_locations_.erase(locations_entry);
}
