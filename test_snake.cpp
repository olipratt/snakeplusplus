#include <catch.hpp>

#include <snake.hpp>



TEST_CASE( "Create a snake", "[snake]" ) {

    Snake snake {{0, 0}, Direction::right};

    REQUIRE( snake.position() == Point2D<int>(0, 0) );
}

TEST_CASE( "Move a snake", "[snake]" ) {

    Snake snake {{0, 0}, Direction::right};

    snake.move();

    REQUIRE( snake.position() == Point2D<int>(1, 0) );

    snake.move();

    REQUIRE( snake.position() == Point2D<int>(2, 0) );
}

TEST_CASE( "Change a snake's direction", "[snake]" ) {

    Snake snake {{0, 0}, Direction::right};

    snake.face(Direction::down);
    snake.move();

    REQUIRE( snake.position() == Point2D<int>(0, 1) );

    snake.face(Direction::right);
    snake.move();

    REQUIRE( snake.position() == Point2D<int>(1, 1) );
}

TEST_CASE( "A snake can't go in the direction it last moved in", "[snake]" ) {

    Snake snake {{0, 0}, Direction::right};

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
