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
            auto r = (int)(window.calculate_u_from_screen_x(x) * 255); 
            for (int y = 0; y < h; ++y) {
                window.SetDrawColor(r, 0, (int)(window.calculate_v_from_screen_y(y) * 255));
                window.DrawPoint(x, y); 

            }
        }
        window.Present();
        ++frame; 
    }
}
