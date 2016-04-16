
#include <algorithm>
#include <list>

#include <point2d.hpp>
#include <direction.hpp>
#include <window.hpp>
#include <sdlrenderapi.hpp>


void SDLSnakeRenderer::draw(Window *window,
                            Point2D<int> head_location,
                            const std::list<Point2D<int>> &body_locations,
                            Direction facing,
                            unsigned int board_width,
                            unsigned int board_height)
{
  unsigned int segment_width = window->width() / board_width;
  unsigned int segment_height = window->height() / board_height;
  window->draw_filled_rect(head_location.x() * segment_width,
                           head_location.y() * segment_height,
                           segment_width, segment_height,
                           0x3D, 0x41, 0x24, 0xFF);
  for(const Point2D<int> &point : body_locations)
  {
    window->draw_filled_rect(point.x() * segment_width,
                             point.y() * segment_height,
                             segment_width, segment_height,
                             0x7A, 0x52, 0x48, 0xFF);
  }
}

void SDLFruitRenderer::draw(Window *window,
                            Point2D<int> fruit_location,
                            unsigned int board_width,
                            unsigned int board_height)
{
  unsigned int fruit_width = window->width() / board_width;
  unsigned int fruit_height = window->height() / board_height;
  window->draw_filled_rect(fruit_location.x() * fruit_width,
                           fruit_location.y() * fruit_height,
                           fruit_width, fruit_height,
                           0xFF, 0x00, 0x00, 0xFF);
}
