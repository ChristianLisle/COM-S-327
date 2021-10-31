#include "ca.h"

void initCA(CELLULAR_AUTOMATA* ca, int state) {
  // TODO
}

int set1DCACell(CELLULAR_AUTOMATA* ca, unsigned int x, unsigned char state) {
  // TODO
}

int set2DCACell(CELLULAR_AUTOMATA* ca, unsigned int x, unsigned int y, unsigned char state) {
  // TODO
}

void displayCA(CELLULAR_AUTOMATA* ca) {
  // TODO
}

CELLULAR_AUTOMATA* create1DCA(int w, unsigned char qstate) {
  // TODO
}

CELLULAR_AUTOMATA* create2DCA(int w, int h, unsigned char qstate) {
  // TODO
}

void step1DCA(CELLULAR_AUTOMATA* ca, unsigned char (*rule)(CELLULAR_AUTOMATA*, int x)) {
  // TODO
}

void step2DCA(CELLULAR_AUTOMATA* ca, unsigned char (*rule)(CELLULAR_AUTOMATA*, int x, int y)) {
  // TODO
}
