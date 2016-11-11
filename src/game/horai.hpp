#ifndef __GAME_HORAI_HPP__
#define __GAME_HORAI_HPP__

#include <allegro/bitmap.hpp>
#include <allegro/bounds.hpp>
#include <allegro/color.hpp>
#include <allegro/display.hpp>
#include <allegro/position.hpp>
#include <allegro/size.hpp>

#include <game/polarity.hpp>


namespace Game {
  class Horai {
  public:
    const Allegro::Size Size;
    const Game::Polarity Polarity;
    const float Speed;
    Allegro::Position Pos;
    
    Horai(
      const Allegro::Size,
      const Game::Polarity,
      const float speed,
      const Allegro::Position
    );
    
    void Move(double, Allegro::Bounds); // direction in radians.
    
    void DrawOn(const Allegro::Display& display) const;
    
  private:
    const Allegro::Bitmap bmp;
  };
}

#endif /* __GAME_HORAI_HPP__ */
