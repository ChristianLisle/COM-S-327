## Documentation

The [`main.cpp`](main.cpp) file includes the main method, which references the [`CellularAutomaton.h`](CellularAutomaton.h) and [GraphicsClient.h](GraphicsClient.h) header files which implement functions implemented within [`ca.c`](ca.c).

In its current state, the program initializes a 2DCA based on the user input (command line arguments) file. The program then performs steps of the Game of Life rule on the 2DCA, halting after each step until the user hits `enter`. The program exits when any other character is entered.

## Files & Functions

#### [`main.cpp`](main.cpp)

`printParameterInfo` prints the parameter info. This function is to be called whenever the user enters the incorrect parameters.

`validateParameters` validate the given parameters. If the parameters are invalid, inform the user and exit the program. The function takes parameters; `int` parameter count, `char *` array of parameters.

`gameOfLifeRule` is the rule to be performed on a cell in `2DCA`. It is to be passed into the `step2DCA` function. The function takes parameters; `CellularAutomaton*` pointer to 2DCA, `int` x and `int` y index of character to perform rule on.

`main` is the application that builds a 2DCA. Currently, the app builds a 2DCA based on file from user input. The program then allows the user to step through iterations of the 2DCA, displaying the 2DCA at each iteration, until the user exits the program.

#### [`CellularAutomaton.h`](CellularAutomaton.h)

This is the header file which defines the `CellularAutomaton` class and all functions contained in `CellularAutomaton.cpp` file, so they are readily accessable to files such as `main.cpp`.


#### [`CellularAutomaton.cpp`](CellularAutomaton.cpp)

This file contains the implementation of the `CellularAutomaton` class.

`CellularAutomaton` is the default constructor that takes parameters; `string` filename, `int` quiescent state. **Note:** a copy constructor exists that takes another `CellularAutomaton` as its parameter.

`~CellularAutomaton` is the destructor. It behaves as an object destructor should.

`operator=` is the operator overload function of the `=` operator. It envokes the `CellularAutomaton` constructor on the `CellularAutomaton` parameter obejct passed in.

`step` performs a single step on the `CellularAutomaton`. The function takes parameters; `unsigned char (*rule)(CellularAutomaton*, int , int )` pointer to function representing the rule to be performed.

`displayCA` utilizes an already connected `GraphicsClient` object to display the current state of the `CellularAutomaton`. The function takes parameters; `GraphicsClient` object.

#### [`GraphicsClient.h`](GraphicsClient.h)

This is the header file which defines the `GraphicsClient` class and all functions contained in `GraphicsClient.cpp` file, so they are readily accessable to files such as `main.cpp`.


#### [`GraphicsClient.cpp`](GraphicsClient.cpp)

This file contains the implementation of the `GraphicsClient` class.

`convertInt2Byte` converts the lowest 2 bytes of an integer to hexadecimal. The function takes parameters; `int` integer to convert, `char*` buffer to store hexadecimal in, `int` starting index of buffer.

`convertInt4Byte` converts the lowest 4 bytes of an integer to hexadecimal. The function takes parameters; `int` integer to convert, `char*` buffer to store hexadecimal in, `int` starting index of buffer.

`preformatMessage` preformats a message. The function takes parameters; `char*` message, `int` size of payload, `int` type of message.

`GraphicsClient` is the default constructor that takes parameters; `string` connection url, `int` connection port. **Note:** a copy constructor exists that takes another `GraphicsClient` as its parameter.

`~GraphicsClient` is the destructor. It closes the socket connection given one exists.

`operator=` is the operator overload function of the `=` operator. It envokes the `GraphicsClient` constructor on the `GraphicsClient` parameter obejct passed in.

`setBackgroundColor` sends a message via socket connection to set the background color. The function takes parameters; `int` red value, `int` green value, `int` blue value.

`setDrawingColor` sends a message via socket connection to set the drawing color. The function takes parameters; `int` red value, `int` green value, `int` blue value.

`clear` sends a message via socket connection to clear the GUI.

`setPixel` sends a message via socket connection to set a specific pixel to a certain color. The function takes parameters; `int` x coordinate, `int` y coordinate, `int` red value, `int` green value, `int` blue value.

`drawRectangle` sends a message via socket connection to draw a rectangle outline. The function takes parameters; `int` x coordinate, `int` y coordinate, `int` width, `int` height.

`fillRectangle` sends a message via socket connection to draw a filled rectangle. The function takes parameters; `int` x coordinate, `int` y coordinate, `int` width, `int` height.

`clearRectangle` sends a message via socket connection to clear a rectangle. The function takes parameters; `int` x coordinate, `int` y coordinate, `int` width, `int` height.

`drawOval` sends a message via socket connection to draw an oval outline. The function takes parameters; `int` x coordinate, `int` y coordinate, `int` width, `int` height.

`fillOval` sends a message via socket connection to draw a filled oval. The function takes parameters; `int` x coordinate, `int` y coordinate, `int` width, `int` height.

`drawLine` sends a message via socket connection to draw a line. The function takes parameters; `int` x coordinate 1, `int` y coordinate 1, `int` x coordinate 2, `int` y coordinate 2.

`drawString` sends a message via socket connection to draw a string. The function takes parameters; `int` x coordinate, `int` y coordinate, `string` string to be drawn.

`repaint` sends a message via socket connection to repaint the GUI.