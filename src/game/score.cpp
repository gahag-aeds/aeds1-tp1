#include <fstream>

#include <game/score.hpp>


namespace Game {
  unsigned loadScore() {
    std::fstream fstream(scoreFile);
    
    unsigned score = 0;
    
    fstream >> score;
    
    return score;
  }

  void saveScore(unsigned score) {
    std::ofstream fstream(scoreFile, std::ofstream::out);
    
    fstream << score << std::endl;
  }
}
