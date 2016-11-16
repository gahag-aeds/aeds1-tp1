#include <cstdlib>

#include <game/polarity.hpp>


namespace Game {
  Polarity RandomPolarity() {
    return (std::rand() % 2) == 1 ? Polarity::Blue
                                  : Polarity::Green;
  }
  
  Allegro::Color Color(Polarity pol) {
    return pol == Polarity::Green ? Allegro::Color::Green()
                                  : Allegro::Color::Blue();
  }
}
