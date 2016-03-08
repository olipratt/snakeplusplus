
#include <point2d.hpp>

enum class Direction { up, down, left, right };

Point2D<int> direction_unit_vector(Direction);

class Screen;

class Snake {
private:
  Point2D<int> position_;
  Direction direction_;

public:
  Snake(const Point2D<int> &pos, Direction dir) : position_{pos}, direction_{dir} {}

  Point2D<int> position() const { return position_; }

  void move();
  void face(Direction dir);

  void draw(Screen *screen);
};
