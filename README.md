# Cellular Automata & Sand Painting

This program enables for constructing, manipulating, and displaying a one-dimensional [Cellular Automata](https://mathworld.wolfram.com/ElementaryCellularAutomaton.html) (1DCA).

View more about how the program works in [DEVELOPERS.md](DEVELOPERS.md).

### Running the program
1. Compile the program

        make

2. Run the program with 5 parameters

        ./odca.out <1> <2> <3> <4> <5>

#### Parameters (required)
```
(1) Integer between 10 and 100 representing the number of cells in the 1DCA.
(2) Natural number representing the states possible for each cell.
(3) Flag indicating whether the simulation wraps or not for edge cases.
    Allowed values:
    * wrap
    * nowrap
(4) Integer representing the initial state of cells.
    Allowed values:
    * 0 through (parameter 2 value - 1)
    * -1 for randomly assigned number
(5) Natural number representing the number of steps to simulate the 1DCA.
```

---
Developed by [Christian Lisle](http://christianlisle.com)