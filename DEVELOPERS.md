## Documentation

The [`casimulator.cpp`](casimulator.cpp) file includes the main method, and references the [`CellularAutomaton.h`](CellularAutomaton.h), [GraphicsClient.h](GraphicsClient.h), and [`Simulator.h`](`Simulator.h`) header files representing objects.

The program initializes a Cellular Automaton simulator. The user can then randomly generate a two-dimensional Cellular Automaton, or load one by txt file. The program then allows the user to interact with the Cellular Automaton in various ways, such as perform steps of the Game of Life rule.


## Files & Functions

#### [`casimulator.cpp`](main.cpp)

`gameOfLifeRule` is the rule to be performed on a cell in `2DCA`. The function takes parameters; `CellularAutomaton*` pointer to 2DCA, `int` x and `int` y index of character to perform rule on.

`main` is the application that builds and constantly refreshes a Simulator.


#### [`CellularAutomaton.h`](CellularAutomaton.h)

This is the header file which defines the `CellularAutomaton` class and all functions contained in `CellularAutomaton.cpp` file, so they are readily accessable to files such as `casimulator.cpp`.


#### [`CellularAutomaton.cpp`](CellularAutomaton.cpp)

This file contains the implementation of the `CellularAutomaton` class.

`CellularAutomaton` constructors:
 - *default* constructor that takes parameters; `string` filename, `int` quiescent state
 - constructor that takes parameters; `int` width, `int` height, `int` quiscent state
 - copy constructor that takes parameters; another `CellularAutomaton`

`~CellularAutomaton` is the destructor. It behaves as an object destructor should.

`operator=` is the operator overload function of the `=` operator. It envokes the `CellularAutomaton` constructor on the `CellularAutomaton` parameter obejct passed in.

`step` performs a single step on the `CellularAutomaton`. The function takes parameters; `unsigned char (*rule)(CellularAutomaton*, int , int )` pointer to function representing the rule to be performed.

`displayCA` utilizes an already connected `GraphicsClient` object to display the current state of the `CellularAutomaton`. The function takes parameters; `GraphicsClient` object, `unsigned int` size of display container.

`setCell` sets the value of a cell given an index and state. The function takes parameters; `unsigned int` x index, `unsigned int` y index, `unsigned int` state.

`getCells` returns a pointer to the address of the `unsigned char` representing the cells of the Cellular Automaton.


#### [`GraphicsClient.h`](GraphicsClient.h)

This is the header file which defines the `GraphicsClient` class and all functions contained in `GraphicsClient.cpp` file, so they are readily accessable to files such as `casimulator.cpp`.


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

`requestFile` sends a message via socket connection to prompt the user with the file browser.


#### [`Simulator.h`](Simulator.h)

This is the header file which defines the `Simulator` class and all functions contained in `Simulator.cpp` file, so they are readily accessable to files such as `casimulator.cpp`.


#### [`Simulator.cpp`](Simulator.cpp)

`Simulator` default constructor that takes parameters; `string` address/url of Graphics Server, `int` port of GraphicsServer, `unsigned char (*)(CellularAutomaton*, int, int)` pointer function to Cellular Automaton rule. **Note:** A copy constructor that takes another Simulator as its parameter exists.

`~Simulator` is the destructor. It envokes the destructors of its `CellularAutomaton` and `GraphicsClient`.

`Simulator=` is the operator overload function of the `=` operator. It envokes the `Simulator` constructor on the `Simulator` parameter object passed in.

`listen` is the function that listens for a mouse click. The function takes no parameters, but returns a `MouseClick` struct, which includes data; `success`, `type`, `button`, `x`, `y`.

`handleClick` decides what to do given a mouse click. The function takes parameters; `x` coordinate, `y` coordinate.

`getStatus` returns the status of the `Simulator`.

---

#### The different values of `status` are:

`-1` - Program is closed (terminated)

`0` - Program is paused (**defualt**)

`1` - Program is playing - constantly iterating through steps of Cellular Automaton
