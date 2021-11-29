#include "GraphicsClient.h"
#include "CellularAutomaton.h"

#ifndef SIMULATOR_
#define SIMULATOR_

using namespace std;

class Simulator {
  private:
    GraphicsClient* client;
    CellularAutomaton* ca;
  public:
    Simulator(CellularAutomaton*, string url, int port);
    Simulator(Simulator&);
    ~Simulator();
    void operator=(const Simulator);
    void open();
    void step(unsigned char (*rule)(CellularAutomaton*, int, int));
    void run();
    void pause();
    void quit();
    void load();
    void clear();
    void randomize();
};

#endif