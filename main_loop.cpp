
#include <SDL.h>

#include <stdexcept>

#include <queue>

#include <window.hpp>
#include <snake_scene.hpp>


//Screen dimension constants,
const char *SCREEN_NAME = "Snake";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


class SceneEventQueue
{
public:
  void poll();
  bool empty() const { return event_queue_.empty(); }
  bool quit() const { return quit_; }
  SceneEvent front() const { return event_queue_.front(); }
  void pop() { event_queue_.pop(); }

private:
  std::queue<SceneEvent> event_queue_{};
  bool quit_{false};

};


void SceneEventQueue::poll()
{
  SDL_Event event;

  while (SDL_PollEvent(&event) != 0)
  {
    if (event.type == SDL_QUIT)
    {
      quit_ = true;
    }
    else if( event.type == SDL_KEYDOWN )
    {
      switch( event.key.keysym.sym )
      {
        case SDLK_UP:
          event_queue_.push(SceneEvent::up);
          break;
        case SDLK_DOWN:
          event_queue_.push(SceneEvent::down);
          break;
        case SDLK_LEFT:
          event_queue_.push(SceneEvent::left);
          break;
        case SDLK_RIGHT:
          event_queue_.push(SceneEvent::right);
          break;
      }
    }
  }
}

void main_loop()
{
  SceneEventQueue event_queue;

  // The window we'll be rendering to.
  Window window {SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT};

  SnakeScene snake_scene {3, 3, 1000};

  int last_update_time = SDL_GetTicks();
  int this_update_time;

  while (true)
  {
    // Process any input.
    event_queue.poll();
    if (event_queue.quit())
    {
      break;
    }
    while (!event_queue.empty())
    {
      snake_scene.queue_event(event_queue.front());
      event_queue.pop();
    }

    //Update the current scene.
    this_update_time = SDL_GetTicks();
    try
    {
      snake_scene.update(this_update_time - last_update_time);
    }
    catch (const std::runtime_error &error)
    {
      // The game has ended.
      break;
    }
    last_update_time = this_update_time;

    // Draw to the window.
    snake_scene.draw(&window);

    // Render the window.
    window.update();
  }

  // Fill the window red.
  window.draw_filled_rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
                          0xFF, 0x00, 0x00, 0xFF);

  //Update the window.
  window.update();

  // Wait two seconds so we can see the result.
  SDL_Delay(2000);
}
