#ifndef __GAME_DIRECTION_HPP__
#define __GAME_DIRECTION_HPP__

#include <cmath>
#include <experimental/optional>


namespace Game {
  static inline std::experimental::optional<double> direction( // direction to radians
    const bool left,
    const bool up,
    const bool right,
    const bool down
  ) {
    return left || up || right || down
      ? std::atan2(
          (up ? 1 : 0) - (down ? 1 : 0),    // Δy
          (right ? 1 : 0) - (left ? 1 : 0)  // Δx
        )
      : std::experimental::optional<double>();
  }
  
  template<typename T, typename U>
  static inline std::experimental::optional<double> direction(const T& b1, const U& b2) {
    return b1.Pos == b2.Pos
      ? std::experimental::optional<double>()
      : std::atan2(
          b1.Pos.y - b2.Pos.y,    // y axis grows downwards.
          -(b1.Pos.x - b2.Pos.x)  // x axis grows forwards, but here we use it backwards.
        );                        // atan2 computes on the cartesian plane. To keep the
  }                               // direction correct, we reverse the x axys.
}

#endif /* __GAME_DIRECTION_HPP__ */
