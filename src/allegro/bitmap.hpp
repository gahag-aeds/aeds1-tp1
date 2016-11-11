#ifndef __ALLEGRO_BITMAP_HPP__
#define __ALLEGRO_BITMAP_HPP__

#include <memory>

#include <allegro5/allegro.h>

#include <allegro/color.hpp>
#include <allegro/size.hpp>


namespace Allegro {
  class Bitmap {
    friend class Display;
    
  public:
    const Allegro::Size Size;
    
    
    Bitmap(const Allegro::Size);
    Bitmap(const Allegro::Size, const Color);
    
    void Paint(const Color) const;
    
  private:
    const std::shared_ptr<ALLEGRO_BITMAP> bitmap;
  };
}

#endif /* __ALLEGRO_BITMAP_HPP__ */
