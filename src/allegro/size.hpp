#ifndef __ALLEGRO_SIZE_HPP__
#define __ALLEGRO_SIZE_HPP__

#include <stdexcept>

#include <allegro/position.hpp>
#include <allegro/bounds.hpp>


namespace Allegro {
  struct Size {
    const float Width, Height;
    const Position Center;
    const Allegro::Bounds Bounds;
    
    constexpr Size(const float width, const float height)
    : Width(width), Height(height)
    , Center(Allegro::Position(width / 2, height / 2))
    , Bounds(Allegro::Position(0, 0), Allegro::Position(width, height))
    {
      if (width < 0 || height < 0)
        throw std::runtime_error("negative parameter in size");
    }
  };
}

#endif /* __ALLEGRO_SIZE_HPP__ */
