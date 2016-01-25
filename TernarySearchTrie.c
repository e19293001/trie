#include "TernarySearchTrie.h"

tstrie* tstSearchR(tstrie *t, char *s, int i);

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

tstrie* tstSearchR(tstrie *t, char *s, int i) {
  char val = s[i];

//  printf("val: %c t->item: %c (strlen(s)-1): %0d *s: %s\n", val, t->item, (strlen(s)-1), s);

  if (t == NULL) {
//    printf("  t is null\n");
    return NULL;
  }
  if (val < t->item) {
//    printf("  t is less than t->item.\n");
    return tstSearchR(t->left, s, i);
  }
  else if (val > t->item) {
//    printf("  t is more than t->item.\n");
    return tstSearchR(t->right, s, i);
  }
  else if (i < strlen(s)-1) {
//    printf("  t is equal to t->item.\n");
    return tstSearchR(t->middle, s, i+1);
  }
  else {
    return t;
  }
}

tstrie* tstSearch(tstrie *t, char *s) {
  tstrie *ret;

  ret = tstSearchR(t, s, 0);

  return ret;
}
