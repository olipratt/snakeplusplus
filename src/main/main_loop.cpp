
#include <SDL.h>

#include <stdexcept>

#include <queue>

#include <window.hpp>
#include <snake_scene.hpp>
#include <sdleventqueue.hpp>
#include <sdlrenderapi.hpp>


// Screen name and dimension constants.
const char *SCREEN_NAME = "Snake";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


void main_loop()
{
  SDLSceneEventQueue event_queue;

  // The window we'll be rendering to.
  Window window {SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT};

  SDLRendererFactory render_fact {};

  SnakeScene snake_scene {4, 4, 750, &render_fact};

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
