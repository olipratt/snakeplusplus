#ifndef WINDOWHPPINCLUDED
#define WINDOWHPPINCLUDED

#include <SDL.h>


class Window {
public:
  Window(const char *name, int width, int height);
  ~Window();

  int width() { return width_; }
  int height() { return height_; }

  void update();

  void draw_filled_rect(int x, int y, int width, int height,
                        unsigned char r, unsigned char g,
                        unsigned char b, unsigned char a);

private:
  int width_;
  int height_;
  SDL_Window* window;
  SDL_Renderer *renderer_;

  SDL_Renderer *new_renderer();
};

#endif
