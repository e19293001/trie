#include <stdio.h>
#include <stdlib.h>

#include "TernarySearchTrie.h"

void Test0000();
tstrie* Test0000MakeTrie();
void Test0000free(tstrie *t);

int main() {
  Test0000();
  return 0;
}

void Test0000() {
  tstrie *trie;
  trie = Test0000MakeTrie();
  
  Test0000free(trie);
}

tstrie* Test0000MakeTrie() {
  tstrie *ret;
  ret = (tstrie *) tstNew('s', 0);

  ret->left = tstNew('e', 0);
  ret->middle = tstNew('h', 0);
  ret->right = tstNew('t', 0);
                                 
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


