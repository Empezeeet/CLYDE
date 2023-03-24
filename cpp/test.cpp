#include "renderer.h"
#include <chrono>
#include <thread>
#include <random>



using namespace std;

int main() {

    clyde::Renderer ren(64, 64, 5);
    clyde::Renderer::object_list objects = {{'0', '1', 'A'}};
    clyde::Renderer::object_list floor = {{'0', '1', 'A'}};
    std::chrono::milliseconds timespan(16);
    
    ren.prepare_frame(objects);
    
    ren.render_frame();

    

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
                ren.prepare_frame(objects);
                ren.render_frame();
                std::this_thread::sleep_for(timespan);
            }
        }


    }
    
    
    



    return 0;
}


