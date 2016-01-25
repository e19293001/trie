#include <stdio.h>
#include <stdlib.h>

#include "TernarySearchTrie.h"

void Test0000();
tstrie* Test0000MakeTrie();
void Test0000free(tstrie *t);
void Test0000search(tstrie *t, char *s);

int main() {
  Test0000();
  return 0;
}

void Test0000() {
  tstrie *trie;
  trie = Test0000MakeTrie();
  
  Test0000search(trie, "s");
  Test0000search(trie, "h");
  Test0000search(trie, "t");
  Test0000search(trie, "a");
  Test0000search(trie, "b");

  Test0000free(trie);
}

void Test0000search(tstrie *t, char *s) {
  tstrie *a = tstSearch(t, s);
  if (a != NULL) {
    printf("search found: %c\n", a->item);
  }
  else {
    printf("search miss: %s\n", s);
  }
}  

tstrie* Test0000MakeTrie() {
  tstrie *ret;
  ret = (tstrie *) tstNew('s', 0);

  ret->left = tstNew('h', 0);
  ret->right = tstNew('t', 0);
  ret->left->left = tstNew('a', 0);
                                 
  return ret;
}

void Test0000free(tstrie *t) {
  if (t != NULL) {
    if (t->left != NULL) {
      Test0000free(t->left);
    }
    if (t->middle != NULL) {
      Test0000free(t->middle);
    }
    if (t->right != NULL) {
      Test0000free(t->right);
    }
    free(t);
  }
}


