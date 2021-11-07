#ifndef CA_H_

#ifndef NULL
#define NULL 0
#endif

typedef struct ca_data {
  unsigned char* cadata;
  unsigned char dimension;
  unsigned char wrap;
  unsigned char quiescentState;
  unsigned int possibleStates;
  unsigned int width;
  unsigned int height;
} CELLULAR_AUTOMATA;

void initCA(CELLULAR_AUTOMATA*, int);
void displayCA(CELLULAR_AUTOMATA*);
int set1DCACell(CELLULAR_AUTOMATA*, unsigned int, unsigned char);
int set2DCACell(CELLULAR_AUTOMATA*, unsigned int, unsigned int, unsigned char);
void step1DCA(CELLULAR_AUTOMATA*, unsigned char (*)(CELLULAR_AUTOMATA*, int));
void step2DCA(CELLULAR_AUTOMATA*, unsigned char (*)(CELLULAR_AUTOMATA*, int, int));
CELLULAR_AUTOMATA* create1DCA(int, unsigned char);
CELLULAR_AUTOMATA* create2DCA(int, int, unsigned char);

#define CA_H_
#endif