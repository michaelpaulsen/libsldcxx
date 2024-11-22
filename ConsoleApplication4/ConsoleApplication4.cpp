// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <SDL3/SDL.h>
#include "./headers/Window.h"
//sdl stuff

static constexpr auto SDL_INIT_ALL = SDL_INIT_AUDIO | SDL_INIT_VIDEO
| SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC
| SDL_INIT_GAMEPAD | SDL_INIT_EVENTS
| SDL_INIT_SENSOR | SDL_INIT_CAMERA;



template <typename T> concept number = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <number T = int> struct vec2 {
    union {
        T x, w;
    };
    union { 
        T y, h;
    };
    //TODO implement len function
};

typedef vec2<int> vec2i; 
typedef vec2<float> vec2f;



struct rect_t {
    vec2i pos, size; 
};
enum class GameState {
    QUIT, 
    PLAYING,
    PAUSED, // don't render the screen. 
    MENUE, //the game is in pre-first game input state 
};
auto w_rect = rect_t{ 0,0,1920,1080 }; 
GameState PollEvents(SDL_Event& evnt) {
    while (SDL_PollEvent(&evnt)) {
        if(evnt.type == SDL_EVENT_QUIT) return GameState::QUIT;
        //TODO: delegate event to event dispach
    }

    return GameState::PLAYING;
}
int main()
{
    
    //init all subsystems 
    SDL_Init(SDL_INIT_ALL); 
   
    auto window = SKC::SDLCXX::Window("test window", 680, 480); 
        
        //SDL_CreateWindow("window title", w_rect.size.w, w_rect.size.h,0);
    SDL_Event e{};
    while (auto gamestate = PollEvents(e) != GameState::QUIT) {
        std::cout << gamestate << '\r';
    }
    std::cout << "Hello World!\n";
}
