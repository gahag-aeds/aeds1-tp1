#include <allegro/bounds.hpp>
#include <allegro/size.hpp>


namespace Allegro {
  Bounds Bounds::Reduce(Allegro::Size size) const {
    return Bounds(
      this->Min,
      this->Max.Map([&](auto x, auto y) { return Position(x - size.Width, y - size.Height); })
    );
  }
  
  Position Bounds::RandomPos() const {
    auto floor = [](auto val) { return static_cast<unsigned long>(val); };
    
    return Position(
      floor(this->Min.x) + std::rand() % floor(this->Max.x - this->Min.x),
      floor(this->Min.y) + std::rand() % floor(this->Max.y - this->Min.y)
    );
  }
}
