#ifndef __GAME_SCORE_HPP__
#define __GAME_SCORE_HPP__

#include <string>


namespace Game {
  constexpr char scoreFile[] = "score.dat";
  
  unsigned loadScore();
  void saveScore(unsigned score);
}

#endif /* __GAME_SCORE_HPP__ */
