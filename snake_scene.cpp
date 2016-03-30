
#include <exception>
#include <stdexcept>

#include <snake_scene.hpp>


void SnakeScene::update()
{
  // Process events from the queue.
  process_event_queue();

  // Now move the snake.
  snake_.move();
}

void SnakeScene::process_event_queue()
{
  while (!event_queue_.empty())
  {
    SceneEvent event = event_queue_.front();

    switch(event)
    {
      case SceneEvent::Down:
        snake_.face(Direction::down);
        break;
      case SceneEvent::Up:
        snake_.face(Direction::up);
        break;
      case SceneEvent::Left:
        snake_.face(Direction::left);
        break;
      case SceneEvent::Right:
        snake_.face(Direction::right);
        break;
      default:
        throw std::logic_error("Invalid SceneEvent");
    }

    event_queue_.pop();
  }
}
