#include <cmath>

#include <game/physics.hpp>
#include <game/ikaruga.hpp>


namespace Game {
  Ikaruga::Ikaruga(
    const Allegro::Size size,
    const Game::Polarity polarity,
    const float speed,
    const Allegro::Position pos
  ) : Size(size)
    , Speed(speed)
    , Pos(pos)
    , bmp(size, Color(polarity))
    , alive(true)
    , polarity(polarity)
    , score(0)
  { }
  
  
  void Ikaruga::Flip() {
    this->polarity = Game::Flip(this->polarity);
    this->bmp.Paint(Color(this->polarity));
  }
  
  void Ikaruga::Move(double direction, Allegro::Bounds bounds) {
    this->Pos.Move(this->Speed, direction, bounds);
  }
  
  bool Ikaruga::Collide(const Horai& horai) {
    if (Game::rectCollision(*this, horai)) {
      if (this->Polarity() == horai.Polarity)
        this->score++;
      else
        this->alive = false;
      
      return true;
    }
    
    return false;
  }
  
  
  bool Ikaruga::Alive() const {
    return this->alive;
  }
  
  Game::Polarity Ikaruga::Polarity() const {
    return this->polarity;
  }
  
  unsigned Ikaruga::Score() const {
    return this->score;
  }
  
  
  void Ikaruga::DrawOn(const Allegro::Display& display) const {
    display.Draw(this->bmp, this->Pos);
  }
}
