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
#include <scene.hpp>
#include <renderapi.hpp>


class SnakeScene: public Scene
{
public:
  SnakeScene(unsigned int width, unsigned int height, int ticks_per_move,
             RendererFactory *render_fact)
    : location_source_{width, height},
      fruit_manager_{&location_source_, render_fact},
      snake_{&fruit_manager_, &location_source_, {0, 0}, Direction::right,
             render_fact},
      ticks_per_move_{ticks_per_move},
      renderer_{render_fact->new_scene_renderer()}
    { fruit_manager_.place_fruit({static_cast<int>(width / 2),
                                  static_cast<int>(height / 2)}); }

  void update(int elapsed_ticks);
  void queue_event(SceneEvent event) { event_queue_.push(event); }
  void draw(Window *window);

private:
  LocationSource location_source_;
  FruitManager fruit_manager_;
  Snake snake_;
  std::queue<SceneEvent> event_queue_;
  int ticks_per_move_;
  int ticks_since_move_{0};
  std::unique_ptr<SceneRenderer> renderer_;

  void process_event_queue();
  void process_ticks(int elapsed_ticks);
};

#endif