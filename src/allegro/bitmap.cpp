#include <stdexcept>

#include <allegro/bitmap.hpp>


namespace Allegro {
  Bitmap::Bitmap(const Allegro::Size size)
  : Size(size), bitmap(al_create_bitmap(size.Width, size.Height), al_destroy_bitmap)
  {
    if (!this->bitmap)
      throw std::runtime_error("failed to create bitmap");
  }
  
  Bitmap::Bitmap(const Allegro::Size size, const Color color) : Bitmap(size) {
    this->Paint(color);
  }
  
  
  void Bitmap::Paint(const Color color) const {
    al_set_target_bitmap(this->bitmap.get());
    al_clear_to_color(color.Value);
  }
}
