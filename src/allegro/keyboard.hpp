#ifndef __ALLEGRO_KEYBOARD_HPP__
#define __ALLEGRO_KEYBOARD_HPP__

#include <functional>
#include <map>

#include <allegro5/allegro.h>


typedef int ALLEGRO_KEY;

namespace Allegro {
  class Keyboard {
  public:
    static void Install();
    static ALLEGRO_EVENT_SOURCE* EventSource();
    static void UpdateKeysState(
      const ALLEGRO_EVENT&,
      std::map<int, bool>& keys // map<keycode, pressed>
    );
    static void HandleKeyPress(
      const ALLEGRO_EVENT&,
      const std::map<int, std::function<void()>>& // map<keycode, action>
    );
  };
}

#endif /* __ALLEGRO_KEYBOARD_HPP__ */
