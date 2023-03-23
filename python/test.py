import python.main as main
import random
import time
import sys

renderer = main.Render(width=20, height=10, fps=5)


# Full list of random objects for test
objects = [ 
    (1, 5, "A", (255, 12, 102)),
    (2, 3, "B", (52, 255, 255)),
    (3, 4, "C", (255, 255, 65)),
    (4, 5, "D", (255, 255, 255)),
    (5, 6, "E", (255, 52, 255)),
    (6, 7, "F", (0, 0, 0)),
    (7, 8, "G", (5, 5, 5)),
    (8, 9, "H", (205, 15, 23)),
    (9, 9, "I", (213, 123, 123))
]




fl_oor = [
    (x, renderer.height-2, "0", (255, 255, 255)) for x in range(renderer.width)
]
print(fl_oor)

renderer.prepare_frame(objects + fl_oor)

# print the frame
renderer.render_frame()



start_time = time.time()
while True:
    
    #objects = [(random.randint(1, 10), random.randint(1, 10), random.choice("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))) for i in range(10)]
    #objects += fl_oor
    objects += renderer.generate_shape("rectangle", x=5, y=5, width=7, height=7, color=(255, 255, 255), position=(1, 1))
    
    
    renderer.prepare_frame(objects)
    renderer.render_frame()
    with open("test.txt", "w") as f:
        f.write(f"{time.time() - start_time}")
    time.sleep(1/renderer.fps)
    
   


    
    
    
    
    
    
    







