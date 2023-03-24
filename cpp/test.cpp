#include "renderer.h"
#include <chrono>
#include <thread>
#include <random>

using namespace std;

int main() {

    clyde::Renderer ren(10, 10, 5);
    clyde::Renderer::object_list objects = {{'0', '1', 'A'}};
    clyde::Renderer::object_list floor = {{'0', '1', 'A'}};
	std::chrono::milliseconds timespan(100);
	
	ren.prepare_frame(objects);
    
    ren.render_frame();

    for (int b=0; b<=10000; b++) {

        objects = ren.generate_shape(1 + (rand() % static_cast<int>(3 - 1 + 1)), 1 + (rand() % static_cast<int>(3 - 1 + 1)), 3, 3, 'r');
        floor = ren.generate_shape(9, 9, 5, 1, 'r');
        objects.insert(end(objects), begin(floor), end(floor));
        ren.prepare_frame(objects);
        ren.render_frame();
        std::this_thread::sleep_for(timespan);


    }
    
    



    return 0;
}


