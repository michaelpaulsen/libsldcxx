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
using frame_count_t = uint64_t; 
const int w = 720, h = 480; 
int main()
{
    frame_count_t frame = 0; 
    //init all subsystems 
    SKC::SDLCXX::init_all_sdl_sub_systems(); 
    auto window = SDLXX::Window("test window", w, h); 
    SDL_Event e{};
    while (auto gamestate = env::PollEvents(e) != GameState::QUIT) {
        std::cout << gamestate << '\r';
        for (int x = 0; x < w; ++x) {
            for (int y = 0; y < h; ++y) {
                window.DrawPoint(x, y); 
                window.SetDrawColor(x % 255, frame % 255, y % 255);

            }
        }
        window.Present();
        ++frame; 
    }
}
