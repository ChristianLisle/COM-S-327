#include <stdio.h>

void init1DCA(int numCells, unsigned char* cellularAutomata) {
  for (int i = 0; i < numCells; i++) {
    cellularAutomata[i] = 0;
  }
}

void set1DCACell(unsigned char* cellularAutomata, int index, unsigned char updatedState) {
  if (index < 0) {
    return;
  }

  cellularAutomata[index] = updatedState;
}

void display1DCA(unsigned char* cellularAutomata, int numCells) {
  for (int i = 0; i < numCells; i++) {
    printf("%d ", cellularAutomata[i]);
  }

  printf("\n");
}