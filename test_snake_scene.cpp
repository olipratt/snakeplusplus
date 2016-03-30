#include <exception>
#include <stdexcept>

#include <vector>

#include <catch.hpp>

#include <snake_scene.hpp>


TEST_CASE( "Update a snake scene until it ends", "[scene]" )
{
  SnakeScene snake_scene {3, 3};

  snake_scene.update();
  snake_scene.update();

  REQUIRE_THROWS_AS( snake_scene.update(), std::runtime_error );
}