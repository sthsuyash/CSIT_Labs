# All the algorithms and programs for Computer Graphics using C++

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

## [Moving Car](https://github.com/sthsuyash/CSIT_Labs/tree/main/3rd_Semester/moving_car.cpp)

## [Scan Conversion Algorithm](https://github.com/sthsuyash/CSIT_Labs/tree/main/3rd_Semester/Computer_Graphics/Scan_Conversion_Algorithm)

```README
The process of representing continuous graphics object as a collection of discrete pixels is known as scan conversion.
```

1. Scan Converting a Point and a straight Line:

   - [Digital Analyzer Algorithm](https://github.com/sthsuyash/C-projects/blob/main/Computer_Graphics/Scan_Conversion_Algorithm/DDA.cpp)
   - [Bresenham's Line Drawing Algorithm](https://github.com/sthsuyash/C-projects/blob/main/Computer_Graphics/Scan_Conversion_Algorithm/Bresenham.cpp)
     <br><br>

2. Scan Converting Circle and Ellipse:
   - [Mid Point Circle Algorithm](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/Scan_Conversion_Algorithm/circle.cpp)
   - [Ellipse Algorithm](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/Scan_Conversion_Algorithm/ellipse.cpp)
     <br><br>

## [Simulation of 2D transformation](https://github.com/sthsuyash/CSIT_Labs/tree/main/3rd_Semester/Computer_Graphics/Simulation_of_2D_transformation)

- [All Menu Driven Program](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/Simulation_of_2D_transformation/menuDrivenAll.cpp)
- [Cohen Sutherland line clipping algorithm](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/Simulation_of_2D_transformation/Cohen_Sutherland_Line_Clipping_Algorithm.cpp)
- [Rotation](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/Simulation_of_2D_transformation/rotation.cpp)
- [Scaling](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/Simulation_of_2D_transformation/scaling.cpp)
- [Shearing](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/Simulation_of_2D_transformation/shearing.cpp)
- [Translation](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/Simulation_of_2D_transformation/translation.cpp)
- [Reflection](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/Simulation_of_2D_transformation/reflection.cpp)

<br><br>

## [Simulation of 3D transformation](https://github.com/sthsuyash/CSIT_Labs/tree/main/3rd_Semester/Computer_Graphics/3D_transformation)

- [3D transformation menu driven program](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/3D_transformation/3Dmenu_driven.cpp)

<br><br>

## [3D Object Representation](https://github.com/sthsuyash/CSIT_Labs/tree/main/3rd_Semester/Computer_Graphics/3D_object_representation)

- [Beizer Curve](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/3D_object_representation/beizer_curve.cpp)
- [Sphere](https://github.com/sthsuyash/CSIT_Labs/blob/main/3rd_Semester/Computer_Graphics/3D_object_representation/sphere.cpp)

<br><br>
