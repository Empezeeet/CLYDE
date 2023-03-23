#include "renderer.h"
#include <chrono>
#include <thread>

using namespace std;

int main() {

    Renderer ren(10, 10, 5);
    Renderer::object_list objects = {{'0', '1', 'A'}};
	std::chrono::milliseconds timespan(100);
	
	ren.prepare_frame(objects);
    
    ren.render_frame();
    char cch;
    char cch2;
    for (int i=0; i<=10000; i++) {
        cch = 'a' + rand()%26;
        cch2 = 'a' + rand()%26;
        for (int i=0; i<8; i++) {
            cch2 = i + '0';
            objects = { {'5', cch2, 'B'} };
            ren.prepare_frame(objects);
            ren.render_frame();
            std::this_thread::sleep_for(timespan);
        }
        
    
        ren.render_frame();
        std::this_thread::sleep_for(timespan);
    }
    
    



    return 0;
}


