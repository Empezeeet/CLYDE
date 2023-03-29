#include <vector>

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
    struct Color {
        unsigned char r=255;
        unsigned char g=255;
        unsigned char b=255;
        Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}
    };
   
    struct Object {
        int x;
        int y;
        Color color;
        Object(int x, int y, Color color) : x(x), y(y), color(color) {}
    };
    typedef std::vector< std::vector<Color> > Frame;
    typedef std::vector<Object> object_list;

    class Renderer {
        private:
            object_list _objects;

        public:
            Frame frame;
            int width;
            int height;
            int fps;
            bool running=false;
            // pointer to frame variable
            Frame *frame_ptr = &frame;

            
            
            Renderer(int w, int h, FPS f) {
                // Initialize renderer
                // w = width
                // h = height
                // f = fps
                
                width = w;
                height = h;
                fps = f;
                // Initialize frame and clear frame
                this->frame = std::vector< std::vector<Color> >(h, std::vector<Color>(w));
                
                this->clear_frame();
                		
	        }
            int get_width() { return this->width; }
            int get_height() { return this->height; }
            
            
            
            object_list generate_shape(int x, int y, int w, int h, char c, Color color) {
                /* Generate a shape
                // x = x position
                // y = y position
                // w = width
                // h = height
                // c = type of shape:
                //    - 'r' = rectangle
                //    - 't' = triangle // doesn't work yet
                //    - 'c' = circle // doesn't work yet
                // color = color of shape (RGB)
                // Returns object_list with shape
                // Returns { {'n'} } when shape is not recognized
                */
                object_list shape;
                switch (c) {
                    case 'r':
                        return this->generate_rectangle(x, y, w, h, color);
                    default:
                        return { {{0, 0, {255, 255, 255}}} };
                }

                return  {{{0, 0, {255, 255, 255}}}};
            }
            void clear_frame() {
                if (!this->frame.empty()) {
                    for (int y=0; y<=get_height()-1; y++) {
                        for (int x=0; x<=get_width()-1; x++) {
                            this->frame[y][x] = Color(0, 0, 0);
                        }
                    }
                }
                
            }
            Frame prepare_frame(object_list objects) {
                // Prepare frame
                // Returns frame
                // You can use this function to prepare a frame but not show in CLI.

                // Clear frame
                this->clear_frame();
                if (!objects.empty()) {
                    for (int i=0; i<=objects.size(); i++) {
                
                        // use frame_ptr to set object at its position in frame variable
                        if (objects[i].x > this->get_width()-1) continue;
                        if (objects[i].y > this->get_height()-1) continue;

                        //frame[objects[i].x][objects[i].y] = objects[i].letter;
                        // do the same like above but using frame pointer
                        this->frame_ptr->at(objects[i].y).at(objects[i].x) = objects[i].color;
                    
                    }
                }
                
                return this->frame; 
            }
             
            void prepare_objects(object_list objects) {
                this->_objects = objects;
            }
        
        private:  
                   
            object_list generate_rectangle(int x, int y, int w, int h, Color color) {
                // x: x of top left corner
                // y: y of top left corner
                // w: width
                // h: height
                
                object_list rectangle;
                for (int i=0; i<h; i++) {
                    for (int j=0; j<w; j++) {
                        if (x+j > width-1) continue;
                        if (y+i > height-1) continue;
                        rectangle.push_back({Object(x+j, y+i, color)});
                    }
                }

                return rectangle;
            }
            
            
    
    };
}
    
