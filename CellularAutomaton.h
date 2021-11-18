#include <string>
#include "GraphicsClient.h"

#ifndef CELLULAR_AUTOMATAON_
#define CELLULAR_AUTOMATAON_

using namespace std;

class CellularAutomaton {
  private:
    unsigned char* cadata;
    unsigned char wrap;
    unsigned char quiescentState;
    unsigned int possibleStates;
    unsigned int width;
    unsigned int height;
    string file;
    void setCell(unsigned int x, unsigned int y, unsigned char state) {
      cadata[x + (y * width)] = state;
    };
    unsigned char getCell(unsigned int x, unsigned int y) {
      return cadata[x + (y * width)];
    };
  public:
    CellularAutomaton(string, int);
    CellularAutomaton(CellularAutomaton&);
    ~CellularAutomaton();
    void operator=(const CellularAutomaton);
    void step(unsigned char (*rule)(CellularAutomaton*, int, int));
    void displayCA(GraphicsClient&);
};

#endif