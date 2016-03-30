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

TEST_CASE( "A scene can handle basic event input", "[scene]" )
{
  SnakeScene snake_scene {4, 3};

  snake_scene.queue_event(SceneEvent::Down);

  snake_scene.update();
  snake_scene.update();

  REQUIRE_THROWS_AS( snake_scene.update(), std::runtime_error );
}
