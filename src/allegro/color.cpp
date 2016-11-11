#include <cstdlib>

#include <allegro/color.hpp>


namespace Allegro {
  Color Color::White() { return Color(255, 255, 255); }
  Color Color::Black() { return Color(0,     0,   0); }
  Color Color::Red()   { return Color(255,   0,   0); }
  Color Color::Green() { return Color(0,   255,   0); }
  Color Color::Blue()  { return Color(0,     0, 255); }
  Color Color::Random() {
    return Color(std::rand() % 256, std::rand() % 256, std::rand() % 256);
  }
  
  Color::Color(unsigned char r, unsigned char g, unsigned char b)
  : Value(al_map_rgb(r, g, b))
  { }
}
