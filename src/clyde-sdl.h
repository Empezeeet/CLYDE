#include <SDL2/SDL.h>
#include "clyde-rgb.h"
#include <string>
namespace clydeSDL {

    class CSDL {
        // CLYDE-SDL Handler class
        private:
            unsigned int window_width;
            unsigned int window_height;
            clyde::FPS fps;
            
            clyde::Frame window_frame;
            clyde::Renderer *CRenderer;
            

        public:
            SDL_Window* window;
            SDL_Renderer *render;
            CSDL(unsigned int width, unsigned int height, clyde::FPS fps) {
                
                // variables
                this->window_width = width;
                this->window_height = height;
                this->fps = fps;
                
                // CLYDE

                //clyde::Renderer Renderer(width, height, fps);
                this->CRenderer = new clyde::Renderer(width, height, fps);
                this->CRenderer->clear_frame();



                // SDL2
                if (SDL_Init(SDL_INIT_VIDEO) != 0) {
                    SDL_Log("Nie można zainicjować biblioteki SDL2: %s", SDL_GetError());
                    throw "SDL2 init error";
                }
                if (initializeWindow() == false) {
                    throw "SDL2 window init error";
                }             
                this->mainloop();   
            }
            void userTasks() {

               // SDL_SetRenderDrawColor(this->render, 255, 255, 255, 255);
                //SDL_RenderDrawLine(this->render, 0, 0, 640, 480);




            }
        private:
            bool initializeWindow() {
                this->window = SDL_CreateWindow(
                    "CSDL-DEMO",                      // Tytuł okna
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
            void initRender() {
                this->render = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
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
                    this->userTasks();




                    if (SDL_RenderPresent(this->render) != 0) {
                    }
                    SDL_Delay(this->fps); // Ograniczenie liczby klatek na sekundę
                }

                // Zniszczenie okna i wyjście z programu
                SDL_DestroyWindow(window);
                SDL_Quit();
            }
            
    };
}







