// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <SDL3/SDL.h>
#include "./headers/Window.h"
#include "./headers/SDL_CXX.h"
#include "./headers/events/events.h"

using GameState = SKC::SDLCXX::EVENTS::GameState;
namespace env = SKC::SDLCXX::EVENTS; 
namespace SDLXX = SKC::SDLCXX; 
int main()
{
    //init all subsystems 
    SKC::SDLCXX::init_all_sdl_sub_systems(); 
    auto window = SDLXX::Window("test window", 720, 480); 
    SDL_Event e{};
    while (auto gamestate = env::PollEvents(e) != GameState::QUIT) {
        std::cout << gamestate << '\r';
    }
}
