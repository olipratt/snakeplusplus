#ifndef DUMMYRENDERAPIINCLUDED
#define DUMMYRENDERAPIINCLUDED

#include <exception>
#include <stdexcept>
#include <memory>

#include <direction.hpp>
#include <point2d.hpp>
#include <renderapi.hpp>


class DummySceneRenderer : public SceneRenderer
{
public:
  void clear(Window *window)
  {
    throw std::logic_error("Dummy clear should never be called");
  }
};

class DummySnakeRenderer : public SnakeRenderer
{
public:
  void draw(Window *window,
            Point2D<int> head_location,
            const std::list<Point2D<int>> &body_locations,
            Direction facing,
            unsigned int board_width,
            unsigned int board_height)
  {
    throw std::logic_error("Dummy draw should never be called");
  }
};

class DummyFruitRenderer : public FruitRenderer
{
public:
  void draw(Window *window,
            Point2D<int> fruit_location,
            unsigned int board_width,
            unsigned int board_height)
  {
    throw std::logic_error("Dummy draw should never be called");
  }
};

class DummyRendererFactory : public RendererFactory
{
public:
  std::unique_ptr<SceneRenderer> new_scene_renderer() {
    return std::unique_ptr<DummySceneRenderer> (new DummySceneRenderer);
  }

  std::unique_ptr<SnakeRenderer> new_snake_renderer() {
    return std::unique_ptr<DummySnakeRenderer> (new DummySnakeRenderer);
  }

  std::unique_ptr<FruitRenderer> new_fruit_renderer() {
    return std::unique_ptr<DummyFruitRenderer> (new DummyFruitRenderer);
  }
};

#endif
