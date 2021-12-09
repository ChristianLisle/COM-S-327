## COM S 327 - Advanced Programming Techniques

This is an archive of the semester-long project from the course Computer Science 327 (Advanced Programming Techniques) at Iowa State University in the fall of 2021.

This course covered various topics and challenged students to become proficient in languages C and C++.

This project ended up becomming a Cellular Automaton siulator, and was completed in 5 parts (1a, 1b, 1c, 2a, and 2b). All of these parts can be visited in the commit history, with their respective assignment document. The final assignment document is [Project2B.pdf](Project2B.pdf).

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