# Cellular Automata & Sand Painting (WORK IN PROGRESS)

This program enables for constructing, manipulating, and displaying a one-dimensional [Cellular Automata](https://mathworld.wolfram.com/ElementaryCellularAutomaton.html) (1DCA).

View more about how the program works in [DEVELOPERS.md](DEVELOPERS.md).

### Running the program
1. Compile the program

        make

2. Run the program with 5 parameters

        ./odca.out <1> <2>

#### Parameters (required)
```
(1) Number of dimensions in CA (1 or 2)
(2) Filename (include the path, if necessary) to a file that gives the dimensions and initial state of a 2-Dimensional CA. The format of this file is a text file that contains integers seperated by spaces or new lines. The first two numbers in the file are the number of rows and columns. The rest of data (rows * columns) is the initial state of the CA.
```

---
Developed by [Christian Lisle](http://christianlisle.com)