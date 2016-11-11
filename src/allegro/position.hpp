#ifndef __ALLEGRO_POSITION_HPP__
#define __ALLEGRO_POSITION_HPP__

#include <functional>
#include <stdexcept>


namespace Allegro {
  struct Bounds;
  
  struct Position {
    float x, y;
    
    constexpr Position(const float x, const float y) : x(x), y(y) {
      if (x < 0 || y < 0)
        throw std::runtime_error("negative parameter in position");
    }
    
    void Move(double distance, double direction, const Bounds&);  // Direction in radians.
    
    bool In(const Bounds&) const;
    
    Position Map(const std::function<Position(float, float)>&) const;
  };
  
  bool operator==(const Position&, const Position&);
  bool operator!=(const Position&, const Position&);
  
  Position operator+(Position, const Position&);
  Position operator-(Position, const Position&); // Absolute difference
}                                                // between coordinates.

#endif /* __ALLEGRO_POSITION_HPP__ */
