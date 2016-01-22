#include <stdio.h>
#include <stdlib.h>

#include "TernarySearchTrie.h"

void Test0000();

int main() {
  Test0000();
  return 0;
}

void Test0000() {
  tstrie *trie;
  trie = (tstrie *) tstNew(0);
  printf("hello world\n");
  free(trie);
}


