# Simulation of Two Dimensional Transformation

- ## [Menu Driven All program]()

  - included programs
    - Rotation
    - Scaling
    - Shearing
    - Translation
    - Reflection

- ## [Cohen Sutherland Line Clipping Algorithm]()

1. Read 2 end points of line as p1(x1,y1) and p2(x2,y2)

2. Read 2 corner points of the clipping window (left-top and right-bottom) as (wx1,wy1) and (wx2,wy2)

3. Assign the region codes for 2 endpoints p1 and p2 using following steps:-
    - initialize code with 0000
    - Set bit 1 if x < wx1
    - Set bit 2 if x > wx2
    - Set bit 3 if y < wy2
    - Set bit 4 if y > wy1

4. Check for visibility of line
    - If region codes for both endpoints are zero then line is completely visible. Draw the line go to step 9.
    - If region codes for endpoints are not zero and logical ANDing of them is also nonzero then line is invisible. Discard the line and move to step 9.
    - If it does not satisfy 4.a and 4.b then line is partially visible.

5. Determine the intersecting edge of clipping window as follows:-
    - If region codes for both endpoints are nonzero find intersection points p1’ and p2’ with boundary edges.
    - If region codes for any one end point is non zero then find intersection point p1’ or p2’.

6. Divide the line segments considering intersection points.

7. Reject line segment if any end point of line appears outside of any boundary.

8. Draw the clipped line segment.

9. Stop.

- ## [Rotation]()

- ## [Translation]()

- ## [Reflection]()

- ## [Shearing]()

- ## [Scaling]()
