#ifndef __GAME_POLARITY_HPP__
#define __GAME_POLARITY_HPP__

#include <allegro/color.hpp>


namespace Game {
  enum class Polarity {
    Green,
    Blue
  };
  
  constexpr Polarity Flip(Polarity pol) {
    return pol == Polarity::Green ? Polarity::Blue
                                  : Polarity::Green;
  }
  
  Polarity RandomPolarity();
  
  Allegro::Color Color(Polarity);
}

#endif /* __GAME_POLARITY_HPP__ */
