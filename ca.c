#include "ca.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initCA(CELLULAR_AUTOMATA* ca, int state) {
  if (state == -1) srand(time(NULL)); // Initialize random function

  if (ca -> dimension == '1') {
    for (int i = 0; i < ca -> width; i++) {
      unsigned int newState = (state != -1) ? state : rand() % (ca -> possibleStates);
      set1DCACell(ca, i, newState);
    }
  }
  else {
    for (int y = 0; y < ca -> height; y++) {
      for (int x = 0; x < ca -> width; x++) {
        unsigned int newState = (state != -1) ? state : rand() % (ca -> possibleStates);
        set2DCACell(ca, x, y, newState);
      }
    }
  }
}

int set1DCACell(CELLULAR_AUTOMATA* ca, unsigned int x, unsigned char state) {
  if (ca -> width <= x || ca -> dimension != '1') {
    return 0;
  }
  
  (ca -> cadata)[x] = state;

  return 1;
}

int set2DCACell(CELLULAR_AUTOMATA* ca, unsigned int x, unsigned int y, unsigned char state) {
  unsigned int index = x + (y * (ca -> width));
  if ((ca -> width) * (ca -> height) <= index) {
    return 0;
  }

  (ca -> cadata)[index] = state;

  return 1;
}

void displayCA(CELLULAR_AUTOMATA* ca) {
  if (ca -> dimension == '1') {
    for (int i = 0; i < ca -> width; i++) {
      printf("%d ", (ca -> cadata)[i]);
    }

    printf("\n");
  }
  else {
    for (int y = 0; y < ca -> height; y++) {
      for (int x = 0; x < ca -> width; x++) {
        unsigned int index = x + (y * (ca -> width));
        printf("%d ", (ca -> cadata)[index]);
      }

      printf("\n");
    }
  }
}

CELLULAR_AUTOMATA* create1DCA(int w, unsigned char qstate) {
  CELLULAR_AUTOMATA* ca = malloc(sizeof(CELLULAR_AUTOMATA));

  if (!ca) return NULL;

  ca -> cadata = malloc(w * sizeof(unsigned char));

  if (!(ca -> cadata)) {
    free(ca);
    return NULL;
  }

  ca -> width = w;
  ca -> height = 1;
  ca -> dimension = '1';
  ca -> quiescentState = qstate;

  return ca;
}

CELLULAR_AUTOMATA* create2DCA(int w, int h, unsigned char qstate) {
  CELLULAR_AUTOMATA* ca = malloc(sizeof(CELLULAR_AUTOMATA));
  
  if (!ca) return NULL;

  ca -> cadata = malloc(w * h * sizeof(unsigned char));

  if (!(ca -> cadata)) {
    free(ca);
    return NULL;
  }

  ca -> width = w;
  ca -> height = h;
  ca -> dimension = '2';
  ca -> quiescentState = qstate;

  return ca;
}

void step1DCA(CELLULAR_AUTOMATA* ca, unsigned char (*rule)(CELLULAR_AUTOMATA*, int x)) {
  if (ca -> dimension != '1') {
    fprintf(stderr, "Unable to perform a 1DCA step on a 2DCA.\n");
  }

  unsigned char* newCells = malloc((ca -> width) * sizeof(CELLULAR_AUTOMATA));

  if (!newCells) {
    fprintf(stderr, "Unable to perform a step on the CA.\n");
  }

  for (int i = 0; i < ca -> width; i++) {
    newCells[i] = (*rule)(ca, i);
  }

  free(ca -> cadata);

  ca -> cadata = newCells;
}

void step2DCA(CELLULAR_AUTOMATA* ca, unsigned char (*rule)(CELLULAR_AUTOMATA*, int x, int y)) {
  unsigned char* newCells = malloc((ca -> width) * (ca -> height) * sizeof(unsigned char));

  if (!newCells) {
    fprintf(stderr, "Unable to perform a step on the CA.\n");
  }

  for (int y = 0; y < ca -> height; y++) {
    for (int x = 0; x < ca -> width; x++) {
      unsigned int index = x + (y * (ca -> width));
      newCells[index] = (*rule)(ca, x, y);
    }
  }

  free(ca -> cadata);

  ca -> cadata = newCells;
}
