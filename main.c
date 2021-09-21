#include "dca1d.h"

int main(void) {
  unsigned char cellularAutomata[25];

  init1DCA(25, cellularAutomata);

  for (int i = 0; i < 25; i++) {
    if (i % 2 == 0) {
      set1DCACell(cellularAutomata, i, 2);
    }
    else {
      set1DCACell(cellularAutomata, i, 1);
    }
  }

  display1DCA(cellularAutomata, 25);
}