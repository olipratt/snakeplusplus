#include <cassert>

#include <random>
#include <algorithm>

#include <location_source.hpp>

Point2D<int> LocationSource::new_random_location()
{
  std::uniform_int_distribution<int> distribution_width(0, width_ - 1);
  std::uniform_int_distribution<int> distribution_height(0, height_ - 1);

  return Point2D<int> {distribution_width(generator),
                       distribution_height(generator)};
}

Point2D<int> LocationSource::generate_new_location()
{
  return new_random_location();
}

Point2D<int> LocationSource::next_location()
{
  if (no_available_locations())
  {
    throw no_available_locations_error("All locations unavailable");
  }

  auto point = generate_new_location();

  while (location_unavailable(point))
  {
    point = generate_new_location();
  }

  return point;
}

bool LocationSource::location_unavailable(const Point2D<int> &location) const
{
  return std::find(unavailable_locations_.begin(),
                   unavailable_locations_.end(),
                   location) != unavailable_locations_.end();
}

void LocationSource::take(Point2D<int> new_location)
{
  assert(!location_unavailable(new_location));
  unavailable_locations_.push_back(new_location);
}

void LocationSource::give_back(Point2D<int> point)
{
  auto locations_entry = std::find(unavailable_locations_.begin(),
                                   unavailable_locations_.end(),
                                   point);
  assert(locations_entry != unavailable_locations_.end());
  unavailable_locations_.erase(locations_entry);
}

void TestLocationSource::add_location(Point2D<int> new_location)
{
  locations_.push(new_location);
}

Point2D<int> TestLocationSource::generate_new_location()
{
  if (locations_.empty())
  {
    return LocationSource::generate_new_location();
  }
  else
  {
    auto new_location = locations_.front();
    locations_.pop();
    return new_location;
  }
}
