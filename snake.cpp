#include <stdexcept>

#include <snake.hpp>


Point2D<int> direction_unit_vector(Direction dir)
{
  switch (dir)
  {
    case Direction::up:
      return Point2D<int>(0, -1);
    case Direction::right:
      return Point2D<int>(1, 0);
    case Direction::down:
      return Point2D<int>(0, 1);
    case Direction::left:
      return Point2D<int>(-1, 0);
  }

  throw std::logic_error("Invalid direction");
}

void Snake::face(Direction dir)
{
  direction_ = dir;
}

void Snake::move()
{
  position_ = position_ + direction_unit_vector(direction_);
}
