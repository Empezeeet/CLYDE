#include "renderer.h"
#include <chrono>
#include <random>



int main() {

    clyde::Renderer ren(32, 32, clyde::FPS_30);
    clyde::object_list objects = {{1, 0, 'A'}};
    std::chrono::milliseconds timespan(ren.fps);
    

    while (true) {
        for (int i=1; i<ren.get_height()-1; i++) {
            for (int j=1; j<ren.get_width()-1; j++) {
                
                // Fill objects with objects that are specified above (in comment)
                objects = {
                    clyde::Object(i-1, j-1, '<'), //  Top left
                    clyde::Object(i-1, j, '='), //  Top
                    clyde::Object(i-1, j+1, '>'), // Top right

                    clyde::Object(i, j-1, '<'), // Center left
                    clyde::Object(i, j, char(i + '0')), // Center
                    clyde::Object(i, j+1, '>'), // Center Right

                    clyde::Object(i+1, j-1, '<'), //  Bottom left
                    clyde::Object(i+1, j, '='), //  Bottom
                    clyde::Object(i+1, j+1, '>'), // Bottom right
                };
                
                // Render objects

                ren.prepare_frame(objects);
                ren.render_frame();
                std::this_thread::sleep_for(timespan);
            }
        }


    }
    
    
    



    return 0;
}


