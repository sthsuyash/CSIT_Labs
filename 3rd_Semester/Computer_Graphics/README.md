# All the algorithm programs for Computer Graphics using C++

## How to add graphics.h in dev C++

1. Add header source files into the Dev C++ directory

   - First, download the header files from this [Google drive link](https://drive.google.com/file/d/1ULN_XcrbDkls2U2DlYkNM_yiua5h-_NI/view?usp=sharing) and extract the files.
   - It contains three files:
     - graphics.h - winbgim.h - libbgi.a.
   - You need to copy “graphics.h” and “winbgim.h” into include the directory of Dev-Cpp program resource files. The exact directory address is –
     - C:\Program Files (x86)\Dev-Cpp\MinGW64\include
   - Next, copy “libbgi.a” to lib folder, which should be inside MinGW64. The directory address is –
     - C:\Program Files (x86)\Dev-Cpp\MinGW64\lib

2. Change compiler suit in Dev C++

   - First open Dev C++ appliaction.
   - On the right side of the toolbar, you will have the drop-down menu to select the desired compiler suit.
   - Set it to TDM - GCC 4.9.2 32-bit release.

3. Configure required linkers for graphics

   - On Dev, C++, look for the Tool option on the top menu.
   - Expand tools and select Compiler Options.
   - You should arrive on the general tab of the compiler options window.
   - Ensure the “Add the following commands when calling the linker” check box is selected.
   - Then add these linkers in the input box – (just copy and paste this line)

     -libgcc -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

   - Then click on OK to save.

     [Reference](https://gamespec.tech/how-to-add-graphics-in-dev-c/)

## Programs

1. ## [Scan Conversion Algorithm](Scan_Conversion_Algorithm/)

```README
The process of representing continuous graphics object as a collection of discrete pixels is known as scan conversion.
```

- Scan Converting a Point and a straight Line:

  - [Digital Analyzer Algorithm](Scan_Conversion_Algorithm/DDA.cpp)
  - [Bresenham's Line Drawing Algorithm](Scan_Conversion_Algorithm/Bresenham.cpp)

- Scan Converting Circle and Ellipse:

  - [Mid Point Circle Algorithm](Scan_Conversion_Algorithm/midpoint-circle.cpp)
  - [Bresenham Circle Algorithm](Scan_Conversion_Algorithm/bresenham-circle.cpp)
  - [Ellipse Algorithm](Scan_Conversion_Algorithm/ellipse.cpp)

2. ## [2D Geometric Transformations](2D_Geometric_transformations/)

   - [All Menu Driven Program](2D_Geometric_transformations/menuDrivenAll.cpp)
   - [Rotation](2D_Geometric_transformations/rotation.cpp)
   - [Scaling](2D_Geometric_transformations/scaling.cpp)
   - [Shearing](2D_Geometric_transformations/shearing.cpp)
   - [Translation](2D_Geometric_transformations/translation.cpp)
   - [Reflection](2D_Geometric_transformations/reflection.cpp)
   - [Cohen Sutherland line clipping algorithm](2D_Geometric_transformations/Cohen_Sutherland_Line_Clipping_Algorithm.cpp)
   - [Window Viewport Mapping](2D_Geometric_transformations/window_viewport_mapping.cpp)
   - [Composite Transformation](2D_Geometric_transformations/composite_transformation.cpp)

3. ## [3D Geometric transformation](3D_Geometric_transformation/)

   - [Menu driven program](3D_Geometric_transformation/3Dmenu_driven.cpp)

4. ## [3D Object Representation](3D_object_representation/)

   - [Beizer Curve](3D_object_representation/beizer_curve.cpp)
   - [Sphere](3D_object_representation/sphere.cpp)

5. ## [Visible Surface Detection](Visible_Surface_Detections/)

   - [Implementaion of rotation of 3D cube](Visible_Surface_Detections/rotation_3D_cube.cpp)

6. ## [Introduction to OpenGL](OpenGL/)

   - [Event Driven Programming](OpenGL/Event_Driven_Programming.cpp)
   - [Point](Computer_Graphics/OpenGL/point.cpp)
   - [Line](Computer_Graphics/OpenGL/line/line.cpp)
   - [Polygon](Computer_Graphics/OpenGL/polygon.cpp)
   - [Drawing 3D objects](Computer_Graphics/OpenGL/drawing_3D_objects.cpp)

   - [Color Cube](OpenGL/colorCube/colorCube.cpp)
