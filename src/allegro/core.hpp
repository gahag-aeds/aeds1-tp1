#ifndef __ALLEGRO_HPP__
#define __ALLEGRO_HPP__

#include <functional>
#include <map>

#include <allegro5/allegro.h>


namespace Allegro {
  void Init();  // Initiates the framework.
                // This must be called before any other framework function.
  
  void Rest(const double seconds); // Sleep during the specified time.
  
  void HandleEvent(
    const ALLEGRO_EVENT&,
    const std::map<ALLEGRO_EVENT_TYPE, std::function<void()>>&
  );
}

#endif /* __ALLEGRO_HPP__ */
