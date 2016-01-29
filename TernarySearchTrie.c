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
    printf("current: val: %c t->item: %c ", val, t->item);
    printf("[ turning left.\n");
    return tstSearchR(t->left, s, i, cntr+1);
  }
  if (val > t->item) {
    printf("current: val: %c t->item: %c ", val, t->item);
    printf("[ turning right.\n");
    return tstSearchR(t->right, s, i, cntr+1);
  }
  if (i < strlen(s)-1) {
    printf("current: val: %c t->item: %c ", val, t->item);
    printf("[ going to middle.\n");
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

void tstCopy(tstrie *src, tstrie **dst) {
  (*dst)->item = src->item;
  (*dst)->data = src->data;
  (*dst)->left = src->left;
  (*dst)->middle = src->middle;
  (*dst)->right = src->right;
//  printf("[ tstCopy ] src->item: %c src->data: %0d (*dst)->item: %c (*dst)->data: %0d\n", src->item, src->data, (*dst)->item, (*dst)->data);
}

void tstDelete(tstrie *t) {
  if (t != NULL) {
    if (t->left != NULL) {
      tstDelete(t->left);
    }
    if (t->middle != NULL) {
      tstDelete(t->middle);
    }
    if (t->right != NULL) {
      tstDelete(t->right);
    }
    free(t);
  }
}

void printspace(int cnt) {
  int x;
  for (x = 0; x < cnt+1; x++) {
    printf(" ");
  }
}


void tstDump(tstrie *t) {
  printf("[\n");
  tstDump_(t, 0);
  printf("]");
  printf("\n");
}

void tstDump_(tstrie *t, int cnt) {
  if (t == NULL) {
    printf("null here.");
  }
  else {
    printspace(cnt);
    printf("->%c\n", t->item);
    printspace(cnt);
    if (t->left != NULL) {
      printf(" turning left\n");
      tstDump_(t->left, cnt+1);
    }
    else {
      printf(" left is null.\n");
    }
    printspace(cnt);
    if (t->middle != NULL) {
      printf(" go to middle\n");
      tstDump_(t->middle, cnt+1);
    }
    else {
      printf(" middle is null.\n");
    }
    printspace(cnt);
    if (t->right != NULL) {
      printf(" turning right\n");
      tstDump_(t->right, cnt+1);
    }
    else {
      printf(" right is null.\n");
    }
  }
}  
