#include "TernarySearchTrie.h"

int tstSearchR(tstrie *t, char *s, int i);

tstrie* tstNew(char i, int d) {
  tstrie* ret;

  ret = (tstrie *) malloc(sizeof(tstrie));
  ret->item = i;
  ret->data = d;
  ret->left = NULL;
  ret->middle = NULL;
  ret->right = NULL;

  return ret;
}

int tstSearchR(tstrie *t, char *s, int i) {
  int ret;

  return ret;
}

int tstSearch(tstrie *t, char *s) {
  int ret;

  ret = tstSearchR(t, s, 0);

  return ret;
}
