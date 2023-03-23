#include <vector>
#include <iostream>



    class Renderer {

        public:

            int width;
            int height;
            int fps;
           
            typedef std::vector< std::vector<char> > object_list;
            //std::vector< std::vector<char> > frame(10, std::vector<char>(10));
            // create vector of vector of chars with size 10x10
            std::vector< std::vector<char> > frame = std::vector< std::vector<char> >(10, std::vector<char>(10));

            Renderer(int w, int h, int f) {
                width = w;
                height = h;
                fps = f;
                // Initialize frame
                for (int y=0; y<h; y++) {
                    for (int x=0; x<=w; x++) {
                        
                            frame[y][x] = ' ';
                    }
                }
            }
            int get_width() { return width; }
            int get_height() { return height; }



            void prepare_frame(object_list objects) {
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
        
    };