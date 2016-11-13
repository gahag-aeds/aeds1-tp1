#include <fstream>
#include <stdexcept>

#include <game/score.hpp>


namespace Game {
  unsigned loadScore() {
    std::fstream fstream(scoreFile);
    
    unsigned score = 0;
    
    fstream >> score;
    
    if (fstream.fail())
      throw std::runtime_error("Failed to load score from " + std::string(scoreFile));
    
    return score;
  }
  
  void saveScore(unsigned score) {
    std::ofstream fstream(scoreFile, std::ofstream::out);
    
    fstream << score << std::endl;
    
    if (fstream.fail())
      throw std::runtime_error("Failed to save score to " + std::string(scoreFile));
  }
}
