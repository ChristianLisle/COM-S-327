## Documentation

The [`main.c`](main.c) file includes the main method, which references the [`ca.h`](ca.h) header file that implements functions implemented within [`ca.c`](ca.c).

In its current state, the program initializes a 2DCA based on the user input (command line arguments) file. The program then performs steps of the Game of Life rule on the 2DCA, halting after each step until the user hits `enter`. The program exits when any other character is entered.

## Files & Functions

#### [`main.c`](main.c)

`printParameterInfo` prints the parameter info. This function is to be called whenever the user enters the incorrect parameters.

`validateParameters` validate the given parameters. If the parameters are invalid, inform the user and exit the program. The function takes parameters; `int` parameter count, `char *` array of parameters.

`gameOfLifeRule` is the rule to be performed on a cell in `2DCA`. It is to be passed into the `step2DCA` function. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to 2DCA, `int` x and `int` y index of character to perform rule on.

`main` is the application that builds a 2DCA. Currently, the app builds a 2DCA based on file from user input. The program then allows the user to step through iterations of the 2DCA, displaying the 2DCA at each iteration, until the user exits the program.

#### [`ca.h`](ca.h)

This is the header file which defines cellular automata structures and all functions contained in `ca.c` file, so they are readily accessable to files such as `main.c`.

#### [`ca.c`](ca.c)

This is the file that performs all of the manipulation of states in a CA. Functions in this file utilize the `stdio.h`, `stdlib.h`, and `time.h` libraries in their implementations.

`initCA` initalizes a CA by setting all states to the **state** parameter. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to ca, `int` state.

`set1DCACell` sets the state of a given cell in a 1DCA. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to 1DCA, `unsigned int` index of cell to be updated, `unsigned char` new state. **Note:** The function validates its input (index and dimensionality).

`set2DCACell` sets the state of a given cell in a 2DCA. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to 2DCA, `unsigned int` x index of cell to be updated, `unsigned int` y index of cell to be updated, `unsigned char` new state. **Note:** The function validates its input (index).

`displayCA` displays the CA appropriately. The function takes a single parameter; `CELLULAR_AUTOMATA*` pointer to CA.

`create1DCA` creates a 1DCA given the width and quiescent state. The function takes parameters; `int` width of ca, `unsigned char` initial (quiescent) state. The function returns a pointer to the created 1DCA. **Note:** The function returns `NULL` if it is unable to construct a 1DCA properly.

`create2DCA` creates a 2DCA given the width, height, and quiescent state. The function takes parameters; `int` width of ca, `int` height of ca, `unsigned char` initial (quiescent) state. The function returns a pointer to the created 2DCA. **Note:** The function returns `NULL` if it is unable to construct a 2DCA properly.

`step1DCA` performs a single step on the 1DCA. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to 1DCA, `unsigned char (*)(CELLULAR_AUTOMATA*, int)` pointer to function that acts as rule to be performed, `int` flag representing index.

`step2DCA` performs a single step on the 2DCA. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to 2DCA, `unsigned char (*)(CELLULAR_AUTOMATA*, int, int)` pointer to function that acts as rule to be performed, `int` flags representing x and y indices.