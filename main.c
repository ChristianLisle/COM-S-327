#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ca.h"

const unsigned int MIN_CELLS = 10;
const unsigned int MAX_CELLS = 100;

void printParameterInfo() {
  printf("\nThe expected parameters are:\n");
  printf("(1) Integer between 10 and 100 representing the number of cells in the 1DCA.\n");
  printf("(2) 1 or 2 representing the states possible for each cell.\n");
  printf("(3) Flag indicating whether the simulation wraps or not for edge cases.\n    Allowed values:\n    * wrap\n    * nowrap\n");
  printf("(4) Integer representing the initial state of cells.\n    Allowed values:\n    * 0 through (parameter 2 value - 1)\n    * -1 for randomly assigned number\n");
  printf("(5) Natural number representing the number of steps to simulate the 1DCA.\n");
}

int validateParameters(int argc, char *argv[]) {
  if (argc != 6) {
    fprintf(stderr, "This program expects 5 parameters, but %d parameter were passed in.\n", (argc - 1));
    printParameterInfo();
    return 0;
  }

  int hasInvalidParameter = 0;
  const int parameter1 = atoi(argv[1]);
  const int parameter2 = atoi(argv[2]);
  const int parameter4 = atoi(argv[4]);
  const int parameter5 = atoi(argv[5]);

  if (parameter1 < MIN_CELLS || MAX_CELLS < parameter1) {
    fprintf(stderr, "Invalid first parameter, \"%s\".\n", argv[1]);
    hasInvalidParameter = 1;
  }

  if (parameter2 < 1 || 2 < parameter2) {
    fprintf(stderr, "Invalid second parameter, \"%s\".\n", argv[2]);
    hasInvalidParameter = 1;
  }

  if (*argv[3] != *"wrap" && *argv[3] != *"nowrap") {
    fprintf(stderr, "Invalid third parameter, \"%s\".\n", argv[3]);
    hasInvalidParameter = 1;
  }

  if (parameter4 < -1 || parameter2 <= parameter4) {
    fprintf(stderr, "Invalid fourth parameter, \"%s\".\n", argv[4]);
    hasInvalidParameter = 1;
  }

  if (parameter5 < 0) {
    fprintf(stderr, "Invalid fifth parameter, \"%s\".\n", argv[4]);
    hasInvalidParameter = 1;
  }

  if (hasInvalidParameter) {
    printParameterInfo();
    return 0;
  }
  return 1;
}

unsigned char rule110(CELLULAR_AUTOMATA* cellularAutomata, int index) {
  unsigned char middle = (cellularAutomata -> cells)[index];
  unsigned char left, right;

  if (index == 0) {
    if (cellularAutomata -> wrapFlag) {
      left = (cellularAutomata -> cells)[cellularAutomata -> numCells - 1];
    }
    else {
      left = cellularAutomata -> quiescentState;
    }
  }
  else {
    left = (cellularAutomata -> cells)[index - 1];
  }
  
  if (index + 1 == cellularAutomata -> numCells) {
    if (cellularAutomata -> wrapFlag) {
      right = (cellularAutomata -> cells)[0];
    }
    else {
      right = cellularAutomata -> quiescentState;
    }
  }
  else {
    right = (cellularAutomata -> cells)[index + 1];
  }

  if (left != 0 && middle != 0 && right != 0) {
    return 0;
  }
  else if (left != 0 && middle == 0 && right == 0) {
    return 0;
  }
  else if (left == 0 && middle == 0 && right == 0) {
    return 0;
  }

  return 1;
}

int main(int argc, char *argv[]) {
  int isValidParameters = validateParameters(argc, argv);
  if (!isValidParameters) return 0;

  const unsigned int numCells = atoi(argv[1]);
  const unsigned int possibleStates = atoi(argv[2]);
  const unsigned int wrapFlag = !strcmp("wrap", argv[3]);
  const int initialState = atoi(argv[4]);
  const unsigned int numSteps = atoi(argv[5]);

  const unsigned int quiescentState = (initialState == -1) ? 0 : initialState;

  CELLULAR_AUTOMATA* cellularAutomata = create1DCA(numCells, quiescentState);

  if (!cellularAutomata) {
    fprintf(stderr, "Error occured while creating 1DCA\n");
    exit(1);
  }

  cellularAutomata -> possibleStates = possibleStates;

  init1DCA(cellularAutomata, initialState);
  display1DCA(cellularAutomata);

  for (int i = 0; i < numSteps; i++) {
    stepCA(cellularAutomata, rule110, wrapFlag);
    display1DCA(cellularAutomata);
  }

  free(cellularAutomata -> cells);
  free(cellularAutomata);
}