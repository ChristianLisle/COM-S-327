#include <stdio.h>
#include <iostream>
#include "CellularAutomaton.h"
#include "Simulator.h"

using namespace std;

void printParameterInfo() {
  // TODO
}

int validateParameters(int argc, char *argv[]) {
  // TODO
  return 1;
}

unsigned char gameOfLifeRule(CellularAutomaton* ca, int x, int y) {
  const unsigned int width = ca -> getWidth();
  const unsigned int height = ca -> getHeight();
  const unsigned char qState = ca -> getQuiescentState();
	const unsigned char wrap = ca -> getWrap();
	const unsigned char* cells = ca -> getCells();

  unsigned int xLeft, xRight, yAbove, yBelow;
  unsigned int left, right, above, below, aboveLeft, aboveRight, belowLeft, belowRight;

  // set left x
  if (x == 0) {
    if (wrap) {
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
    if (wrap) {
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
    if (wrap) {
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
    if (wrap) {
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
  left = (xLeft == -1) ? qState : (cells)[xLeft + (y * width)];
  right = (xRight == -1) ? qState : (cells)[xRight + (y * width)];
  above = (yAbove == -1) ? qState : (cells)[x + (yAbove * width)];
  below = (yBelow == -1) ? qState : (cells)[x + (yBelow * width)];

  // top left
  if (xLeft == -1 || yAbove == -1) {
    aboveLeft = qState;
  }
  else {
    aboveLeft = (cells)[xLeft + (yAbove * width)];
  }

  // top right
  if (xRight == -1 || yAbove == -1) {
    aboveRight = qState;
  }
  else {
    aboveRight = (cells)[xRight + (yAbove * width)];
  }

  // bottom left
  if (xLeft == -1 || yBelow == -1) {
    belowLeft = qState;
  }
  else {
    belowLeft = (cells)[xLeft + (yBelow * width)];
  }

  // bottom right
  if (xRight == -1 || yBelow == -1) {
    belowRight = qState;
  }
  else {
    belowRight = (cells)[xRight + (yBelow * width)];
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

  unsigned char currentCell = (cells)[x + (y * width)];

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

	string filename = argv[1];
	CellularAutomaton* ca = new CellularAutomaton(filename, 0);


  Simulator* sim = new Simulator(ca, "127.0.0.1", 7777);
  sim -> open();

	return 0;
}