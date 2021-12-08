# Cellular Automata ~~& Sand Painting~~

This program acts as a simulator which enables for constructing, manipulating, and displaying two-dimensional [Cellular Automata](https://mathworld.wolfram.com/ElementaryCellularAutomaton.html) (2DCA). The program allows a user to view and interact with the 2DCA at various steps of the [Game of Life rule](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

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
This repository includes sample text files [stable.txt](examples/stable.txt), [blinker.txt](examples/blinker.txt), and [glider.txt](examples/glider.txt), which represent cellular automaton their names imply.

---

Developed by [Christian Lisle](http://christianlisle.com)