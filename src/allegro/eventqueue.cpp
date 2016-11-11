#include <stdexcept>

#include <allegro/eventqueue.hpp>


namespace Allegro {
  EventQueue::EventQueue() : queue(al_create_event_queue(), al_destroy_event_queue) {
    if (!this->queue)
      throw std::runtime_error("failed to create event queue");
  }
  
  
  ALLEGRO_EVENT EventQueue::AwaitEvent() const {
    ALLEGRO_EVENT e;
    
    al_wait_for_event(this->queue.get(), &e);
    
    return e;
  }
}
