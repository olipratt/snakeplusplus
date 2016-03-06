

enum class Direction { up, down, left, right };

class Screen;

class Snake {
private:
  int x_pos;
  int y_pos;
  Direction direction;

  const int width {25};
  const int height {25};

public:
  Snake(int x, int y, Direction dir) : x_pos{x}, y_pos{y}, direction{dir} {}

  void draw(Screen *screen);
};

