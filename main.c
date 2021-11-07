#include "ca.h"
#include <stdlib.h>
#include <stdio.h>

void printParameterInfo() {
  printf("\nThe expected parameters are:\n");
  printf("(1) Number of dimensions in CA (1 or 2). MUST BE 2 for this program\n");
  printf("(2) Filename (include the path, if necessary) to a file that gives the dimensions and initial state of a 2-Dimensional CA. The format of this file is a text file that contains integers seperated by spaces or new lines. The first two numbers in the file are the number of rows and columns. The rest of data (rows * columns) is the initial state of the CA.\n");
}

int validateParameters(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "This program expects 2 parameters, but %d parameters were passed in.\n", (argc - 1));
    printParameterInfo();
    return 0;
  }

  int hasInvalidParameter = 0;
  const int param1 = atoi(argv[1]);

  if (param1 != 2) {
    fprintf(stderr, "Invalid first parameter, \"%s\".\n", argv[1]);
    hasInvalidParameter = 1;
  }

  FILE* file;
  file = fopen(argv[2], "r");

  if (!file) {
    fprintf(stderr, "Invalid second parameter. File \"%s\" could not be opened", argv[2]);
    hasInvalidParameter = 1;
  }
  else {
    fclose(file);
  }

  if (hasInvalidParameter) {
    printParameterInfo();
    return 0;
  }
  return 1;
}

unsigned char gameOfLifeRule(CELLULAR_AUTOMATA* ca, int x, int y) {
  if (ca -> wrap) {
    // TODO

  }
  else {
    // TODO
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int isValidParameters = validateParameters(argc, argv);
  if (!isValidParameters) return 0;

  FILE* inputFile;
  inputFile = fopen(argv[2], "r");

  if (!inputFile) {
    fprintf(stderr, "There was an issue opening the File \"%s\".", argv[2]);
    return 0;
  }

  unsigned int width, height;
  fscanf(inputFile, "%d %d", &height, &width);

  CELLULAR_AUTOMATA* ca = create2DCA(width, height, '0');
  ca -> wrap = ""; // TODO: FIGURE OUT WHAT TO SET THIS TO!!!! SEE PIAZZA @256

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      unsigned int state;
      fscanf(inputFile, "%d", &state);

      set2DCACell(ca, x, y, state);
    }
  }

  displayCA(ca);

  unsigned char input;
  scanf("%c", &input);

  while (input == '\n') {
    step2DCA(ca, gameOfLifeRule);
    displayCA(ca);

    scanf("%c", &input);
  }

  free(ca);

  return 0;
}