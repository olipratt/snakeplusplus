#ifndef SCENEHPPINCLUDED
#define SCENEHPPINCLUDED

#include <scene_event.hpp>
#include <renderapi.hpp>

class Scene {
public:
  virtual void update(int elapsed_ticks) = 0;
  virtual void queue_event(SceneEvent event) = 0;
  virtual void draw(Window *window) = 0;
};

#endif
