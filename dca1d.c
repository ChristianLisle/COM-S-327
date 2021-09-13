#include <stdio.h>

void init1DCA(int numCells, int* arrayPointer) {
  unsigned char cellularAutomata[numCells];

  // arrayPointer = cellularAutomata[0];

  for (int i = 0; i < numCells; i++) {
    cellularAutomata[i] = 0;
  }
}

void set1DCACell(int* arrayPointer, int index, unsigned char updatedState) {
  if (index < 0) {
    return;
  }

  // char cellularAutomata[index];
}

void display1DCA(int* arrayPointer, int numCells) {
  printf("%d\n", *arrayPointer);

  for (int i = 0; i < numCells; i++) {
    int* address = *arrayPointer + i;
    printf("%c ", *address);
    // printf("x ");
  }

  printf("\n");
}