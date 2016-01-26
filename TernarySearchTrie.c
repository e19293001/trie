#include "TernarySearchTrie.h"

tstrie* tstSearchR(tstrie *t, char *s, int i, int cntr);

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

tstrie* tstSearchR(tstrie *t, char *s, int i, int cntr) {
  char val = s[i];
  int x;

  for (x = 0; x < cntr+1; x++) {
    printf(" ");
  }
//  (t == NULL) ? 
//    printf("val: %c t is null\n", val) :
//    printf("val: %c t->item: %c ", val, t->item);
  
  if (t == NULL) {
    printf("t is null\n");
    return NULL;
  }
  if (val < t->item) {
    printf("[ turning left.");
    printf(" val: %c t->item: %c\n", val, t->item);
    return tstSearchR(t->left, s, i, cntr+1);
  }
  if (val > t->item) {
    printf("[ turning right.\n");
    printf(" val: %c t->item: %c\n", val, t->item);
    return tstSearchR(t->right, s, i, cntr+1);
  }
  if (i < strlen(s)-1) {
    printf("[ going to middle.\n");
    printf(" val: %c t->item: %c\n", val, t->item);
    return tstSearchR(t->middle, s, i+1, cntr+1);
  }

  printf("\n");

  return t;
}

tstrie* tstSearch(tstrie *t, char *s) {
  tstrie *ret;

  printf("--- [ searching for: %s\n", s);
  ret = tstSearchR(t, s, 0, 0);

  return ret;
}
