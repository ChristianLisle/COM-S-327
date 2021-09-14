## Documentation

The [`main.c`](main.c) file includes the main method, which references the [`dca1d.h`](dca1d.h) header file that implements functions implemented within [`dca1d.c`](dca1d.c).

In its current state, the program initializes a 1DCA, of length 25, with all states set to **0**. The program then sets all states of odd indices to **1**, and all states of even indices to **2**. The program then displays the updated 1DCA.

---
## Files & Functions

#### `main.c`

`main` is the application that builds a 1DCA. Currently, the app builds a 1DCA of length 25, sets all states at odd indices to 1 and all states at even indices to 2, and then displays the 1DCA.

#### `dca1d.h`

This is the header file which defines all functions contained in `dca1d.c` file, so they are readily accessable to files such as `main.c`.

#### `dca1d.c`

This is the file that performs all of the manipulation of states in a 1DCA. The file includes the `stdio.h` module so that it can output in the `display1DCA` function.

`init1DCA` initalizes a 1DCA by setting all states to **0**. The function takes parameters; `int` number of cells in 1DCA, `unsigned char*` pointer to 1DCA.

`set1DCACell` sets the state of a given cell in a 1DCA. The function takes parameters; `unsigned char*` pointer to 1DCA, `int` index of cell to be updated, `unsigned char` new state. **Note:** The function validates its input (index).

`display1DCA` displays the 1DCA in the format `x y z` where each letter represents a different cell, terminated with a new line. The function takes parameters; `unsigned char*` pointer to 1DCA, `int` number of cells in 1DCA.