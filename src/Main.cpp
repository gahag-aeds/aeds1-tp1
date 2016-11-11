#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <exception>

#include <allegro/color.hpp>
#include <allegro/core.hpp>
#include <allegro/display.hpp>
#include <allegro/eventqueue.hpp>
#include <allegro/font.hpp>
#include <allegro/keyboard.hpp>
#include <allegro/position.hpp>
#include <allegro/timer.hpp>

#include <game/horai.hpp>
#include <game/score.hpp>
#include <game/ikaruga.hpp>


constexpr unsigned FPS = 60
                 , IkarugaSpeed = 5
                 , HoraiSpeed   = 3;

constexpr Allegro::Size ScreenSize(1200, 800);
constexpr Allegro::Size IkarugaSize(32, 32);
constexpr Allegro::Size HoraiSize(20, 20);


void spawnHorai(std::list<Game::Horai>& enemies, Allegro::Position position) {
  enemies.push_back(
    Game::Horai(
      HoraiSize,
      Game::RandomPolarity(),
      HoraiSpeed,
      position
    )
  );
}


auto main() -> int {
  try {
    Allegro::Init();
    Allegro::Font::Init();
    Allegro::Keyboard::Install();
    
    Allegro::Font       size32("arial.ttf", 32);
    Allegro::Timer      timer(1.0 / FPS);
    Allegro::EventQueue eventQueue;
    Allegro::Display    display(ScreenSize, Allegro::Color::Black());
    
    
    Game::Ikaruga ikaruga(
      IkarugaSize,
      Game::Polarity::Green,
      IkarugaSpeed,
      (display.Size.Center - IkarugaSize.Center).Map(
        [](auto x, auto y) { return Allegro::Position(x, y * 2); }
      )
    );
    
    std::list<Game::Horai> enemies;
    
    
    bool playing = true;
    
    
    std::map<ALLEGRO_KEY, bool> movementKeys =
      { { ALLEGRO_KEY_W, false }, { ALLEGRO_KEY_UP,    false }
      , { ALLEGRO_KEY_A, false }, { ALLEGRO_KEY_LEFT,  false }
      , { ALLEGRO_KEY_S, false }, { ALLEGRO_KEY_DOWN,  false }
      , { ALLEGRO_KEY_D, false }, { ALLEGRO_KEY_RIGHT, false } };
    
    std::map<ALLEGRO_KEY, std::function<void()>> actionKeys =
      { { ALLEGRO_KEY_SPACE,  [&] { ikaruga.Flip();  } }
      , { ALLEGRO_KEY_ESCAPE, [&] { playing = false; } } };
    
    std::map<ALLEGRO_EVENT_TYPE, std::function<void()>> displayEvents =
      { { ALLEGRO_EVENT_DISPLAY_CLOSE, [&] { playing = false; } } };
    
    
    eventQueue.Register(display);
    eventQueue.Register(timer);
    eventQueue.Register<Allegro::Keyboard>();   
    
    display.Invalidate();
    
    timer.Start();
    
    
    while(playing) {
      auto ev = eventQueue.AwaitEvent();
      
      Allegro::Keyboard::UpdateKeysState(ev, movementKeys);
      Allegro::Keyboard::HandleKeyPress(ev, actionKeys);
      Allegro::HandleEvent(ev, displayEvents);
      
      timer.OnElapse(
        ev,
        [&] {
          display.Clear();
          
          auto ikarugaDirection = Game::direction(
            movementKeys[ALLEGRO_KEY_A] || movementKeys[ALLEGRO_KEY_LEFT],
            movementKeys[ALLEGRO_KEY_W] || movementKeys[ALLEGRO_KEY_UP],
            movementKeys[ALLEGRO_KEY_D] || movementKeys[ALLEGRO_KEY_RIGHT],
            movementKeys[ALLEGRO_KEY_S] || movementKeys[ALLEGRO_KEY_DOWN]
            );
          
          if (ikarugaDirection)
            ikaruga.Move(
              ikarugaDirection.value(),
              display.Size.Bounds.Reduce(ikaruga.Size)
            );
          
          ikaruga.DrawOn(display);
          
          
          // Spawn a horai each second, max 15.
          if (timer.Count() % 60 == 0 && enemies.size() <= 15) {
            // Spawn at random position:
            auto pos = display.Size.Bounds.Reduce(HoraiSize).RandomPos();
            
            // Prevent spawning too close:
            while ((pos - ikaruga.Pos).In(Allegro::Size(200, 200).Bounds))
              pos = display.Size.Bounds.Reduce(HoraiSize).RandomPos();
            
            spawnHorai(enemies, pos);
          }
          
          for (auto horai = enemies.begin(); horai != enemies.end(); /* no increment */) {
            if (ikaruga.Collide(*horai)) {
              if (!ikaruga.Alive()) {
                playing = false;
                break;
              }
              
              horai = enemies.erase(horai);
              continue;
            }
            
            auto horaiDirection = ikaruga.Polarity() == horai->Polarity
                                ? Game::direction(ikaruga, *horai)  // move away.
                                : Game::direction(*horai, ikaruga); // move to the ikaruga.
            
            if (horaiDirection)
              horai->Move(
                horaiDirection.value(),
                display.Size.Bounds.Reduce(horai->Size)
              );
            
            horai->DrawOn(display);
            
            horai++;
          }
          
          display.SetTitle("Score: " + std::to_string(ikaruga.Score()));
          
          display.Invalidate();
        }
      );
    }
    
    // End game:
    
    display.Clear();
    
    
    unsigned record = Game::loadScore();
    std::stringstream ss;
    
    if (ikaruga.Score() > record) {
      ss << "New record! ";
      record = ikaruga.Score();
      Game::saveScore(record);
    }
    
    ss << "Score: "     << ikaruga.Score()
       << " / Record: " << record;
    
    display.Draw(ss.str(), size32, Allegro::Color::Green(), display.Size.Center);
    
    
    display.Invalidate();
    
    Allegro::Rest(3);
  }
  catch (std::exception err) {
    std::cerr << err.what();
    return -1;
  }
  
  return 0;
}
