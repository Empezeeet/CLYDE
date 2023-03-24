import clyde_renderer as clyde_renderer
import time
import random
clyde_renderer = clyde_renderer.Render(width=20, height=10, fps=5)


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
    (x, clyde_renderer.height-2, "0", (255, 255, 255)) for x in range(clyde_renderer.width)
]
print(fl_oor)

clyde_renderer.prepare_frame(objects + fl_oor)

# print the frame
clyde_renderer.render_frame()



start_time = time.time()
while True:
    objects = [ 
        (random.randint(1, 9), random.randint(1, 9), "A", (255, 12, 102)),
        (random.randint(1, 9), random.randint(1, 9), "B", (52, 255, 255)),
        (random.randint(1, 9), random.randint(1, 9), "C", (255, 255, 65)),
        (random.randint(1, 9), random.randint(1, 9), "D", (255, 255, 255)),
        (random.randint(1, 9), random.randint(1, 9), "E", (255, 52, 255)),
        (random.randint(1, 9), random.randint(1, 9), "F", (0, 0, 0)),
        (random.randint(1, 9), random.randint(1, 9), "G", (5, 5, 5)),
        (random.randint(1, 9), random.randint(1, 9), "H", (205, 15, 23)),
        (random.randint(1, 9), random.randint(1, 9), "I", (213, 123, 123))
    ]
    
    clyde_renderer.prepare_frame(objects)
    clyde_renderer.render_frame()
    time.sleep(1/clyde_renderer.fps)
    
   


    
    
    
    
    
    
    







