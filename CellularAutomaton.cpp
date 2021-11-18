#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "GraphicsClient.h"
#include "CellularAutomaton.h"

// int setCell(unsigned char* cells, unsigned int x, unsigned int y, unsigned char state) {
//   unsigned int index = x + (y * width);
//   if (width * height <= index) {
//     return 0;
//   }

//   cells[index] = state;

//   return 1;
// }

CellularAutomaton::CellularAutomaton(string filename, int qState) {
  file = filename;
  quiescentState = qState;
  wrap = 1;

  // TODO: validate filename
  FILE* inputFile;
  inputFile = fopen(file.c_str(), "r");

  if (!inputFile) {
    fprintf(stderr, "There was an issue opening the File \"%s\"\n", file.c_str());
    return;
  }

  fscanf(inputFile, "%d %d", &height, &width);

  // Create CA
  cadata = (unsigned char *) malloc(width * height * sizeof(unsigned char));

  if (!cadata) {
    fprintf(stderr, "There was an issue creating the Cellular Automata.\n");
    return;
  }

  // Fill CA
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      unsigned int state;
      fscanf(inputFile, "%d", &state);

      setCell(cadata, x, y, state);
    }
  }

  fclose(inputFile);
}

CellularAutomaton::CellularAutomaton(CellularAutomaton &other) {
  CellularAutomaton(other.file, other.quiescentState);
}

CellularAutomaton::~CellularAutomaton() {
  // TODO
}

void CellularAutomaton::operator=(const CellularAutomaton rhs) {
  CellularAutomaton(rhs.file, rhs.quiescentState);
}

void step(unsigned char (*rule)(CellularAutomaton*, int x, int y)) {
  // TODO
}

void displayCA(GraphicsClient &client) {
  // TODO
}
