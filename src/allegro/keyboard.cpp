#include <stdexcept>

#include <allegro/keyboard.hpp>


namespace Allegro {
  void Keyboard::Install() {
    if (!al_install_keyboard())
      throw std::runtime_error("failed to install keyboard driver");
  }
  
  ALLEGRO_EVENT_SOURCE* Keyboard::EventSource() {
    return al_get_keyboard_event_source();
  }
  
  void Keyboard::UpdateKeysState(const ALLEGRO_EVENT& ev, std::map<int, bool>& keys) {
    if (ev.type != ALLEGRO_EVENT_KEY_DOWN && ev.type != ALLEGRO_EVENT_KEY_UP)
      return;
    
    auto key = keys.find(ev.keyboard.keycode);
    if (key != keys.end())
      key->second = ev.type == ALLEGRO_EVENT_KEY_DOWN;
  }
  
  void Keyboard::HandleKeyPress(
    const ALLEGRO_EVENT& ev,
    const std::map<int, std::function<void()>>& handlers
  ) {
    if (ev.type != ALLEGRO_EVENT_KEY_DOWN)
      return;
    
    auto handler = handlers.find(ev.keyboard.keycode);
    if (handler != handlers.end())
      handler->second();
  }
}
