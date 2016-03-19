
#include <exception>
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
  auto new_position = position_ + direction_unit_vector(direction_);
  if (!grid_->contains(new_position))
  {
    throw std::runtime_error("Tried to move out of bounds");
  }

  if (grid_->fruit_at(new_position))
  {
    grid_->remove_fruit(new_position);
    grow_body();
  }
  else
  {
    move_body();
  }

  if (body_occupies(new_position))
  {
    throw std::runtime_error("Tried to move into own body");
  }

  position_ = new_position;
  last_moved_direction_ = direction_;
}

void Snake::grow_body()
{
  ++length_;

  body_locations_.push_front(position_);
}

void Snake::move_body()
{
  body_locations_.push_front(position());
  body_locations_.pop_back();
}
