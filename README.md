# Cellular Automata & Sand Painting (WORK IN PROGRESS)

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

1. Run the program

```bash
./simulator.out
```

#### Provided Sample 2DCA
This repository includes sample text files [stable.txt](stable.txt), [blinker.txt](blinker.txt), and [glider.txt](glider.txt), which behave as their names would imply. The behavior is possible because of the [Game of Life rule](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

---

Developed by [Christian Lisle](http://christianlisle.com)