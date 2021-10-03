#include <stdlib.h>
#include <stdio.h>
#include "ca.h"

void init1DCA(CELLULAR_AUTOMATA* cellularAutomata, int initialValue) {
  for (int i = 0; i < cellularAutomata -> numCells; i++) {
    int isSetSuccessful = set1DCACell(cellularAutomata, i, initialValue);

    // TODO: determine if I need to even handle set1DCACell behavior here
    if (!isSetSuccessful) return;
  }
}

int set1DCACell(CELLULAR_AUTOMATA* cellularAutomata, unsigned int index, unsigned char value) {
  if (index < 0 || index > cellularAutomata -> numCells) {
    return 0;
  }

  (cellularAutomata -> cells)[index] = value;
  
  return 1;
}

void display1DCA(CELLULAR_AUTOMATA* cellularAutomata) {
  for (int i = 0; i < cellularAutomata -> numCells; i++) {
    printf("%d ", (cellularAutomata -> cells)[i]);
  }

  printf("\n");
}

CELLULAR_AUTOMATA* create1DCA(int numCells, unsigned char initialState) {
  printf("value: %d\n", initialState);
  CELLULAR_AUTOMATA* cellularAutomata = malloc(sizeof(CELLULAR_AUTOMATA));

  if (!cellularAutomata) return NULL;

  cellularAutomata -> cells = malloc(numCells * sizeof(unsigned char));

  if (!(cellularAutomata -> cells)) {
    free(cellularAutomata);
    return NULL;
  }

  cellularAutomata -> numCells = numCells;
  init1DCA(cellularAutomata, initialState);

  return cellularAutomata;
}

void stepCA(CELLULAR_AUTOMATA* cellularAutomata, unsigned char (*performRule)(CELLULAR_AUTOMATA*, int), int flag) {
  // TODO
}