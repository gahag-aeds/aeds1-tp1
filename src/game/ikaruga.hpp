#ifndef __GAME_IKARUGA_HPP__
#define __GAME_IKARUGA_HPP__

#include <allegro/bitmap.hpp>
#include <allegro/bounds.hpp>
#include <allegro/color.hpp>
#include <allegro/display.hpp>
#include <allegro/position.hpp>
#include <allegro/size.hpp>

#include <game/horai.hpp>
#include <game/polarity.hpp>
#include <game/direction.hpp>


namespace Game {
  class Ikaruga {
  public:
    const Allegro::Size Size;
    const float Speed;
    Allegro::Position Pos;
    
    Ikaruga(
      const Allegro::Size,
      const Game::Polarity,
      const float speed,
      const Allegro::Position
    );
    
    void Flip();
    
    void Move(double, Allegro::Bounds);  // Direction in radians.
    
    bool Collides(const Horai&); // Checks collision with a horai.
                                 // Returns wether ikaruga collided with the horai.
    
    bool Alive() const;
    
    Game::Polarity Polarity() const;
    
    unsigned Score() const;
    
    void DrawOn(const Allegro::Display& display) const;
    
  private:
    const Allegro::Bitmap bmp;
    bool alive;
    Game::Polarity polarity;
    unsigned score;
  };
}

#endif /* __GAME_IKARUGA_HPP__ */
