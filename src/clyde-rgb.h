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
    struct Clr {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        Clr(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}
        Clr() = default;
    };
   
    struct Object {
        int x;
        int y;
        Clr clr;
        Object(int x, int y, Clr clr) : x(x), y(y), clr(clr) {}
    };
    typedef std::vector< std::vector<Clr> > Frame;
    typedef std::vector<Object> object_list;

    class Renderer {
        
        private:
            object_list _objects;

        public:
            Frame frame;
            int width;
            int height;
            int fps;
            // pointer to frame variable
            Frame *frame_ptr = &frame;
            Renderer();
            Renderer(int w, int h, FPS f) {
                // Initialize renderer
                // w = width
                // h = height
                // f = fps
                
                this->width = w;
                this->height = h;
                this->fps = f;
                // Initialize frame and clear frame
                this->frame = std::vector< std::vector<Clr> >(h, std::vector<Clr>(w));
                
                this->clear_frame();	
	        }
            
            
            
            int get_width() { return this->width; }
            int get_height() { return this->height; }
            
            
            
            object_list generate_shape(int x, int y, int w, int h, char c, Clr clr) {
                /* Generate a shape
                // x = x position
                // y = y position
                // w = width
                // h = height
                // c = type of shape:
                //    - 'r' = rectangle
                //    - 't' = triangle // doesn't work yet
                //    - 'c' = circle // doesn't work yet
                // clr = clr of shape (RGB)
                // Returns object_list with shape
                // Returns { {'n'} } when shape is not recognized
                */
                object_list shape;
                switch (c) {
                    case 'r':
                        return this->generate_rectangle(x, y, w, h, clr);
                    default:
                        return { Object(-1, -1, Clr(0, 0, 0))};
                }

                return { Object(-1, -1, Clr(0, 0, 0))};
            }
            Frame test_frame() {
                // generates test frame
                // return frame with rectangle (width /4 x height /4)
                this->clear_frame();
                this->frame = this->prepare_frame(this->generate_shape(0, 0, this->width/4, this->height/4, 'r', Clr(255, 255, 255)));
                return this->frame;
            }
            
            
            
            
            void clear_frame() {
                if (!this->frame.empty()) {
                    for (int y=0; y<=get_height()-1; y++) {
                        for (int x=0; x<=get_width()-1; x++) {
                            this->frame[y][x] = Clr(0, 0, 0);
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
                        this->frame_ptr->at(objects[i].y).at(objects[i].x) = objects[i].clr;
                    
                    }
                }
                
                return this->frame; 
            }
             
            void prepare_objects(object_list objects) {
                this->_objects = objects;
            }
        
        private:  
                   
            object_list generate_rectangle(int x, int y, int w, int h, Clr clr) {
                // x: x of top left corner
                // y: y of top left corner
                // w: width
                // h: height
                
                object_list rectangle;
                for (int i=0; i<h; i++) {
                    for (int j=0; j<w; j++) {
                        if (x+j > width-1) continue;
                        if (y+i > height-1) continue;
                        rectangle.push_back(Object(x+j, y+i, clr));
                    }
                }

                return rectangle;
            }
            
            
    
    };
}
    
