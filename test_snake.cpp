#include <exception>
#include <stdexcept>

#include <vector>

#include <catch.hpp>

#include <grid.hpp>
#include <snake.hpp>



TEST_CASE( "Create a snake", "[snake]" ) {

  Grid grid {3, 3};
  Snake snake {&grid, {0, 0}, Direction::right};

  REQUIRE( snake.position() == Point2D<int>(0, 0) );
}

TEST_CASE( "Snake movements", "[snake]" ) {

  Grid grid {3, 3};
  Snake snake {&grid, {0, 0}, Direction::right};

  SECTION( "Basic movement" )
  {
    snake.move();

    REQUIRE( snake.position() == Point2D<int>(1, 0) );

    snake.move();

    REQUIRE( snake.position() == Point2D<int>(2, 0) );
  }
  SECTION( "Change a snake's direction" )
  {
    snake.face(Direction::down);
    snake.move();

    REQUIRE( snake.position() == Point2D<int>(0, 1) );

    snake.face(Direction::right);
    snake.move();

    REQUIRE( snake.position() == Point2D<int>(1, 1) );
  }
  SECTION( "A snake can't go in the direction it last moved in" )
  {
    snake.face(Direction::left);
    snake.move();

    REQUIRE( snake.position() == Point2D<int>(1, 0) );

    snake.face(Direction::left);
    snake.move();

    REQUIRE( snake.position() == Point2D<int>(2, 0) );

    snake.face(Direction::down);
    snake.move();

    REQUIRE( snake.position() == Point2D<int>(2, 1) );

    snake.face(Direction::up);
    snake.move();

    REQUIRE( snake.position() == Point2D<int>(2, 2) );
  }
}

TEST_CASE( "A snake shouldn't be able to go outside the grid", "[snake]" ) {

  Grid grid {3, 3};
  Snake snake {&grid, {0, 0}, Direction::right};

  SECTION( "A snake can't go outside the grid in the positive direction" )
  {
    snake.move();
    snake.move();

    REQUIRE_THROWS_AS( snake.move(), std::runtime_error );
  }
  SECTION( "A snake can't go outside the grid in the negative direction" )
  {
    snake.face(Direction::up);

    REQUIRE_THROWS_AS( snake.move(), std::runtime_error );
  }
}

TEST_CASE( "A snake can grow as it moves", "[snake]" ) {

  Grid grid {3, 3};
  Snake snake {&grid, {0, 0}, Direction::right};
  grid.place_fruit({1, 0});

  SECTION( "A snake can eat a fruit to grow" )
  {
    snake.move();

    REQUIRE( snake.length() == 2 );
    REQUIRE( snake.occupies({0, 0}) );
    REQUIRE( snake.occupies({1, 0}) );

    REQUIRE_FALSE( grid.fruit_at({1, 0}) );
  }
}
