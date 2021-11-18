#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "GraphicsClient.h"
#include "CellularAutomaton.h"

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
  fprintf(stdout, "width: %d\nheight: %d\n", width, height);

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

      setCell(x, y, state);
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

void CellularAutomaton::step(unsigned char (*rule)(CellularAutomaton*, int x, int y)) {
  unsigned char* newCells = (unsigned char*) malloc(width * height * sizeof(unsigned char));

  if (!newCells) {
    fprintf(stderr, "Unable to perform a step on the CA.\n");
  }

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      newCells[x + (y * width)] = (*rule)(this, x, y);
    }
  }

  free(cadata);

  cadata = newCells;
}

void CellularAutomaton::displayCA(GraphicsClient &client) {
  int m = max(width, height);
  int cellSize, gapSize;

  if (200 < m && m <= 600) {
    cellSize = 1;
    gapSize= 0;
  }
  else if (100 < m && m <= 200) {
    cellSize = 2;
    gapSize= 1;
  }
  else if (50 < m && m <= 100) {
    cellSize = 4;
    gapSize= 1;
  }
  else if (1 < m && m <= 50) {
    cellSize = 10;
    gapSize= 2;
  }
  else {
    fprintf(stderr, "There was an issue displaying the Cellular Automata.\n");
    return;
  }

  client.drawRectangle(0, 0, (width * (cellSize + gapSize)), (height * (cellSize + gapSize)));

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      int xCoord = x * (cellSize + gapSize);
      int yCoord = y * (cellSize + gapSize);
      if (getCell(x, y) == 1) {
        client.fillRectangle(xCoord, yCoord, cellSize, cellSize);
      }
    }
  }
}
