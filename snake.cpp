
#include <exception>
#include <stdexcept>

#include <snake.hpp>

void Snake::face(Direction dir)
{
  if (dir != direction_opposite(last_moved_direction_))
  {
    direction_ = dir;
  }
}

void Snake::move()
{
  // This is the new position the head will be in after moving.
  auto new_position = head_position() + direction_unit_vector(direction_);

  // If the snake tries to move outside the grid - that's an error.
  if (!location_source_->contains(new_position))
  {
    throw std::runtime_error("Tried to move out of bounds");
  }

  // If the snake moves on to a fruit, it eats the fruit and its body grows.
  // Otherwise, its body just moves forward.
  if (fruit_manager_->fruit_at(new_position))
  {
    fruit_manager_->consume_fruit(new_position);
    grow_body();
  }
  else
  {
    move_body();
  }

  // Now the body is in its new position, if the head would move into it, then
  // that's an error.
  if (body_occupies(new_position))
  {
    throw std::runtime_error("Tried to move into own body");
  }

  // Everything succeeded, move the head and update the last direction the
  // snake moved in.
  location_source_->take(new_position);
  head_position_ = new_position;
  last_moved_direction_ = direction_;
}

void Snake::grow_body()
{
  // Grow the body by adding another body part on the same location as the head
  // which has not yet moved forward.
  body_locations_.push_front(head_position());
}

void Snake::move_body()
{
  body_locations_.push_front(head_position());
  location_source_->give_back(body_locations_.back());
  body_locations_.pop_back();
}
