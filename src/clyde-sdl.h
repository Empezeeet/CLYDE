#include <SDL2/SDL.h>
#include "clyde.h"
#include "main.cpp"
namespace clydeSDL {

    class CSDL {
        // CLYDE-SDL Handler class
        private:
            unsigned int window_width;
            unsigned int window_height;
            std::string window_title;
            clyde::FPS fps;
            clyde::Renderer CRenderer;

        public:
            // constructor
            CSDL(unsigned int width, unsigned int height, clyde::FPS fps, std::string title) {
                
                // variables
                this->window_width = width;
                this->window_height = height;
                this->fps = fps;
                this->window_title = title;
                
                // CLYDE

                this->CRenderer = clyde::Renderer(width, height, fps);
                



                // SDL2
                if (SDL_Init(SDL_INIT_VIDEO) != 0) {
                    SDL_Log("Nie można zainicjować biblioteki SDL2: %s", SDL_GetError());
                    throw "SDL2 init error";
                }
                if (initializeWindow() == false) {
                    throw "SDL2 window init error";
                }

                
            }
        private:
            bool initializeWindow() {
                SDL_Window* window = SDL_CreateWindow(
                    this->window_title,               // Tytuł okna
                    SDL_WINDOWPOS_CENTERED,           // Pozycja X
                    SDL_WINDOWPOS_CENTERED,           // Pozycja Y
                    this->window_width,               // Szerokość okna
                    this->window_height,              // Wysokość okna
                    SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL // Flagi okna
                );
                if (window == nullptr) {
                    SDL_Log("Nie można utworzyć okna: %s", SDL_GetError());
                    SDL_Quit();
                    return false;
                }
                return true;
            }
            void mainloop() {
                // Główna pętla zdarzeń
                SDL_Event event;
                bool quit = false;
                while (!quit) {
                    while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) {
                            quit = true;
                        }
                    }
                    // Tutaj można umieścić kod rysujący na ekranie

                    SDL_Delay(16); // Ograniczenie liczby klatek na sekundę
                }

                // Zniszczenie okna i wyjście z programu
                SDL_DestroyWindow(window);
                SDL_Quit();
            }
    };
}







int main(int argc, char* argv[]) {
    
    return 0;
}