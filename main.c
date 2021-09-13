#include "dca1d.h"

int main(void) {
  // 25 cells wide
  // odd cell indices: 1
  // even cell indices: 2
  // then print all cell indices

  char cellularAutomata[25];

  init1DCA(25, cellularAutomata);

  display1DCA(cellularAutomata, 25);
}