#include <ostream>

template<typename T>
class Point2D {
public:
  constexpr T x() const { return x_pos; }
  constexpr T y() const { return y_pos; }
  constexpr Point2D(int x, int y) : x_pos{x}, y_pos{y} {}

  constexpr Point2D<T> operator+(const Point2D<T> &other) const {
    return Point2D<T> { x() + other.x(), y() + other.y()}; }


  constexpr bool operator==(const Point2D<T> &other) const {
    return x() == other.x() && y() == other.y(); }

  std::ostream& operator << (std::ostream& os) const {
    os << "Point2D(" << x() << ", " << y() << ")";
    return os;
  }


private:
  T x_pos;
  T y_pos;
};


