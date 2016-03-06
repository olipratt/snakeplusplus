#include <catch.hpp>

#include <snake.hpp>



TEST_CASE( "Create a snake", "[snake]" ) {

    Snake snake {0, 0, Direction::right};

    REQUIRE( 1 == 1 );
}
