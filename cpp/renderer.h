#include <vector>
#include <iostream>
#include <thread>

//#include <windows.h>

namespace clyde {
    
    enum FPS {
        FPS_60 = 16,
        FPS_30 = 33,
        FPS_15 = 66,
        FPS_10 = 100,
        FPS_5 = 200,
        FPS_1 = 1000
    };    
    class Renderer {

        public:
            typedef std::vector< std::vector<char> > object_list;
            std::vector< std::vector<char> > frame;
            int width;
            int height;
            int fps;
            bool running=false;
            object_list _objects;



            
            
            Renderer(int w, int h, FPS f) {
                // Initialize renderer
                // w = width
                // h = height
                // f = fps
                
                width = w;
                height = h;
                fps = f;
                // Initialize frame and clear frame
                frame = std::vector< std::vector<char> >(h, std::vector<char>(w));
                
                for (int y=0; y<h; y++) {
                    for (int x=0; x<=w; x++) {
                        frame[y][x] = ' ';
                    }
                }
                // Run mainloop thread

               this->run();
		
	        }
            int get_width() { return width; }
            int get_height() { return height; }
            
            void run() {
                this->running = true;
                // run mainloop functions in new thread
                std::thread t(&Renderer::mainloop, this, 'a');
            }
            void stop() {
                this->running = false;
            }

            void prepare_objects(object_list objects) {
                this->_objects = objects;
            }
            std::vector< std::vector<char> > prepare_frame(object_list objects) {
                // Prepare frame
                // Returns frame
                // You can use this function to prepare a frame but not show in CLI.

                // Clear frame
                for (int y=0; y<get_height(); y++) {
                    for (int x=0; x<get_width(); x++) {
                        frame[y][x] = ' ';
                    }
                }
                for (int i=0; i<objects.size(); i++) {
                    // Object: {'0', '1', 'A'}
                    frame[ int(objects[i][0] - '0') ][ int(objects[i][1] - '0') ]  = objects[i][2];
                }
                return frame;
            }
            void render_frame() {
                system("cls");
                for (int y=0; y<height; y++) {
                    for (int x=0; x<width; x++) {
                        std::cout << this->frame[y][x];
                    }
                    std::cout << std::endl;
                }
            }
            



            object_list generate_shape(int x, int y, int w, int h, char c) {
                // Generate a shape
                // x = x position
                // y = y position
                // w = width
                // h = height
                // c = type of shape:
                //    - 'r' = rectangle
                //    - 't' = triangle
                //    - 'c' = circle
                // Returns object_list with shape
                // Returns { {'n'} } when shape is not recognized
                object_list shape;
                switch (c) {
                    case 'r':
                        return this->generate_rectangle(x, y, w, h);
                    default:
                        return { {'n'} };
                }

                return { {'n'} };
            }
            private: 
                void mainloop(char dummy) {   
                    while (this->running) {
                        prepare_frame(this->_objects);
                        render_frame();
                        std::this_thread::sleep_for(std::chrono::milliseconds(this->fps));
                    
                    }
                }
                object_list generate_rectangle(int x, int y, int w, int h) {
                    // x: x of top left corner
                    // y: y of top left corner
                    // w: width
                    // h: height
                    object_list rectangle;
                    rectangle.push_back({ char(x + '0'), char(y + '0'), 'A' });
                    for (int i=0; i<h; i++) {
                        
                        for (int j=0; j<w; j++) {
                            rectangle.push_back({ char(x + j + '0'), char(y + i + '0'), 'B' });
                        }
                    }

                    return rectangle;
                }
                
                
        
    };
}
    
