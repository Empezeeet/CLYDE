import threading
import os
from tcolorpy import tcolor
import time
import sys
class Render(threading.Thread):
    """
        CLYDE RENDERER
        This is simple 2D graphics renderer built for 2D Graphics in Command Line
        This is joke project, but it is still fun to use.
        You can only generate ASCII Art BUT you can use colors!
    
    
    """
    def __init__(self, **kwargs):
        """
            Initialize the render.
            Arguments:
                - width: Width of the render, default 10
                - heigh: Height of the render, **FOR NOW ALWAYS SAME AS WIDTH**
                - fps: Frames per second, default 12
                - border: Render border? Default: False
        """
        self.width = kwargs.get("width", 10)
        self.height = self.width #kwargs.get("height", 10)
        self.fps = kwargs.get("fps", 12)
        self.border: bool = kwargs.get("border", False)
        self._frame = [[(" ", (0, 0, 0)) for i in range(self.width)] for j in range(self.height)]
        pass
    
    
    
    
    def render_frame(self):
        """
            Frame is a 2 Dimensional array of objects
            Each object is a tuple of (symbol, color)
            symbol is a single character
            Color is represented as a tuple of (r, g, b)
            Example of 4x4 frame:
            ```
                frame = [
                    [("A", (255, 255, 255)), (), (), ()]
                    [(), (), (), ()]
                    [(), (), (), ()]
                    [(), (), (), ()]
                ]
            ```
        
        """
        os.system("cls")
        for y in range(self.height):
            for x in range(self.width):
                #print()
                sys.stdout.write(f"{tcolor(self._frame[y][x][0], color=self._frame[y][x][1])} ")
            sys.stdout.write("\n")#print() # New Line
        
    
    def prepare_frame(self, objects):
        """
            Objects is a list of objects
            1 Object is: (x, y, symbol, color)
            Example:
                objects = [
                    (1, 5, "A", (255, 12, 102)),
                    (2, 3, "B", (255, 255, 255))
                ]
        
        """
        
        # Create empty frame
        #                \/ - This character should be replaced with space TODO
        self._frame = [[(" ", (0, 0, 0)) for i in range(self.width)] for j in range(self.height)]        
        
        # Element: (1, 5, "A", (255, 12, 102))
        try:
            for element in objects:
                self._frame[element[1]][element[0]] = (element[2], element[3])
        except IndexError:
            pass
    
    def generate_shape(self, shape, **kwargs):
        """
            Generates shape.
            Arguments:
                - Shape: Shape to generate, available shapes: "rectangle", "circle"
                - center-x: Center of the shape on x axis. (Only when generating circle)
                - center-y: Center of the shape on y axis. (Only when generating circle)
                
                - width: Width of the shape. (Only when generating rectangle)
                - height: Height of the shape. (Only when generating rectangle)
                - position: Position of the shape. (Only when generating rectangle, bottom-left corner)

        """
        
        object_shape = {
            "shape":shape,
            "center-x":kwargs.get("center-x", None),
            "center-y":kwargs.get("center-y", None),
            "width":kwargs.get("width", None),
            "height":kwargs.get("height", None),
            "position":kwargs.get("position", None),
            "color":kwargs.get("color", (255, 255, 255))
        }
        match shape:
            case "rectangle":
                return self._generate_rectangle(object_shape)
            case "circle":
                return self._generate_circle(object_shape)
            case _:
                return "Invalid shape"
    
    def _generate_rectangle(self, shape: dict):
        """
            Generates rectangle.
            args:
                - shape: example shape dict object:
                    
                    ```
                    self.shape = {
                        "shape":shape,
                        "center-x":kwargs.get("center-x", None),
                        "center-y":kwargs.get("center-y", None),
                        "width":kwargs.get("width", None),
                        "height":kwargs.get("height", None),
                    }
                    ```
            returns:
                - "Objects" type list:
                
                    ```
                        [
                            (x, y, symbol, color),
                            etc...
                        ]
                    ```
        """
        
        # Generate rectangle
        objects = []
        for y in range(shape["position"][1], shape["height"]):
            for x in range(shape["position"][0], shape["width"]):
                objects.append((x, y, "H", shape["color"]))
        return objects
        

