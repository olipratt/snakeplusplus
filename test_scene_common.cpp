#include <exception>
#include <stdexcept>

#include <vector>

#include <catch.hpp>

#include <scene.hpp>
#include <snake_scene.hpp>


TEST_CASE( "Multiple scenes can be held in a container", "[scene]" )
{
  std::vector<Scene*> scenes;
  SnakeScene snake_scene {4, 3, 1000};
  scenes.push_back(&snake_scene);
}
