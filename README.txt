Preadator-Prey-Simulation
A C++ simulation involving predators and prey objects

Program Summary

This program implements a simple 2D predator-prey simulation using derived classes and virtual functions. The predators are the doodlebugs. They will consume the prey, which are ants. Both organisms breed at different rates, and move randomly within the grid.  

How to Run the Program

Put the program code into a Linux directory. Then compile and link the program with the following command: make all

To run the program, enter: ./PA6 gridSize #doodlebugs #ants #time_steps seed pause

The gridSize is the number representing the side lengths of the grid. It will default to 20. The #doodlebugs is the number of predators int the simulation. It will default to 20. The #ants is the number of prey organisms and defaults to 100. the #time_steps is the number of move cycles in the simulation and will default to 1000. The seed is the number used to seed the random number generator and will default to 1. Lastly, the pause is an indicator of whether or not to pause in between each movement cycle. 

Problems I encountered

I had difficulty understanding the 2D array using pointers to organisms. Figuring out what belonged to the super class compared to the subclasses. 


Source Citations:

Textbook Absolute C++ Walter Savitch

---------------------------------------------------------------------------------------------------------------


Test Case 1:

This test shows a small board where the doodlebug eats the only ant, so it terminates early. 

./PA6 4 1 1 30 1 1


Time Step:  0 (Initial Configuration)
....
....
...x
.o..
Press Enter to continue

Time Step:  1
....
....
..x.
..o.
Press Enter to continue

Time Step:  2
....
....
....
..x.
Press Enter to continue

Command Line:  ./PA6 4 1 1 30 1 1 
Number of Steps Simulated:  2
Total Number of Ants Created:  1, Ants Remaining:  0
Total Number of Doodlebugs Created:  1, Doodlebugs Remaining:  1

FINAL CONFIGURATION 
Time Step:  2
....
....
....
..x.



------------------------------------------------------------------------------------
Test Case 2: 

This test shows the ant and doodlebug moving randomly, without coming into contact. The ant breeds while the doodlebug starves. 

./PA6 6 1 1 30 1 1

Time Step:  0 (Initial Configuration)
......
...o..
......
......
.x....
......
Press Enter to continue

Time Step:  1
......
..o...
......
......
..x...
......
Press Enter to continue

Time Step:  2
..o...
......
......
......
......
..x...
Press Enter to continue

Time Step:  3
...o..
...o..
......
......
......
......
Press Enter to continue

Command Line:  ./PA6 6 1 1 30 1 1 
Number of Steps Simulated:  3
Total Number of Ants Created:  2, Ants Remaining:  2
Total Number of Doodlebugs Created:  1, Doodlebugs Remaining:  0

FINAL CONFIGURATION 
Time Step:  3
...o..
...o..
......
......
......
......







-----------------------------------------------------------------------------------------------------------------
Test Case 3:

This test shows a doodlebug consuming ants and breeding. 

./PA6 6 1 6 12 2 2

Time Step:  0 (Initial Configuration)
...o..
x.....
......
oo..o.
......
..oo..
Press Enter to continue

Time Step:  2
...o..
......
......
x.....
oo....
o..oo.
Press Enter to continue

Time Step:  4
.....o
...o..
...oo.
o.....
ooo...
x...o.
Press Enter to continue

Time Step:  6
..oooo
..oo..
......
oooo..
.x.o..
.ooo..
Press Enter to continue

Time Step:  8
o.oo..
..oo..
o..oo.
..o...
.o.o..
oxx...
Press Enter to continue

Time Step:  10
oooooo
oooo.o
.o..o.
.oo...
oox..o
o.x...
Press Enter to continue

Command Line:  ./PA6 6 1 6 12 2 2 
Number of Steps Simulated:  12
Total Number of Ants Created:  28, Ants Remaining:  18
Total Number of Doodlebugs Created:  2, Doodlebugs Remaining:  2

FINAL CONFIGURATION 
Time Step:  12
ooooo.
oo..o.
oooo.o
o.x.o.
o.x...
.o...o

---------------------------------------------------------------------------------------
Test Case 4:

This test looks at a very large board and a large number of ants and doodlebugs. 

./PA6 15 20 200 1000 1 200

Time Step:  0 (Initial Configuration)
ooooooooooooooo
oooooooxxxoooxo
.oooooooooooooo
oooooooo.xooxoo
ooooox.oooooo.o
ooxoooooooooooo
xoooooooooooooo
oxxoooooooooooo
oooo.ooooooxooo
ooooooooooooxoo
oooooooxxoooxoo
ooooooooooooooo
oxoooooooooooox
ooxoooooooooooo
ooooooxoooooooo
Press Enter to continue

Time Step:  200
ooooooxoooooooo
ooooooxooo.xooo
oooooooooxoxoxx
oooooooo.xooooo
o.oxxxxo..ooxxo
.oooo...o.o..xo
o..ooooxxo..oxo
..ooo.....oxoo.
.......o...xo.o
..x..o...xo.ox.
xox...x..x...xo
x.....x....x..o
.......o...x.xx
..x....oo......
xxxxx...xx.....
Press Enter to continue

Time Step:  400
xxooooooooxxoxo
oooxoooooooooxo
oooxxxooooooxxx
..xooooooooox..
o.xooxoooooxo.o
oooooxooo.ox..o
o.o.oooooxxxxoo
oooooooooooo...
..oooo.ooooooox
...oxxxooooooox
xoxoxooox..o.oo
x.xoooooxoooooo
xxooooooooooooo
ooo..oooooooo..
ooo.o.oo.o.o.o.
Press Enter to continue

Command Line:  ./PA6 15 20 200 1000 1 200 
Number of Steps Simulated:  550
Total Number of Ants Created:  7027, Ants Remaining:  6
Total Number of Doodlebugs Created:  859, Doodlebugs Remaining:  0

FINAL CONFIGURATION 
Time Step:  550
...............
...............
...............
...............
...............
...............
...............
...............
.....o.........
.....oo......o.
...............
.......o.......
.............o.
...............
...............

--------------------------------------------------------------------------------------------
Test Case 5:

This test shows a very small board that is filled with ants and a doodlebug. 

./PA6 2 1 3 30 1 1

Time Step:  0 (Initial Configuration)
ox
oo
Press Enter to continue

Time Step:  1
oo
.x
Press Enter to continue

Time Step:  2
.x
o.
Press Enter to continue

Time Step:  3
oo
.x
Press Enter to continue

Time Step:  4
.x
o.
Press Enter to continue

Time Step:  5
x.
.o
Press Enter to continue

Time Step:  6
ox
o.
Press Enter to continue

Time Step:  7
x.
.o
Press Enter to continue

Time Step:  8
xo
x.
Press Enter to continue

Time Step:  9
xx
..
Press Enter to continue

Command Line:  ./PA6 2 1 3 30 1 1 
Number of Steps Simulated:  9
Total Number of Ants Created:  5, Ants Remaining:  0
Total Number of Doodlebugs Created:  2, Doodlebugs Remaining:  2

FINAL CONFIGURATION 
Time Step:  9
xx
..









  
