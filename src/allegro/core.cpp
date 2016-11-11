#include <stdexcept>

#include <allegro/core.hpp>


namespace Allegro {
  void Init() {
    if (!al_init())
      throw std::runtime_error("failed to initialize allegro");
  }
  
  void Rest(double seconds) {
    al_rest(seconds);
  }
  
  void HandleEvent(
    const ALLEGRO_EVENT& ev,
    const std::map<ALLEGRO_EVENT_TYPE, std::function<void()>>& handlers
  ) {
    auto handler = handlers.find(ev.type);
    if (handler != handlers.end())
      handler->second();
  }
}
