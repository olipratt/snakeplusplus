

#include <SDL.h>
#include <stdexcept>
#include <string>

#include <main_loop.hpp>

void init()
{
  //Initialize SDL
  auto init_rc = SDL_Init(SDL_INIT_VIDEO);
  if (init_rc < 0)
  {
    throw std::runtime_error(
      std::string("SDL could not initialize! SDL_Error: ") + SDL_GetError());
  }
}

void term()
{
  SDL_Quit();
}

int main( int argc, char* args[] )
{
  // Initialise everything.
  init();

  // Run the game.
  main_loop();

  // Terminate everything.
  term();

  return 0;
}