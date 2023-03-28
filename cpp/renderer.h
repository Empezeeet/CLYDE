#include <vector>
#include <iostream>
#include <thread>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   #define CLEAR "cls"
#elif __APPLE__
    #define CLEAR "clear"
#elif __linux__
    #define CLEAR "clear"
#elif __unix__ // all unices not caught above
    #define CLEAR "clear"
#endif




//#include <windows.h>

namespace clyde {
    typedef std::vector< std::vector<char> > object_list;

    enum FPS {
        FPS_60 = 16,
        FPS_30 = 33,
        FPS_15 = 66,
        FPS_10 = 100,
        FPS_5 = 200,
        FPS_1 = 1000
    };    
    




    class Renderer {
        private:
            object_list _objects;

        public:
            std::vector< std::vector<char> > frame;
            int width;
            int height;
            int fps;
            bool running=false;


            
            
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
                		
	        }
            int get_width() { return width; }
            int get_height() { return height; }
            

            void prepare_objects(object_list objects) {
                this->_objects = objects;
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
                system(CLEAR);
                for (int y=0; y<height; y++) {
                    for (int x=0; x<width; x++) {
                        std::cout << this->frame[y][x];
                    }
                    std::cout << std::endl;
                }
            }  
        private:

                          
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

    class RendererHandler {
        private:
            Renderer ren; 
        public:
            int width;
            int height;
            FPS fps;
            
            RendererHandler(int w, int h, FPS f) : ren(w, h, f) {
                this->width = w;
                this->height = h;
                this->fps = f;

            }
            

            void render(object_list objects) {
                ren.prepare_objects(objects);
                ren.prepare_frame(objects);
                ren.render_frame();
            }

    };  


}
    
