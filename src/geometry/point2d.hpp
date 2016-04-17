#ifndef POINT2DHPPINCLUDED
#define POINT2DHPPINCLUDED
#include <ostream>

template<typename T>
class Point2D {
public:
  constexpr Point2D(int x, int y) : x_{x}, y_{y} {}

  constexpr T x() const { return x_; }
  constexpr T y() const { return y_; }

  constexpr Point2D<T> operator+(const Point2D<T> &other) const {
    return Point2D<T> { x() + other.x(), y() + other.y()};
  }

  constexpr bool operator==(const Point2D<T> &other) const {
    return x() == other.x() && y() == other.y();
  }

  friend std::ostream& operator<<(std::ostream& os, const Point2D<T> &point) {
    os << "Point2D(" << point.x() << ", " << point.y() << ")";
    return os;
  }

private:
  T x_;
  T y_;
};

#endif
