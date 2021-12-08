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

      setCell(x, y, state);
    }
  }

  fclose(inputFile);
}

CellularAutomaton::CellularAutomaton(int w, int h, int qState) {
  width = w;
  height = h;
  quiescentState = qState;

  cells = new unsigned char[w * h];

  if (!cells) {
    fprintf(stderr, "There was an issue creating the Cellular Automata.\n");
    return;
  }
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

void CellularAutomaton::displayCA(GraphicsClient &client, unsigned int containerSize) {
  int m = max(width, height);
  double cell = (0.8 * containerSize) / m, gap = (0.2 * containerSize) / m;

  int totalWidth = width * (cell + gap);
  int totalHeight = height * (cell + gap);

  int xStart = (600 - totalWidth) / 2;
  int yStart = (600 - totalHeight) / 2;

  client.setDrawingColor(2, 2, 2);
  client.fillRectangle(xStart, yStart, totalWidth, totalHeight);
  client.setDrawingColor(255, 255, 255);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int xCoord = (x * (cell + gap)) + xStart + (gap / 2);
      int yCoord = (y * (cell + gap)) + yStart + (gap / 2);

      if (cells[x + (y * width)] == 1) {
        client.fillRectangle(xCoord, yCoord, cell, cell);
      }
    }
  }
}

void CellularAutomaton::setCell(unsigned int x, unsigned int y, unsigned int state) {
  cells[x + (y * width)] = state;
}
