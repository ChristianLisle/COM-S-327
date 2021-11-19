# Cellular Automata & Sand Painting

This program enables for constructing, manipulating, and displaying a two-dimensional [Cellular Automata](https://mathworld.wolfram.com/ElementaryCellularAutomaton.html) (2DCA). The program allows a user to view the 2DCA through any number of steps of the [Game of Life rule](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

View more about how the program works in [DEVELOPERS.md](DEVELOPERS.md).

### Running the program

1. Start the Graphics Server

```bash
java -jar GraphicsServer.jar
```

1. Compile the program

```bash
make
```

3. Run the program with 1 parameter

```bash
./a.out <1>
```

#### Parameters (required)
```
(1) Filename (include the path, if necessary) to a file that gives the dimensions and initial state of a 2-Dimensional CA. The format of this file is a text file that contains integers seperated by spaces or new lines. The first two numbers in the file are the number of rows and columns. The rest of data (rows * columns) is the initial state of the CA.
```

#### Provided Sample 2DCA
This repository includes sample text files [stable.txt](stable.txt), [blinker.txt](blinker.txt), and [glider.txt](glider.txt), which behave as their names would imply. The behavior is possible because of the [Game of Life rule](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

---

Developed by [Christian Lisle](http://christianlisle.com)