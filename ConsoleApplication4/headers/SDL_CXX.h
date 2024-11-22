#pragma once
namespace SKC::SDLCXX {
	static constexpr auto SDL_INIT_ALL = SDL_INIT_AUDIO | SDL_INIT_VIDEO
		| SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC
		| SDL_INIT_GAMEPAD | SDL_INIT_EVENTS
		| SDL_INIT_SENSOR | SDL_INIT_CAMERA;
	void init_all_sdl_sub_systems() {
		SDL_Init(SKC::SDLCXX::SDL_INIT_ALL);
	}

}