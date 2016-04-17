#ifndef GRIDHPPINCLUDED
#define GRIDHPPINCLUDED

#include <cassert>

#include <exception>
#include <stdexcept>

#include <algorithm>
#include <vector>

#include <point2d.hpp>

#include <renderapi.hpp>


class FruitManager
{
public:
  FruitManager(LocationSource *location_source, RendererFactory *render_fact)
    : location_source_{location_source},
      renderer_{render_fact->new_fruit_renderer()}
    {}

  /** Place a new fruit at the given location. */
  void place_fruit(const Point2D<int> point) {
    // There should not be a fruit at the new location already.
    assert(!fruit_at(point));

    // Take ownership of the location, and add it to the list of fruit
    // locations.
    location_source_->take(point);
    fruit_locations_.push_back(point);
  }

  /** Take a fruit from the given location, and place a new one elsewhere. */
  void consume_fruit(const Point2D<int> &point) {
    remove_fruit(point);

    // Place a fruit at a new location before returning the current one, to
    // ensure the new one is not placed in the same location.
    place_fruit(location_source_->next_location());
    location_source_->give_back(point);
  }

  /** Is there a fruit at the given location? */
  bool fruit_at(const Point2D<int> &point) const {
    return std::find(fruit_locations_.begin(),
                     fruit_locations_.end(),
                     point) != fruit_locations_.end();
  }

  /** Draw all the current fruit. */
  void draw(Window *window) {
    for(const Point2D<int> &point : fruit_locations_)
    {
      renderer_->draw(window,
                      point,
                      location_source_->width(),
                      location_source_->height());
    }
  }

private:
  LocationSource *location_source_;
  std::vector<Point2D<int>> fruit_locations_;
  std::unique_ptr<FruitRenderer> renderer_;

  void remove_fruit(const Point2D<int> &point) {
    assert(fruit_at(point));
    fruit_locations_.erase(std::find(fruit_locations_.begin(),
                                     fruit_locations_.end(),
                                     point));
  }
};

#endif