#include <cmath>

#include <game/horai.hpp>


namespace Game {
  Horai::Horai(
    const Allegro::Size size,
    const Game::Polarity polarity,
    const float speed,
    const Allegro::Position pos
  ) : Size(size), Polarity(polarity), Speed(speed), Pos(pos), bmp(size, Color(polarity)) { }
  
  
  void Horai::Move(double direction, Allegro::Bounds bounds) {
    this->Pos.Move(this->Speed, direction, bounds);
  }
  
  void Horai::DrawOn(const Allegro::Display& display) const {
    display.Draw(this->bmp, this->Pos);
  }
}
