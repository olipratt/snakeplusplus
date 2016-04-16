#include <exception>
#include <stdexcept>

#include <vector>

#include <catch.hpp>

#include <snake_scene.hpp>
#include <dummyrenderapi.hpp>


TEST_CASE( "Update a snake scene until it ends", "[scene]" )
{
  DummyRendererFactory renderer {};
  SnakeScene snake_scene {3, 3, 1000, &renderer};

  SECTION( "Update in exact ticks-per-move increments" )
  {
    snake_scene.update(1000);
    snake_scene.update(1000);
    REQUIRE_THROWS_AS( snake_scene.update(1000), std::runtime_error );
  }
  SECTION( "Update in exact ticks-per-move increments, but subdivided" )
  {
    snake_scene.update(500);
    snake_scene.update(500);
    snake_scene.update(200);
    snake_scene.update(200);
    snake_scene.update(200);
    snake_scene.update(200);
    snake_scene.update(200);
    REQUIRE_THROWS_AS( snake_scene.update(1000), std::runtime_error );
  }
  SECTION( "Update in non-exact ticks-per-move increments" )
  {
    snake_scene.update(1001);
    snake_scene.update(1002);
    REQUIRE_THROWS_AS( snake_scene.update(1003), std::runtime_error );
  }
  SECTION( "Update multiple ticks-per-move increments simultaneously" )
  {
    snake_scene.update(2005);
    REQUIRE_THROWS_AS( snake_scene.update(995), std::runtime_error );
  }
  SECTION( "Update 0 ticks" )
  {
    snake_scene.update(0);
    snake_scene.update(2000);
    snake_scene.update(0);
    snake_scene.update(0);
    REQUIRE_THROWS_AS( snake_scene.update(1000), std::runtime_error );
  }
}

TEST_CASE( "A scene can handle basic event input", "[scene]" )
{
  DummyRendererFactory renderer {};
  SnakeScene snake_scene {4, 3, 1000, &renderer};

  snake_scene.queue_event(SceneEvent::down);

  snake_scene.update(1000);
  snake_scene.update(1000);

  REQUIRE_THROWS_AS( snake_scene.update(1000), std::runtime_error );
}
