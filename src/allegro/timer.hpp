#ifndef __ALLEGRO_TIMER_HPP__
#define __ALLEGRO_TIMER_HPP__

#include <functional>
#include <memory>

#include <allegro5/allegro.h>


namespace Allegro {
  class Timer {
  public:
    Timer(const double freq); // seconds per tick. Throws runtime_error on failure.
    
    void Start() const;
    
    void OnElapse(const ALLEGRO_EVENT&, const std::function<void()>&);
    
    int64_t Count() const;
    
    ALLEGRO_EVENT_SOURCE* EventSource() const;
    
  private:
    const std::shared_ptr<ALLEGRO_TIMER> timer;
  };
}

#endif /* __ALLEGRO_TIMER_HPP__ */
