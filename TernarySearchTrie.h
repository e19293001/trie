#include <stdlib.h>

typedef struct tstrie {
  char item;
  int data;
  struct tstrie* left;
  struct tstrie* middle;
  struct tstrie* right;
} tstrie;

tstrie* tstNew(char i, int d);
int tstSearch(tstrie *t, char *s);
