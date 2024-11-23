#pragma once
#include <SDL3/SDL.h>
namespace SKC::SDLCXX {
	namespace EVENTS {
		using event_t = SDL_Event; 
		enum class GameState {
			QUIT,
			PLAYING,
			PAUSED, // don't render the screen. 
			MENUE, //the game is in pre-first game input state 
		};
		GameState PollEvents(SDL_Event& evnt) {
			while (SDL_PollEvent(&evnt)) {
				if (evnt.type == SDL_EVENT_QUIT) return GameState::QUIT;
				//TODO: delegate event to event dispach
			}

			return GameState::PLAYING;
		}
	
	}
	namespace evnt = EVENTS;

}