#include "ca.h"
#include <stdlib.h>
#include <stdio.h>

void printParameterInfo() {
  printf("\nThe expected parameters are:\n");
  printf("(1) Number of dimensions in CA (1 or 2)\n");
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

  if (param1 != 1 && param1 != 2) {
    fprintf(stderr, "Invalid first parameter, \"%s\".\n", argv[1]);
    hasInvalidParameter = 1;
  }

  // TODO: Figure out why this is causing segFault. View Piazza question @230
  /*FILE* file;
  file = fopen(argv[2], "r");
  
  if (!file) {
    fprintf(stderr, "Invalid second parameter. File \"%s\" could not be opened", *argv[2]);
    hasInvalidParameter = 1;
  }
  else {
    fclose(file);
  }*/

  if (hasInvalidParameter) {
    printParameterInfo();
    return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int isValidParameters = validateParameters(argc, argv);
  if (!isValidParameters) return 0;

  // TODO
}