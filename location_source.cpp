
#include <location_source.hpp>

Point2D<int> LocationSource::new_random_location()
{
  return Point2D<int> (0, 0);
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
