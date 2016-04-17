
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

Point2D<int> Snake::head_position_after_move() const
{
  return head_position() + direction_unit_vector(direction_);
}

void Snake::move()
{
  // If the snake tries to move outside the grid - that's an error.
  if (!location_source_->contains(head_position_after_move()))
  {
    throw std::runtime_error("Tried to move out of bounds");
  }

  // If the snake moves on to a fruit, it eats the fruit and its body grows.
  // Otherwise, its body just moves forward.
  if (fruit_manager_->fruit_at(head_position_after_move()))
  {
    fruit_manager_->consume_fruit(head_position_after_move());
    grow_body();
  }
  else
  {
    move_body();
  }

  // Now the body is in its new position, if the head would move into it, then
  // that's an error.
  if (body_occupies(head_position_after_move()))
  {
    throw std::runtime_error("Tried to move into own body");
  }

  // Everything succeeded, move the head.
  move_head();
}

void Snake::grow_body()
{
  // Grow the body by adding another body part on the same location as the head
  // which has not yet moved forward.
  body_locations_.push_front(head_position());
}

void Snake::shrink_tail()
{
  location_source_->give_back(body_locations_.back());
  body_locations_.pop_back();
}

void Snake::move_body()
{
  // Grow the body forwards, then shrink the tail end to achieve movement.
  grow_body();
  shrink_tail();
}

void Snake::move_head()
{
  head_position_ = head_position_after_move();
  location_source_->take(head_position_);
  last_moved_direction_ = direction_;
}

void Snake::draw(Window *window)
{
  renderer_->draw(window,
                  head_position_,
                  body_locations_,
                  direction_,
                  location_source_->width(),
                  location_source_->height());
}
