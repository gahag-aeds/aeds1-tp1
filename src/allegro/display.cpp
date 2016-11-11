#include <stdexcept>

#include <allegro/display.hpp>


namespace Allegro {
  Display::Display(const Allegro::Size size, const Color bg)
  : Size(size)
  , Background(bg)
  , display(al_create_display(size.Width, size.Height), al_destroy_display)
  {
    if (!this->display)
      throw std::runtime_error("failed to create display");
    
    this->Clear();
  }
  
  
  void Display::SetTitle(const std::string& title) const {
    al_set_window_title(this->display.get(), title.c_str());
  }
  
  void Display::Clear() const {
    this->Paint(this->Background);
  }
  
  void Display::Paint(const Color& color) const {
    this->Focus();
    al_clear_to_color(color.Value);
  }
  
  void Display::Draw(const Bitmap& bmp, const Position& pos) const {
    this->Focus();
    al_draw_bitmap(bmp.bitmap.get(), pos.x, pos.y, 0);
  }
  
  void Display::Draw(
    const std::string& text,
    const Font& font,
    const Color& color,
    const Position& pos
  ) const {
    this->Focus();
    
    al_draw_text(
      font.font.get(),
      color.Value,
      pos.x,
      pos.y,
      ALLEGRO_ALIGN_CENTRE,
      text.c_str()
    );
  }
  
  void Display::Invalidate() const {
    al_flip_display();
  }
  
  ALLEGRO_EVENT_SOURCE* Display::EventSource() const {
    return al_get_display_event_source(this->display.get());
  }
  
  
  inline void Display::Focus() const {
    al_set_target_bitmap(al_get_backbuffer(this->display.get()));
  }
}
