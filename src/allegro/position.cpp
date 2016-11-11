#include <cmath>

#include <allegro/position.hpp>
#include <allegro/bounds.hpp>


namespace Allegro {
  void Position::Move(double distance, double direction, const Bounds& bounds) {
    this->x += distance * std::cos(direction); // x axis grows forwards.
    this->y -= distance * std::sin(direction); // y axis grows downwards.
    
    this->x = std::min(std::max(bounds.Min.x, this->x), bounds.Max.x);
    this->y = std::min(std::max(bounds.Min.y, this->y), bounds.Max.y);
  }
  
  
  bool Position::In(const Bounds& bounds) const {
    return this->x >= bounds.Min.x && this->x <= bounds.Max.x
        && this->y >= bounds.Min.y && this->y <= bounds.Max.y;
  }
  
  Position Position::Map(const std::function<Position(float, float)>& fn) const {
    return fn(this->x, this->y);
  }
  
  
  bool operator==(const Position& p1, const Position& p2) {
    return p1.x == p2.x
        && p1.y == p2.y;
  }
  
  bool operator!=(const Position& p1, const Position& p2) {
    return !(p1 == p2);
  }
  
  
  Position operator+(Position p1, const Position& p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    
    return p1;
  }
  
  Position operator-(Position p1, const Position& p2) {
    p1.x = std::abs(p1.x - p2.x);
    p1.y = std::abs(p1.y - p2.y);
    
    return p1;
  }
}
