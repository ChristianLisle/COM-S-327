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
    int setCell(unsigned char* cells, unsigned int x, unsigned int y, unsigned char state) {
      unsigned int index = x + (y * width);
      if (width * height <= index) {
        return 0;
      }

      cells[index] = state;

      return 1;
    }
  public:
    CellularAutomaton(string, int);
    CellularAutomaton(CellularAutomaton&);
    ~CellularAutomaton();
    void operator=(const CellularAutomaton);
    void step(unsigned char (*rule)(CellularAutomaton*, int, int));
    void display(GraphicsClient);
};

#endif