#include <stdio.h>
#include <string.h>
#include "ca.h"

void printParameterInfo() {
  printf("The expected parameters are:\n");
  printf("1: Integer between 10 and 100, representing the number of cells in the 1DCA.\n");
  printf("2: Integer of states possible for each cell.\n");
  printf("3: Flag indicating whether the simulation wraps or not at the edge. Allowed values: \"wrap\", \"nowrap\".\n");
  printf("4: Integer representing the initial state of cells in the 1DCA (range 0 =< x < parameter 2 value). Optionally use \"-1\" for randomly assigned number.\n");
  printf("5: Integer representing the number of steps to simulate the 1DCA.\n");
}

int validateParameters(int argc, char *argv[]) {
  if (argc != 6) {
    fprintf(stdout, "This program expects 5 parameters, but %d parameters were passed in.\n", (argc - 1));
    printParameterInfo();
    return 0;
  }

  int hasInvalidParameter = 0;

  if (*argv[1] < 10 || 100 < *argv[1]) {
    fprintf(stdout, "Invalid first parameter, \"%s\".\n", argv[1]);
    hasInvalidParameter = 1;
  }

  if (argv[2] < 0) {
    fprintf(stdout, "Invalid second parameter, \"%s\".\n", argv[2]);
    hasInvalidParameter = 1;
  }

  if (*argv[3] != *"wrap" && *argv[3] != *"nowrap") {
    fprintf(stdout, "Invalid third parameter, \"%s\".\n", argv[3]);
    hasInvalidParameter = 1;
  }

  if (argv[4] < "-1" || 0 >= strcmp(argv[2], argv[4])) {
    printf("%d\n", strcmp(argv[2], argv[4]) );
    fprintf(stdout, "Invalid fourth parameter, \"%s\".\n", argv[4]);
    hasInvalidParameter = 1;
  }

  if (argv[5] < 0) {
    fprintf(stdout, "Invalid fifth parameter, \"%s\".\n", argv[4]);
    hasInvalidParameter = 1;
  }

  if (hasInvalidParameter) {
    printParameterInfo();
    return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int isValidParameters = validateParameters(argc, argv);
  if (!isValidParameters) return 0;

  const unsigned int numCells = *argv[1];
  const unsigned int possibleStates = *argv[2];
  // const char flag[6] = argv[3];
  const char* initialState = argv[4];
  const unsigned int numSteps = *argv[5];
  printf("%s\n", initialState); // TODO: delete


  
  CELLULAR_AUTOMATA* cellularAutomata = create1DCA(numCells, -1);

  display1DCA(cellularAutomata);



  // unsigned char cellularAutomata[25];

  // init1DCA(25, cellularAutomata);

  // for (int i = 0; i < 25; i++) {
  //   if (i % 2 == 0) {
  //     set1DCACell(cellularAutomata, i, 2);
  //   }
  //   else {
  //     set1DCACell(cellularAutomata, i, 1);
  //   }
  // }

  // display1DCA(cellularAutomata, 25);
}

unsigned char aRule(CELLULAR_AUTOMATA* cellularAutomata, int index) {
  // TODO
}