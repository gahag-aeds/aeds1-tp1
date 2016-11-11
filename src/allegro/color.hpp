#ifndef __ALLEGRO_COLOR_HPP__
#define __ALLEGRO_COLOR_HPP__

#include <allegro5/allegro.h>


namespace Allegro {
  class Color {
  public:
    static Color White();
    static Color Black();
    static Color Red();
    static Color Green();
    static Color Blue();
    static Color Random();
    
    
    Color(const unsigned char r, const unsigned char g, const unsigned char b);
    
    const ALLEGRO_COLOR Value;
  };
}

#endif /* __ALLEGRO_COLOR_HPP__ */
