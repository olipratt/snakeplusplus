
#include <window.hpp>
#include <stdexcept>
#include <string>


Window::Window(const char *name, int width, int height)
  : width_{width}, height_{height}
{
  window = SDL_CreateWindow(name,
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            width,
                            height,
                            SDL_WINDOW_SHOWN);
  if( window == NULL )
  {
    throw std::runtime_error(
                      std::string("Window could not be created! SDL_Error: ") +
                      SDL_GetError());
  }

  renderer_ = new_renderer();
}

Window::~Window()
{
  SDL_DestroyWindow(window);
}

SDL_Renderer *Window::new_renderer()
{
  // Create renderer for window.
  auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                                 SDL_RENDERER_PRESENTVSYNC);
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
