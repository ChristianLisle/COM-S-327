#include "ca.h"
#include <stdlib.h>
#include <stdio.h>

void printParameterInfo() {
  printf("\nThe expected parameters are:\n");
  printf("(1) Number of dimensions in CA (Must be 2).\n");
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
  const unsigned int width = ca -> width;
  const unsigned int height = ca -> height;
  const unsigned char qState = ca -> quiescentState;

  unsigned int xLeft, xRight, yAbove, yBelow;
  unsigned int left, right, above, below, aboveLeft, aboveRight, belowLeft, belowRight;

  // set left x
  if (x == 0) {
    if (ca -> wrap) {
      xLeft = width - 1;
    }
    else {
      xLeft = -1; // use qState
    }
  }
  else {
    xLeft = x - 1;
  }

  // set right x
  if (x == width - 1) {
    if (ca -> wrap) {
      xRight = 0;
    }
    else {
      xRight = -1; // use qState
    }
  }
  else {
    xRight = x + 1;
  }

  // set above y
  if (y == 0) {
    if (ca -> wrap) {
      yAbove = height - 1;
    }
    else {
      yAbove = -1; // use qState
    }
  }
  else {
    yAbove = y - 1;
  }

  // set below y
  if (y == height - 1) {
    if (ca -> wrap) {
      yBelow = 0;
    }
    else {
      yBelow = -1; // use qState
    }
  }
  else {
    yBelow = y + 1;
  }

  // Adjacent sides
  left = (xLeft == -1) ? qState : (ca -> cadata)[xLeft + (y * width)];
  right = (xRight == -1) ? qState : (ca -> cadata)[xRight + (y * width)];
  above = (yAbove == -1) ? qState : (ca -> cadata)[x + (yAbove * width)];
  below = (yBelow == -1) ? qState : (ca -> cadata)[x + (yBelow * width)];

  // top left
  if (xLeft == -1 || yAbove == -1) {
    aboveLeft = qState;
  }
  else {
    aboveLeft = (ca -> cadata)[xLeft + (yAbove * width)];
  }

  // top right
  if (xRight == -1 || yAbove == -1) {
    aboveRight = qState;
  }
  else {
    aboveRight = (ca -> cadata)[xRight + (yAbove * width)];
  }

  // bottom left
  if (xLeft == -1 || yBelow == -1) {
    belowLeft = qState;
  }
  else {
    belowLeft = (ca -> cadata)[xLeft + (yBelow * width)];
  }

  // bottom right
  if (xRight == -1 || yBelow == -1) {
    belowRight = qState;
  }
  else {
    belowRight = (ca -> cadata)[xRight + (yBelow * width)];
  }

  // Count alive neighboring cells
  unsigned int aliveNeighbors = 0;
  aliveNeighbors += (aboveLeft != 0);
  aliveNeighbors += (above != 0);
  aliveNeighbors += (aboveRight != 0);
  aliveNeighbors += (left != 0);
  aliveNeighbors += (right != 0);
  aliveNeighbors += (belowLeft != 0);
  aliveNeighbors += (below != 0);
  aliveNeighbors += (belowRight != 0);

  unsigned char currentCell = (ca -> cadata)[x + (y * width)];

  if (currentCell != 0) {
    if (2 <= aliveNeighbors && aliveNeighbors <= 3) {
      return 1;
    }

    return 0;
  }
  else if (aliveNeighbors == 3) {
    return 1;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int isValidParameters = validateParameters(argc, argv);
  if (!isValidParameters) return 0;

  FILE* inputFile;
  inputFile = fopen(argv[2], "r");

  if (!inputFile) {
    fprintf(stderr, "There was an issue opening the File \"%s\"\n", argv[2]);
    return 0;
  }

  unsigned int width, height;
  fscanf(inputFile, "%d %d", &height, &width);

  CELLULAR_AUTOMATA* ca = create2DCA(width, height, '0');
  ca -> wrap = 1;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      unsigned int state;
      fscanf(inputFile, "%d", &state);

      set2DCACell(ca, x, y, state);
    }
  }

  fclose(inputFile);
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