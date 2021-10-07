#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ca.h"

void init1DCA(CELLULAR_AUTOMATA* cellularAutomata, int initialValue) {
  if (initialValue == -1) srand(time(NULL)); // Initialize random function

  for (int i = 0; i < cellularAutomata -> numCells; i++) {
    unsigned int state = (initialValue != -1) ? initialValue : rand() % (cellularAutomata -> possibleStates);
    set1DCACell(cellularAutomata, i, state);
  }
}

int set1DCACell(CELLULAR_AUTOMATA* cellularAutomata, unsigned int index, unsigned char value) {
  if (index < 0 || cellularAutomata -> numCells <= index) {
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
  CELLULAR_AUTOMATA* cellularAutomata = malloc(sizeof(CELLULAR_AUTOMATA));

  if (!cellularAutomata) return NULL;

  cellularAutomata -> cells = malloc(numCells * sizeof(unsigned char));

  if (!(cellularAutomata -> cells)) {
    free(cellularAutomata);
    return NULL;
  }

  cellularAutomata -> numCells = numCells;
  cellularAutomata -> quiescentState = initialState;

  return cellularAutomata;
}

void stepCA(CELLULAR_AUTOMATA* cellularAutomata, unsigned char (*performRule)(CELLULAR_AUTOMATA*, int), int flag) {
  cellularAutomata -> wrapFlag = flag;

  unsigned char* newCells = malloc((cellularAutomata -> numCells) * sizeof(CELLULAR_AUTOMATA));

  for (int i = 0; i < cellularAutomata -> numCells; i++) {
    newCells[i] = (*performRule)(cellularAutomata, i);
  }

  free(cellularAutomata -> cells);

  cellularAutomata -> cells = newCells;
}