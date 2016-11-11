#ifndef __GAME_PHYSICS_HPP__
#define __GAME_PHYSICS_HPP__

namespace Game {
  template<typename T, typename U>
  constexpr bool rectCollision(const T& b1, const U& b2) {
      return b1.Pos.x                 <= b2.Pos.x + b2.Size.Width
          && b1.Pos.x + b1.Size.Width >= b2.Pos.x
          
          && b1.Pos.y                  <= b2.Pos.y + b2.Size.Height
          && b1.Pos.y + b1.Size.Height >= b2.Pos.y;
  }
}

#endif /* __GAME_PHYSICS_HPP__ */
