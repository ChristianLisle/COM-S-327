# Cellular Automata & Sand Painting

This program enables for constructing, manipulating, and displaying a two-dimensional [Cellular Automata](https://mathworld.wolfram.com/ElementaryCellularAutomaton.html) (2DCA). The program allows a user to view the 2DCA through any number of steps of the [Game of Life rule](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

View more about how the program works in [DEVELOPERS.md](DEVELOPERS.md).

### Running the program
1. Compile the program

        make

2. Run the program with 2 parameters

        ./gol <1> <2>

#### Parameters (required)
```
(1) Number of dimensions in CA (Must be 2, since only two-dimensional CA are allowed).
(2) Filename (include the path, if necessary) to a file that gives the dimensions and initial state of a 2-Dimensional CA. The format of this file is a text file that contains integers seperated by spaces or new lines. The first two numbers in the file are the number of rows and columns. The rest of data (rows * columns) is the initial state of the CA.
```

#### Provided Sample 2DCA
This repository includes sample text files [stable.txt](stable.txt), [blinker.txt](blinker.txt), and [glider.txt](glider.txt), which behave as their names would imply. The behavior is possible because of the [Game of Life rule](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

---

Developed by [Christian Lisle](http://christianlisle.com)