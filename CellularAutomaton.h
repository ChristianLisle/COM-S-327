#include <string>
#include "GraphicsClient.h"

#ifndef CELLULAR_AUTOMATAON_
#define CELLULAR_AUTOMATAON_

using namespace std;

class CellularAutomaton {
  private:
    unsigned char* cells;
    unsigned char wrap;
    unsigned char quiescentState;
    unsigned int possibleStates; // TODO: is this needed?
    unsigned int width;
    unsigned int height;
    string file;
  public:
    CellularAutomaton(string, int);
    CellularAutomaton(CellularAutomaton&);
    ~CellularAutomaton();
    void operator=(const CellularAutomaton);
    void step(unsigned char (*rule)(CellularAutomaton*, int, int));
    void displayCA(GraphicsClient&);
    unsigned char* getCells() { return cells; };
    unsigned char getWrap() { return wrap; };
    unsigned char getQuiescentState() { return quiescentState; };
    unsigned int getPossibleStates() { return possibleStates; }; // TODO: is this needed?
    unsigned int getWidth() { return width; };
    unsigned int getHeight() { return height; };
};

#endif