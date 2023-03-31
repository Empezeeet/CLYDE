#include "renderer.h"
#include <chrono>

int main() {

    clyde::Renderer ren(64, 32, clyde::FPS_30);
    clyde::object_list objects = {{1, 0, 'A'}};
    std::chrono::milliseconds timespan(ren.fps);
    

    while (true) {
        for (int i=1; i<ren.get_height()-1; i++) {
            for (int j=1; j<ren.get_width()-1; j++) {
                
                // Render objects
                objects = ren.generate_shape(j, i, 3, 3, 'r');
                ren.prepare_frame(objects);
                ren.render_frame();
                std::this_thread::sleep_for(timespan);
            }
        }
    }
    
    return 0;
}


