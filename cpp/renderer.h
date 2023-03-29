#include <vector>
#include <iostream>
#include <thread>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   #define CLEAR "cls"
#elif __APPLE__
    #define CLEAR "clear"
#else
    #define CLEAR "clear"
#endif




//#include <windows.h>

namespace clyde {
    

    enum FPS {
        FPS_60 = 16,
        FPS_30 = 33,
        FPS_15 = 66,
        FPS_10 = 100,
        FPS_5 = 200,
        FPS_2 = 500,
        FPS_1 = 1000
    };    
    struct Object {
        int x;
        int y;
        char letter;
        Object(int x, int y, char letter) : x(x), y(y), letter(letter) {}
    };

    typedef std::vector<Object> object_list;
    /*
        STD::VECTOR< ... >{ 
            STD::VECTOR<OBJECT>{ OBJECT{}, OBJECT{}, OBJECT{} },
        }
    
    
    
    */

    class Renderer {
        private:
            object_list _objects;

        public:
            std::vector< std::vector<char> > frame;
            int width;
            int height;
            int fps;
            bool running=false;
            // pointer to frame variable
            std::vector< std::vector<char> > *frame_ptr = &frame;

            
            
            Renderer(int w, int h, FPS f) {
                // Initialize renderer
                // w = width
                // h = height
                // f = fps
                
                width = w;
                height = h;
                fps = f;
                // Initialize frame and clear frame
                this->frame = std::vector< std::vector<char> >(h, std::vector<char>(w));
                
                this->clear_frame();
                		
	        }
            int get_width() { return width; }
            int get_height() { return height; }
            
            void render(object_list objs) {
                this->prepare_objects(objs);
                this->prepare_frame(this->_objects);
                this->render_frame();
            }
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
                        return { {{0, 0, 'n'}} };
                }

                return  {{{0, 0, 'n'}}};
            }
            void clear_frame() {
                if (!this->frame.empty()) {
                    for (int y=0; y<=get_height()-1; y++) {
                        for (int x=0; x<=get_width()-1; x++) {
                            this->frame[y][x] = ' ';
                        }
                    }
                }
                
            }
            std::vector< std::vector<char> > prepare_frame(object_list objects) {
                // Prepare frame
                // Returns frame
                // You can use this function to prepare a frame but not show in CLI.

                // Clear frame
                this->clear_frame();
                if (!objects.empty()) {
                    for (int i=0; i<=objects.size(); i++) {
                
                        // use frame_ptr to set object at its position in frame variable
                        frame[objects[i].x][objects[i].y] = objects[i].letter;
                    
                    
                    }
                }
                
                return this->frame; 
            }
            void render_frame() {
                system(CLEAR);
                for (int y=0; y<height-1; y++) {
                    for (int x=0; x<width-1; x++) {
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
                for (int i=0; i<h; i++) {
                    for (int j=0; j<w; j++) {
                        rectangle.push_back({Object(x+j, y+i, 'B')});
                    }
                }

                return rectangle;
            }
            
            
    
    };
}
    
