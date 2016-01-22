#include "stdlib.h"

typedef struct tstrie {
  char item;
  int data;
  struct tsttrie* left;
  struct tsttrie* middle;
  struct tsttrie* right;
} tstrie;

tstrie* tstNew(int d);
