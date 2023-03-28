#include "renderer.h"

#include <chrono>
//#include <thread>
#include <random>



int main() {

    clyde::RendererHandler ren(32, 32, clyde::FPS_60);
    clyde::object_list objects = {{'0', '1', 'A'}};
    std::chrono::milliseconds timespan(ren.fps); // 16ms = 60fps (16.6666ms ~ 60fps)

    

    while (true) {
        for (int i=1; i<=32; i++) {
            for (int j=1; j<=32; j++) {
                objects = {
                    // Top
                    {char(i-1 + '0'), char(j-1 + '0'), '<'}, //  Top left
                    {char(i-1 + '0'), char(j + '0'), '='}, //  Top
                    {char(i-1 + '0'), char(j+1 + '0'), '>'}, // Top right

                    // Center
                    {char(i + '0'), char(j-1 + '0'), '<'}, // Center left
                    {char(i + '0'), char(j + '0'), '='}, // Center
                    {char(i + '0'), char(j+1 + '0'), '>'}, // Center Right
                    // Botton
                    {char(i+1 + '0'), char(j-1 + '0'), '<'}, //  Bottom left
                    {char(i+1 + '0'), char(j + '0'), '='}, //  Bottom
                    {char(i+1 + '0'), char(j+1 + '0'), '>'}, // Bottom right

                };
                ren.render(objects);
                std::this_thread::sleep_for(timespan);
            }
        }


    }
    
    
    



    return 0;
}


