#ifndef __ALLEGRO_FONT_HPP__
#define __ALLEGRO_FONT_HPP__

#include <string>
#include <memory>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


namespace Allegro {
  class Font {
    friend class Display;
    
  public:
    static void Init(); // Throws runtime_error on failure.
    
    Font(const std::string file, const int size);
    
  private:
    const std::shared_ptr<ALLEGRO_FONT> font;
  };
}

#endif /* __ALLEGRO_FONT_HPP__ */
