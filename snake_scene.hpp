#ifndef SNAKESCENEHPPINCLUDED
#define SNAKESCENEHPPINCLUDED

#include <algorithm>
#include <list>

#include <point2d.hpp>
#include <direction.hpp>
#include <location_source.hpp>
#include <fruit_manager.hpp>
#include <snake.hpp>
#include <scene_event.hpp>


class SnakeScene {
public:
  SnakeScene(unsigned int width, unsigned int height) :
    location_source_{width, height}, fruit_manager_{&location_source_},
    snake_{&fruit_manager_, &location_source_, {0, 0}, Direction::right}
    {}

  void update();
  void queue_event(SceneEvent event) { event_queue_.push(event); }

private:
  LocationSource location_source_;
  FruitManager fruit_manager_;
  Snake snake_;
  std::queue<SceneEvent> event_queue_;

  void process_event_queue();
};

#endif