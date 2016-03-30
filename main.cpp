
//Using SDL and standard IO
#include <SDL.h>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

//Screen dimension constants,
const char *SCREEN_NAME = "Snake";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


class Window {
public:
  Window();
  ~Window() { SDL_DestroyWindow(window); }

  void update();

  void draw_filled_rect(int x, int y, int width, int height,
                        unsigned char r, unsigned char g,
                        unsigned char b, unsigned char a);

private:
  SDL_Window* window;
  SDL_Renderer *renderer_;

  SDL_Renderer *new_renderer();
};

Window::Window()
{
  window = SDL_CreateWindow(SCREEN_NAME,
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH,
                            SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN);
  if( window == NULL )
  {
    throw std::runtime_error(
                      std::string("Window could not be created! SDL_Error: ") +
                      SDL_GetError());
  }

  renderer_ = new_renderer();
}

SDL_Renderer *Window::new_renderer()
{
  // Create renderer for window.
  auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL)
  {
    throw std::runtime_error(
                    std::string("Renderer could not be created! SDL_Error: ") +
                    SDL_GetError());
  }

  return renderer;
}

void Window::draw_filled_rect(int x, int y, int width, int height,
                              unsigned char r, unsigned char g,
                              unsigned char b, unsigned char a)
{
  SDL_Rect fill_rect = {x, y, width, height};
  SDL_SetRenderDrawColor(renderer_, r, g, b, a);
  SDL_RenderFillRect(renderer_, &fill_rect);
}

void Window::update()
{
  SDL_RenderPresent(renderer_);
}

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

void run()
{
  // The window we'll be rendering to.
  Window window;

  // Fill the window red.
  window.draw_filled_rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
                          0xFF, 0x00, 0x00, 0xFF);

  //Update the window.
  window.update();

  // Wait two seconds so we can see the result.
  SDL_Delay(2000);
}

int main( int argc, char* args[] )
{
  // Initialise everything.
  init();

  // Run the game.
  run();

  // Terminate everything.
  term();

  return 0;
}