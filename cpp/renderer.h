#include <vector>
#include <iostream>


namespace clyde {
    
    
    
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
                // Initialize renderer
                // w = width
                // h = height
                // f = fps
                
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
                    case 't':
                        return this->generate_triangle(x, y, w, h);
                    case 'c':
                        return this->generate_circle(x, y, w, h);
                    default:
                        return { {'n'} };
                }

                return { {'n'} };
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
                object_list generate_triangle(int x, int y, int w, int h) {
                    object_list triangle;


                    return triangle;
                }
                object_list generate_circle(int x, int y, int w, int h) {
                    object_list circle;

                    return circle;
                }
                
        
    };
}
    