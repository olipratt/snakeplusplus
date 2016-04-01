
#include <exception>
#include <stdexcept>

#include <snake_scene.hpp>


void SnakeScene::update(int elapsed_ticks)
{
  // Process events from the queue.
  process_event_queue();

  // If enough ticks have now passed, move the snake.
  ticks_since_move_ += elapsed_ticks;
  while (ticks_since_move_ >= ticks_per_move_)
  {
    ticks_since_move_ -= ticks_per_move_;
    snake_.move();
  }
}

void SnakeScene::process_event_queue()
{
  while (!event_queue_.empty())
  {
    SceneEvent event = event_queue_.front();

    switch(event)
    {
      case SceneEvent::down:
        snake_.face(Direction::down);
        break;
      case SceneEvent::up:
        snake_.face(Direction::up);
        break;
      case SceneEvent::left:
        snake_.face(Direction::left);
        break;
      case SceneEvent::right:
        snake_.face(Direction::right);
        break;
      default:
        throw std::logic_error("Invalid SceneEvent");
    }

    event_queue_.pop();
  }
}

void SnakeScene::draw(Window *window) const
{
  // Clear the screen first.
  window->draw_filled_rect(0, 0, window->width(), window->height(),
                           0x00, 0xFF, 0x00, 0xFF);

  // Now draw the fruits.
  fruit_manager_.draw(window);

  // Finally draw the snake itself.
  snake_.draw(window);

}
