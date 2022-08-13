- # [Digital Differential Analyzer (DDA) Algorithm](https://github.com/sthsuyash/C-projects/blob/main/Computer_Graphics/Scan_Conversion_Algorithm/DDA.cpp)

    - Step 1:
        - Get the input of two end points (x0 , y0 ) and (x1 , y1 ).

    - Step 2:
        - Calculate the differences between two end points.
        - dx = x1 - x0
        - dy = y1 - y0

    - Step 3:
        - Based on the calculated difference in Step 2, you need to identify the number of steps to put pixel.
        - If dx > dy then you need more steps in x coordinate;
        - otherwise in y coordinate.

        ```C
            if (dx > dy)
                Steps = absolute(dx);
            else
                Steps = absolute(dy);
        ```

    - Step 4:
        - Calculate the increment in x coordinate and y coordinate.
        ```C
        Xincrement = dx / (float) steps;
        Yincrement = dy / (float) steps;
        ```

    - Step 5:
        - Put the pixel by successfully incrementing x and y coordinates accordingly and complete the drawing of the line.

        ```C
            for(int v=0; v < Steps; v++) {
                x = x + Xincrement;
                y = y + Yincrement;
                putpixel(x,y);
            }
        ```
<br/><br/>
- # [Bresenham's Line Drawing Algorithm](https://github.com/sthsuyash/C-projects/blob/main/Computer_Graphics/Scan_Conversion_Algorithm/Bresenham.cpp)


Given coordinate of two points A(x1, y1) and B(x2, y2).
The task to find all the intermediate points required for drawing line AB on the computer screen of pixels.
Note that every pixel has integer coordinates.

Below are some assumptions to keep algorithm simple.
 - We draw line from left to right.
 - x1 < x2 and y1< y2
 - Slope of the line is between 0 and 1. We draw a line from lower left to upper right.

<br/><br/>
`Table to check the next point from previous`
| <p align="center">When m < 1</p>                                                                                                                                                                                                                                                                                                                                                | <p align="center">When m > 1 </p>                                                                                                                                                                                                                                                                                                                                           |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| <p align="center">P<sub>o</sub> = 2dy-dx </p>                                                                                                                                                                                                                                                                                                                                   | <p align="center">P<sub>o</sub> = 2dx-dy </p>                                                                                                                                                                                                                                                                                                                               |
| <table><tr><td>**When P < 0**</td><td>**When P >= 0**</td></tr><tr><td>x<sub>i+1</sub> = x<sub>i</sub> + 1</td><td>x<sub>i+1</sub> = x<sub>i</sub> + 1</td></tr><tr><td>y<sub>i+1</sub> = y<sub>i</sub></td><td>y<sub>i+1</sub> = y<sub>i</sub> + 1</td></tr><tr><td>P<sub>i+1</sub> = P<sub>i</sub> + 2dy</td><td>P<sub>i+1</sub> = P<sub>i</sub> + 2dy - 2dx</td></tr></table> | <table><tr><td>**When P < 0**</td><td>**When P >= 0**</td></tr><tr><td>x<sub>i+1</sub> = x<sub>i</sub></td><td>x<sub>i+1</sub> = x<sub>i</sub> + 1</td></tr><tr><td>y<sub>i+1</sub> = y<sub>i</sub> + 1</td><td>y<sub>i+1</sub> = y<sub>i</sub>+1</td></tr><tr><td>P<sub>i+1</sub> = P<sub>i</sub> + 2dx</td><td>P<sub>i+1</sub> = P<sub>i</sub> + 2dx - 2dy</td></tr></table> |

<br/><br/>

- # [Mid-Point Circle Algorithm](https://github.com/sthsuyash/C-projects/blob/main/Computer_Graphics/Scan_Conversion_Algorithm/circle.cpp)
  - ```Equation of circle```: x<sup>2</sup> + y<sup>2</sup> = r<sup>2</sup>
  - The first thing we can notice to make our circle drawing algorithm more efficient is that
circles centred at (xc, yc) have symmetry.

  - Symmetries in a circle:
    - 4-way symmetry
    - 8-way symmetry

  - Similarly to the case with lines, there is an incremental algorithm for drawing circles.
    - Mid point circle algorithm.
  - In the mid-point circle algorithm, we use eight-way symmetry so only ever calculate the points for the top right eighth of a circle, and then use symmetry to get the rest of the points.
  - Eight Point symmetry is used by reflecting each calculated point around each 45° axis.
  - For any given pixel (x, y), the next pixel to be plotted is either (x, y+1) or (x-1, y+1).
  - This can be decided by following the steps below.
    - Find the mid-point p of the two possible pixels i.e (x-0.5, y+1).
    - If p lies inside or on the circle perimeter, we plot the pixel (x, y+1), otherwise if it’s outside we plot the pixel (x-1, y+1)
    - Whether the mid-point lies inside or outside the circle can be decided by using the formula:-
      - Given a circle centered at (0,0) and radius r and a point p(x,y)
        - F(p) = x<sup>2</sup> + y<sup>2</sup> - r<sup>2</sup>
        - ```Cpp
            if F(p) < 0         // the point is inside the circle.
            else if F(p) = 0    // the point is on the perimeter
            else F(p) > 0       // the point is outside the circle
           ```
           
        - Main algorithm:
        ```Cpp
        while (x >= y){
		    putpixel(x0 + x, y0 + y, 7);
		    putpixel(x0 + y, y0 + x, 7);
		    putpixel(x0 - y, y0 + x, 7);
		    putpixel(x0 - x, y0 + y, 7);
		    putpixel(x0 - x, y0 - y, 7);
		    putpixel(x0 - y, y0 - x, 7);
		    putpixel(x0 + y, y0 - x, 7);
		    putpixel(x0 + x, y0 - y, 7);
 
		    if (err <= 0){
		        y += 1;
    		    err += 2*y + 1;
		    }
		    if (err > 0){
    		    x -= 1;
    		    err -= 2*x + 1;
		    }
        }
        ```
        
  - ### Problem with Mid point Circle Drawing:
    - Works only for the circle with center at (0, 0).
    - So if center is other point than the (0, 0), as stated in the algorithm, we first calculate the points assuming the center coordinates is (0, 0).
    - At the end, we translate the circle.

<br/><br/>



- # [Ellipse Algorithm](https://github.com/sthsuyash/C-projects/blob/main/Computer_Graphics/Scan_Conversion_Algorithm/ellipse.cpp)

  - An ellipse can be represented as:<br/>
        (𝑥−ℎ)<sup>2</sup>/𝑎<sup>2</sup> + (𝑦−𝑘)<sup>2</sup>/𝑏<sup>2</sup> = 1<br/>
            &nbsp;where,<br/>
            &nbsp;&nbsp;(h, k) = ellipse center.<br/>
            &nbsp;&nbsp;a = length of semi-major axis.<br/>
            &nbsp;&nbsp;b = length of semi-minor axis.<br/>
  - Elliptical curves can be generated by modifying circle drawing procedures.
  - The ellipse, like the circle, shows symmetry.
  - An ellipse is symmetric in quadrants.
  - So, if one quadrant is generated then other three parts can be easily generated.
  - The algorithm is applied throughout the 1st quadrant according to
the slope of the ellipse.
  - First quadrant is divided into two parts, region 1(R1) and region 2(R2).
  - These regions are formed by considering the slope of the curve.
  - For the region (R1) where the slope of the curve is less than -1.
  - We process by taking unit steps in x direction and find corresponding y.
  - And for the R2 where the slope is greater than -1 we take unit steps in y direction and find  corresponding x.
  - For R2, the initial point is the last calculated point in R1.
  - The ellipse slope is calculated from equation :
  - 𝑥<sup>2</sup>/𝑎2 + 𝑦<sup>2</sup>/𝑏<sup>2</sup> = 1
  - Differentiating both sides w.r.t x:
    - 𝑑𝑦/𝑑𝑥 = – 2𝑏<sup>2</sup>/𝑥 / 2𝑎<sup>2</sup>𝑦
  - At the boundary region R1 and region R2,
    - 𝑑𝑦/𝑑𝑥 = -1 and
    - 2b<sup>2</sup>x = 2a<sup>2</sup>y
  - Therefore, we move out of region-1(R1) when 2b<sup>2</sup>x >= 2a<sup>2</sup>y.

<br/><br/>

