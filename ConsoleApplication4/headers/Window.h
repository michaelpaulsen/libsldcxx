#pragma once

#include <string_view>
#include <format>
#include <iostream> 
#include <cstdint>

#include <SDL3/SDL.h>
//prob don't need all of SDL in this file...

namespace SKC::SDLCXX {
	class Window {
	public:
		using winuid_t = size_t;
		static constexpr int DEFAULT_WIDTH = 1080;
		static constexpr int DEFAULT_HEIGHT = 720;

		Window() = delete;
		explicit Window(std::string_view name, int w, int h, uint64_t flags = 0) :
			m_name{ name },
			m_uid{ NEXT_WINDOW_UID++ },
			m_window{ SDL_CreateWindow(name.data(), w, h, flags) },
			m_renderer{ SDL_CreateRenderer(m_window, 0) },
			m_flags{ flags }
		{ }
		//NOTE the order the members are listed here doen't matter they always will be initilized in the 
		//order that they are in the class... 
		//this means that m_renderer always must be below m_window in the private section



		//NOTE if you're needing to move or copy a window then you are most likely doing something wrong

		Window(Window&) = delete;
		Window(Window&&) = delete;
		
		Window operator = (Window&) = delete; 
		Window operator = (Window&&) = delete;
		
		[[nodiscard]] auto flags() const {
			return m_flags; 
		}
		[[nodiscard(
"copying strings is expencive you shouldn't"\
"be requesting the name if it is not used"\
"possible fix moving call to name inside if block it is used in"
)]] auto name() const {
			return m_name; 
		}
		void SetDrawColor(uint8_t r, uint8_t g, uint8_t b) {
			SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
		}
		void DrawPoint(float x, float y) {
			SDL_RenderPoint(m_renderer, x, y);
		}
		void Present() {
			SDL_RenderPresent(m_renderer); 
		}
		
		~Window() {
			SDL_DestroyRenderer(m_renderer); 
			SDL_DestroyWindow(m_window);
		}
	private:
		winuid_t m_uid; 
		std::string m_name;
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		uint64_t m_flags;
		//STATICS 
		// 
		//this is the UID for the next window 
		//it is automatically incremented on window creation
		inline static winuid_t NEXT_WINDOW_UID = 0;
		
	public :
		//HACK this may not whant to be const ... you can change a non-zero amount of the 
		//window flags but since I don't plan to expose an API to change window flags for now
		//this is fine to be const
	};
	
}