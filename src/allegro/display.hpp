#ifndef __ALLEGRO_DISPLAY_HPP__
#define __ALLEGRO_DISPLAY_HPP__

#include <memory>

#include <allegro5/allegro.h>

#include <allegro/bitmap.hpp>
#include <allegro/color.hpp>
#include <allegro/font.hpp>
#include <allegro/position.hpp>
#include <allegro/size.hpp>


namespace Allegro {
  class Display {
  public:
    const Allegro::Size Size;
    const Color Background;
    
    
    Display(const Allegro::Size, const Color);
    
    void SetTitle(const std::string&) const;
    
    void Clear() const; // Clears the display.
    
    void Paint(const Color&) const;
    
    void Draw(const Bitmap&, const Position&) const;
    void Draw(const std::string&, const Font&, const Color&, const Position&) const;
    
    void Invalidate() const;
    
    ALLEGRO_EVENT_SOURCE* EventSource() const;
    
  private:
    const std::shared_ptr<ALLEGRO_DISPLAY> display;
    
    void Focus() const; // Focus display for drawing.
  };
}

#endif /* __ALLEGRO_DISPLAY_HPP__ */
