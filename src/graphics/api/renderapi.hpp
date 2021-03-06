#ifndef RENDERAPIINCLUDED
#define RENDERAPIINCLUDED

#include <memory>
#include <list>

#include <direction.hpp>
#include <point2d.hpp>

class Window;

class SceneRenderer
{
public:
  virtual void clear(Window *window) = 0;
};

class SnakeRenderer
{
public:
  virtual void draw(Window *window,
                    Point2D<int> head_location,
                    const std::list<Point2D<int>> &body_locations,
                    Direction facing,
                    unsigned int board_width,
                    unsigned int board_height) = 0;
};

class FruitRenderer
{
public:
  virtual void draw(Window *window,
                    Point2D<int> fruit_location,
                    unsigned int board_width,
                    unsigned int board_height) = 0;
};

class RendererFactory
{
public:
  virtual std::unique_ptr<SceneRenderer> new_scene_renderer() =0;
  virtual std::unique_ptr<SnakeRenderer> new_snake_renderer() =0;
  virtual std::unique_ptr<FruitRenderer> new_fruit_renderer() =0;
};

#endif






























