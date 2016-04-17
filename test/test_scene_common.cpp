#include <exception>
#include <stdexcept>

#include <vector>

#include <catch.hpp>

#include <scene.hpp>
#include <snake_scene.hpp>
#include <dummyrenderapi.hpp>


TEST_CASE( "Multiple scenes can be held in a container", "[scene]" )
{
  std::vector<Scene*> scenes;
  DummyRendererFactory renderer {};
  SnakeScene snake_scene {4, 3, 1000, &renderer};
  scenes.push_back(&snake_scene);
}
