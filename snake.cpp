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

Direction direction_opposite(Direction dir)
{
  switch (dir)
  {
    case Direction::up:
      return Direction::down;
    case Direction::right:
      return Direction::left;
    case Direction::down:
      return Direction::up;
    case Direction::left:
      return Direction::right;
  }

  throw std::logic_error("Invalid direction");
}

void Snake::face(Direction dir)
{
  if (dir != direction_opposite(last_moved_direction_))
  {
    direction_ = dir;
  }
}

void Snake::move()
{
  position_ = position_ + direction_unit_vector(direction_);
  last_moved_direction_ = direction_;
}
