## Documentation

The [`main.c`](main.c) file includes the main method, which references the [`ca.h`](ca.h) header file that implements functions implemented within [`ca.c`](ca.c).

In its current state, the program initializes a 1DCA based on the user input (command line arguments). The program then performs the requested number of steps on the 1DCA, displaying it at each iteration.

## Files & Functions

#### [`main.c`](main.c)

`printParameterInfo` prints the parameter info. This function is to be called whenever the user enters the incorrect parameters.

`validateParameters` validate the given parameters. If the parameters are invalid, inform the user and exit the program. The function takes parameters; `int` parameter count, `char *` array of parameters.

`rule110` is the rule to be performed on a cell in `1DCA`. It is to be passed into the `stepCA` function. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to 1DCA, `int` index of character to perform rule on.

`main` is the application that builds a 1DCA. Currently, the app builds a 1DCA based on user input. The program then performs a certain number of steps on the 1DCA and displays the 1DCA at each iteration.

#### [`ca.h`](ca.h)

This is the header file which defines all functions contained in `ca.c` file, so they are readily accessable to files such as `main.c`.

#### [`ca.c`](ca.c)

This is the file that performs all of the manipulation of states in a 1DCA. Functions in this file utilize the `stdio.h`, `stdlib.h`, and `time.h` libraries in their implementations.

`init1DCA` initalizes a 1DCA by setting all states to the **initialValue** parameter. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to 1DCA, `int` initialValue.

`set1DCACell` sets the state of a given cell in a 1DCA. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to 1DCA, `unsigned int` index of cell to be updated, `unsigned char` new state. **Note:** The function validates its input (index).

`display1DCA` displays the 1DCA in the format `x y z` where each letter represents a different cell, terminated with a new line. The function takes a single parameter; `CELLULAR_AUTOMATA*` pointer to 1DCA.


`create1DCA` creates a 1DCA given the number of cells and initialState. The function takes parameters; `int` number of cells, `unsigned char` initial (quiescent) state. The function returns a pointer to the created 1DCA. **Note:** The function returns `NULL` if it is unable to construct a 1DCA properly.


`stepCA` performs a single step on the 1DCA. The function takes parameters; `CELLULAR_AUTOMATA*` pointer to 1DCA, `unsigned char (*)(CELLULAR_AUTOMATA*, int)` pointer to function that acts as rule to be performed, `int` flag representing whether to wrap on edge cases.