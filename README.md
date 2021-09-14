# Cellular Automata & Sand Painting

This program enables for constructing, manipulating, and displaying a one-dimensional [Cellular Automata](https://mathworld.wolfram.com/ElementaryCellularAutomaton.html) (1DCA).

### How the program works
The [`main.c`](main.c) file includes the main method, which references the [`dca1d.h`](dca1d.h) header file that implements functions implemented within [`dca1d.c`](dca1d.c).

In its current state, the program initializes a 1DCA, of length 25, with all states set to **0**. The program then sets all states of odd indices to **1**, and all states of even indices to **2**. The program then displays the updated 1DCA.

#### 1DCA Functions

`init1DCA` initalizes a 1DCA by setting all states to **0**. The function takes parameters; `int` number of cells in 1DCA, `unsigned char*` pointer to 1DCA.

`set1DCACell` sets the state of a given cell in a 1DCA. The function takes parameters; `unsigned char*` pointer to 1DCA, `int` index of cell to be updated, `unsigned char` new state. **Note:** The function validates its input (index).

``display1DCA`` displays the 1DCA in the format `x y z` where each letter represents a different cell, terminated with a new line. The function takes parameters; `unsigned char*` pointer to 1DCA, `int` number of cells in 1DCA.

This function initializes all states of the provided

[Christian Lisle](http://christianlisle.com)