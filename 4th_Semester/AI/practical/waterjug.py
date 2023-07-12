j1 = 0
j2 = 0
x = 4
y = 3

print("Initial state: (0, 0)")
print("Capacities: (4, 3)")
print("Goal state: (2, 0 or any number)")

while j1 != 2:
    r = int(input("Enter the rule: "))
    if (r == 1):
        j1 = x
    elif (r == 2):
        j2 = y
    elif (r == 3):
        j1 = 0
    elif (r == 4):
        j2 = 0
    elif (r == 5):
        t = y-j2
        j2 = y
        j1 -= t
        if j1 < 0:
            j1 = 0
    elif (r == 6):
        t = x-j1
        j1 = x
        j2 -= t
        if j2 < 0:
            j2 = 0
    elif (r == 7):
        j2 += j1
        j1 = 0
        if j2 > y:
            j2 = y
    elif (r == 8):
        j1 += j2
        j2 = 0
        if j1 > x:
            j1 = x
    print(j1, j2)

'''
Rule jug Task State/logic
1 (j1,j2) Fill the 4-gallon jug if(r==1):
j1=x;
2 (j1,j2) Fill the 3-gallon jug elif(r==2):
j2=y
3 (j1,j2) Empty the 4-gallon jug on the ground elif(r==3):
j1=0;
4 (j1,j2) Empty the 3-gallon jug on the ground elif(r==4):
j2=0;
5 (j1,j2) Pour water from the 4-gallon jug into 
the 3-gallon jug until the 3-gallon jug 
is full
elif(r==5):
t=y-j2;
j2=y;
j1-=t
 if j1<0
 j1=0
6 (j1,j2) Pour water from the 3-gallon jug into 
the 4-gallon jug until the 4-gallon jug 
is full
elif(r==6):
t=x-j1;
j1=x
j2-=t;
 if j2<0:
 j2=0;
7 (j1,j2) Pour all water from the 4-gallon jug 
into the 3-gallon jug until the 4-
gallon jug becomes empty
elif(r==7):
j2+=j1
j1=0;
 if j2>y
 j2=y
8 (j1,j2) Pour water from the 3-gallon jug 
into the 4-gallon jug until the 3-
gallon jug becomes empty
elif(r==8):
j1+=j2
j2=0;
 if j1>x
 j1=x
'''
