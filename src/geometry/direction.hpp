#ifndef DIRECTIONHPPINCLUDED
#define DIRECTIONHPPINCLUDED

#include <point2d.hpp>

enum class Direction { up, down, left, right };

constexpr Point2D<int> direction_unit_vector(Direction dir)
{
  return ((dir == Direction::up) ? Point2D<int>(0, -1) :
          (dir == Direction::right) ? Point2D<int> (1, 0) :
          (dir == Direction::down) ? Point2D<int> (0, 1) :
          Point2D<int> (-1, 0)); // Argument must be Direction::left.
}

constexpr Direction direction_opposite(Direction dir)
{
  return ((dir == Direction::up) ? Direction::down :
          (dir == Direction::right) ? Direction::left :
          (dir == Direction::down) ? Direction::up :
          Direction::right); // Argument must be Direction::left.
}

#endif
