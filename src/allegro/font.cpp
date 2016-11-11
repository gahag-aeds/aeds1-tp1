#include <stdexcept>

#include <allegro/font.hpp>


namespace Allegro {
  void Font::Init() {
    al_init_font_addon();
    
    if (!al_init_ttf_addon())
      throw std::runtime_error("failed to initialize tff addon");
  }
  
  
  Font::Font(const std::string file, const int size)
  : font(al_load_font(file.c_str(), size, 0), al_destroy_font)
  {
    if (!this->font)
      throw std::runtime_error("failed to initialize font");
  }
}
