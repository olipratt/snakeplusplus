#ifndef SNAKEHPPINCLUDED
#define SNAKEHPPINCLUDED

#include <algorithm>
#include <list>

#include <point2d.hpp>
#include <location_source.hpp>
#include <grid.hpp>

enum class Direction { up, down, left, right };

Point2D<int> direction_unit_vector(Direction);
Direction direction_opposite(Direction);

//class Screen;

class Snake {
private:
  Grid *grid_;
  Point2D<int> position_;
  Direction direction_;
  Direction last_moved_direction_;
  int length_{1};
  std::list<Point2D<int> > body_locations_;

  void grow_body();
  void move_body();
  bool body_occupies(const Point2D<int> &pos) const{
    return (std::find(body_locations_.begin(),
                      body_locations_.end(),
                      pos) != body_locations_.end());
  }

public:
  Snake(Grid *grid, const Point2D<int> &pos, Direction dir) :
    grid_{grid}, position_{pos}, direction_{dir}, last_moved_direction_{dir} {}

  Point2D<int> position() const { return position_; }
  int length() const { return length_; }
  int occupies(const Point2D<int> &pos) const {
    return ((pos == position()) || body_occupies(pos));
  }

  void move();
  void face(Direction dir);

  //void draw(Screen *screen);
};

#endif