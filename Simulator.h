#include "GraphicsClient.h"
#include "CellularAutomaton.h"

#ifndef SIMULATOR_
#define SIMULATOR_

using namespace std;

typedef struct MouseClick {
  int success, type, button, x, y;
} Click;

class Simulator {
  private:
    GraphicsClient* client;
    CellularAutomaton* ca;
    string file;
    unsigned char (*rule)(CellularAutomaton*, int, int);
    int status;
    int size;
    void renderCA();
    void renderControlPanel();
    void renderAll();
    void reset();
    void load();
    void clear();
    void randomize();
    void togglePlayback() { status ^= 1; };
    void quit() { status = -1; };
  public:
    Simulator(string url, int port, unsigned char (*caRule)(CellularAutomaton*, int, int));
    Simulator(Simulator&);
    ~Simulator();
    void step();
    void operator=(const Simulator);
    Click listen();
    void handleClick(int, int);
    int getStatus() { return status; };
};

#endif