#include <SDL.h>

#include <sdleventqueue.hpp>


void SDLSceneEventQueue::poll()
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
