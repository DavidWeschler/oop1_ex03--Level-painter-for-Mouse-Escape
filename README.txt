Exercise 3 - Level maker for mouse game

Written by: Ron Avital & David Weschler
			
In this OOP excercise we built a Level maker for the mouse game. 
after running the program, the user needs to enter the amount of rows an cols
of the level he wishes to make. then you can click on a button from the left col
and draw the level the way you wish. the program is built using the SFML library,
in a cMake enviroment and written in C++.
			

The files we created:
 - main.cpp: Short file that is responsible for activationg the Level maker.
 - Painter.h: Defines the Painter class, incharge of handling a character grid drawing board with file I/O and row allocation.
 - Painter.cpp: manages a drawing board represented by a grid of characters, allowing users to interactively draw, save, and load the board from a file.
 - Window.h: defines the funcs that manages a drawing application window using SFML, and handles user input
 - Window.cpp: Implements the functions defined in the header, and handkes the main while loop of SFML 
 - Board.h: Defines the class incgarge of getting the whole board and drawing it
 - Board.cpp: Implements the functions defined in Board.h, providing the functionality to draw the board and toolbar.
 - Row.h: Defines the Row class, representing a dinamic allocated array
 - Row.cpp: Implements the Row class, providing functionality for managing and manipulating rows in the drawing board.
 - Tile.h: Defines the Tile class, representing individual tiles in the drawing board.
 - Tile.cpp: Implements the Tile class, providing functionality for managing and manipulating individual tiles in the drawing board.
 - 10 png/jpg pictures for the graphics
 - Board.txt: the output file, contains the Level the user created


Dominant Data Structures:
- We use a vector of Rows (a Row is a dinamic allocated array we created) to store the data of the level throughout the game.

Notable Algorithms:
- 

Design Overview:

The Painter manages the drawing board, dealing with file operations and user interaction. 
The Window handles the graphical interface using SFML, while the Board manages buttons, 
the drawing matrix, and toolbar, providing a cohesive structure for interactive drawing with file support. 
Together, they create a simple and expandable program for drawing. Row and Tile classes are responsible for 
managing rows and individual tiles in the drawing board, respectively. The Row class deals with the organization and manipulation of rows, 
while the Tile class handles the properties and content of each tile. They contribute to the overall structure of the drawing board, 
supporting the functionality implemented in the Painter and Window classes.

Known Bugs:

Notes:
