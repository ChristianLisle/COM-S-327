#ifndef CA_H_

#ifndef NULL
#define NULL 0
#endif

typedef struct ca_data {
  unsigned char* cells;
  int numCells;
} CELLULAR_AUTOMATA;

void init1DCA(CELLULAR_AUTOMATA*, int);
int set1DCACell(CELLULAR_AUTOMATA*, unsigned int, unsigned char);
void display1DCA(CELLULAR_AUTOMATA*);
CELLULAR_AUTOMATA* create1DCA(int, unsigned char);
void stepCA(CELLULAR_AUTOMATA*, unsigned char (*)(CELLULAR_AUTOMATA*, int), int);

#define CA_H_
#endif