#include <stdexcept>

#include <allegro/timer.hpp>


namespace Allegro {
  Timer::Timer(double freq) : timer(al_create_timer(freq), al_destroy_timer) {
    if (!this->timer)
      throw std::runtime_error("failed to initialize timer");
  }

  
  void Timer::Start() const {
    al_start_timer(this->timer.get());
  }
  
  void Timer::OnElapse(const ALLEGRO_EVENT& ev, const std::function<void()>& fn) {
    if (ev.type == ALLEGRO_EVENT_TIMER)
      fn();
  }
  
  int64_t Timer::Count() const {
    return al_get_timer_count(this->timer.get());
  }

  ALLEGRO_EVENT_SOURCE* Timer::EventSource() const {
    return al_get_timer_event_source(this->timer.get());
  }
}
