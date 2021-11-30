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
    int isPlaying;
    int size;
  public:
    Simulator(string url, int port);
    Simulator(Simulator&);
    ~Simulator();
    void operator=(const Simulator);
    void rerender();
    Click listen();
    void handleClick(int, int);
    void step(unsigned char (*rule)(CellularAutomaton*, int, int));
    void togglePlayback();
    int getPlaybackStatus() { return isPlaying; };
    void quit() { exit(0); };
    void load();
    void clear();
    void randomize();
};

#endif