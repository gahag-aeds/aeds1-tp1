#ifndef __ALLEGRO_EVENT_QUEUE_HPP__
#define __ALLEGRO_EVENT_QUEUE_HPP__

#include <memory>

#include <allegro5/allegro.h>


namespace Allegro {
  class EventQueue {
  public:
    EventQueue();
    
    template<typename T> void Register(const T& r);
    template<typename T> void Register();
    
    ALLEGRO_EVENT AwaitEvent() const;
    
  private:
    const std::shared_ptr<ALLEGRO_EVENT_QUEUE> queue;
  };
  
  
  template<>
  inline void EventQueue::Register(ALLEGRO_EVENT_SOURCE* const& source) {
    al_register_event_source(this->queue.get(), source);
  }
  
  template<typename T>
  inline void EventQueue::Register(const T& r) {
    this->Register(r.EventSource());
  }
  
  template<typename T>
  inline void EventQueue::Register() {
    this->Register(T::EventSource());
  }
}

#endif /* __ALLEGRO_EVENT_QUEUE_HPP__ */
