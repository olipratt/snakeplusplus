#ifndef SNAKESCENEHPPINCLUDED
#define SNAKESCENEHPPINCLUDED

#include <algorithm>
#include <list>

#include <point2d.hpp>
#include <direction.hpp>
#include <location_source.hpp>
#include <fruit_manager.hpp>
#include <snake.hpp>


class SnakeScene {
public:
  SnakeScene(unsigned int width, unsigned int height) :
    location_source_{width, height}, fruit_manager_{&location_source_},
    snake_{&fruit_manager_, &location_source_, {0, 0}, Direction::right}
    {}

  void update() { snake_.move(); }

private:
  LocationSource location_source_;
  FruitManager fruit_manager_;
  Snake snake_;
};

#endif