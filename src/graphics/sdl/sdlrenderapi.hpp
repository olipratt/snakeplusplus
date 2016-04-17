#ifndef SDLRENDERAPIINCLUDED
#define SDLRENDERAPIINCLUDED

#include <direction.hpp>
#include <point2d.hpp>
#include <window.hpp>
#include <renderapi.hpp>



class SDLSceneRenderer : public SceneRenderer
{
public:
  void clear(Window *window);
};

class SDLSnakeRenderer : public SnakeRenderer
{
public:
  void draw(Window *window,
            Point2D<int> head_location,
            const std::list<Point2D<int>> &body_locations,
            Direction facing,
            unsigned int board_width,
            unsigned int board_height);
};

class SDLFruitRenderer : public FruitRenderer
{
public:
  void draw(Window *window,
            Point2D<int> fruit_location,
            unsigned int board_width,
            unsigned int board_height);
};

class SDLRendererFactory : public RendererFactory
{
public:
  std::unique_ptr<SceneRenderer> new_scene_renderer() {
    return std::unique_ptr<SDLSceneRenderer> (new SDLSceneRenderer);
  }

  std::unique_ptr<SnakeRenderer> new_snake_renderer() {
    return std::unique_ptr<SDLSnakeRenderer> (new SDLSnakeRenderer);
  }

  std::unique_ptr<FruitRenderer> new_fruit_renderer() {
    return std::unique_ptr<SDLFruitRenderer> (new SDLFruitRenderer);
  }
};

#endif
