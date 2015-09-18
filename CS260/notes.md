#CS 260 Notes

###08.27.2015
Hardware control
- Assembly controls hardware more so than higher level languages so it is used to created libraries like DirectX
- Drivers faciliate communication between applications and hardware.
- Drivers are also applications for performing specific tasks

DirectX
- Is a technology and C++ is the means in which we implement it
- An api that abstracts the functionality for interfacing with the overall system

###09.03.2015
```
Game Development (DirectX)
    |
    |               Describe
Windows (GUI) ----- Register
    |               Create
    |               Show
Event-Driven
```

##### Describe
Windows Programming
- Primarily written in C++ (OOP)
- Classes contain funtions and variables both of which are called members

lpfnWndProc is a refrence to a callback function/procedure
```CPP
WNDCLASSEX windowClass = { 0 };
windowClass.lpfnWndProc = WindProc; // Callback function
```

##### Register
Pass the above class object by refrence to the register
```CPP
if (!RegisterClassEx(&windowClass))
{
    return -1 // Failed to register -- Handle error
}
```
##### Create/Setup
Windows are rectangular in shape. Define by 4 dimensions
```CPP
RECT rectangle = {0,0,640,480};
AdjustWindowRect(&rectangle, WS_OVERLAPPEDWINDOW, FALSE); // False stands for now menu
```

##### Show
After creating the window handle (HWND) you can show the window as followed
```CPP
ShowWindow(hwnd, commandShow);
```

##### Callbacks
Just like standard C++ we can only have on return type LRESULT but we also can include an attribute type CALLBACK
```CPP
LRESULT CALLBACK WndProc
```
###09.17.2015
##### 2D Rendering
- Adobe Flash, MS Silverlight, HTML5 are examples of technologies that are often used for web based games
- Grid like area to place objects x,y axis
- A plane is a 2d area that stretches to infinity

##### 3D Rendering
- 3D games of course add a 3rd axis z for (x,y,z)
- Similar to the plane, the Cube has an infinite number of planes stacked on top of each other

##### Textures
- Are images that is mapped over a surface to simulate its complexity in a non-geometric sense (Wall brick)
- Core to both 2D and 3D games
- Types include color, light, shadow and alpha maps (transparency)
- "Lookup texture" store values for a pixel that can be used during lighting calculations for example used for an algorithm taking place during rendering.

##### Sprites
- 2D graphical element that appears on screen
- Textured 2d shape (rectangle, square) used for backgrounds, weapons, etc.
- Animations in 2D takes a series of sprites and display them in rapid succession

##### Vertex
- A point with a series of attributes (position, color, texture coord) that defines a region of a shape
- Graphics hardware uses the attr to draw a particular shape

##### Shape
- Collection of verticies connected together with edges (lines) whose insides are shaded in by the graphics hardware
- A shape is referred to as lines if it has 2 connected points or as polygons if it has 3 or more connected points

##### Mesh
- An object made up if polygons, specifically triangle polygons
    - A triangle list: is an array of individual triangles that are independent of one another
    - A triangle strip: is an array where adding 1 more vertex is sufficent to add another triangle
    - A triangle fan: always uses the first vertex along with the previous vertex and the new one
- A mode is a collection of meshes
    - A character model can be made up of the head, legs and other body parts (meshes)
