#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "GraphicsClient.h"
#include "CellularAutomaton.h"

CellularAutomaton::CellularAutomaton(string filename, int qState) {
  file = filename;
  quiescentState = qState;
  wrap = 1;

  FILE* inputFile;
  inputFile = fopen(file.c_str(), "r");

  if (!inputFile) {
    fprintf(stderr, "There was an issue opening the file \"%s\"\n", file.c_str());
    return;
  }

  fscanf(inputFile, "%d %d", &height, &width);

  cells = new unsigned char[width * height];

  if (!cells) {
    fprintf(stderr, "There was an issue creating the Cellular Automata.\n");
    return;
  }

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      unsigned int state;
      fscanf(inputFile, "%d", &state);

      cells[x + (y * width)] = state;
    }
  }

  fclose(inputFile);
}

CellularAutomaton::CellularAutomaton(CellularAutomaton &other) {
  CellularAutomaton(other.file, other.quiescentState);
}

CellularAutomaton::~CellularAutomaton() {
  delete cells;
}

void CellularAutomaton::operator=(const CellularAutomaton rhs) {
  CellularAutomaton(rhs.file, rhs.quiescentState);
}

void CellularAutomaton::step(unsigned char (*rule)(CellularAutomaton*, int, int)) {
  unsigned char* newCells = new unsigned char[width * height];

  if (!newCells) {
    fprintf(stderr, "Unable to perform a step on the CA.\n");
    return;
  }

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      newCells[x + (y * width)] = (*rule)(this, x, y);
    }
  }

  delete cells;

  cells = newCells;
}

void CellularAutomaton::displayCA(GraphicsClient &client) {
  int m = max(width, height);
  int cellSize, gapSize;

  if (200 < m && m <= 600) {
    cellSize = 1;
    gapSize = 0;
  }
  else if (100 < m && m <= 200) {
    cellSize = 2;
    gapSize = 1;
  }
  else if (50 < m && m <= 100) {
    cellSize = 4;
    gapSize = 1;
  }
  else if (1 < m && m <= 50) {
    cellSize = 10;
    gapSize = 2;
  }
  else {
    fprintf(stderr, "The Cellular Automata has a width or height that cannot be displayed.\n");
    return;
  }

  client.setDrawingColor(255, 255, 255);
  client.drawRectangle(0, 0, (width * (cellSize + gapSize)), (height * (cellSize + gapSize)));

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int xCoord = x * (cellSize + gapSize);
      int yCoord = y * (cellSize + gapSize);
      if (cells[x + (y * width)] == 1) {
        client.fillRectangle(xCoord, yCoord, cellSize, cellSize);
      }
    }
  }
}
