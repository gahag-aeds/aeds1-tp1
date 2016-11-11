#ifndef __ALLEGRO_BOUNDS_HPP__
#define __ALLEGRO_BOUNDS_HPP__

#include <stdexcept>

#include <allegro/position.hpp>


namespace Allegro {
  struct Size;
  
  struct Bounds {
    const Position Min, Max;
    
    constexpr Bounds(const Position min, const Position max) : Min(min), Max(max) {
      if (min.x > max.x || min.y > max.y)
        throw std::runtime_error("invalid min/max bounds");
    }
    
    Bounds Reduce(Allegro::Size) const;
    
    Position RandomPos() const;
  };
}

#endif /* __ALLEGRO_BOUNDS_HPP__ */
