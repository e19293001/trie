#include <stdio.h>
#include <stdlib.h>

#include "TernarySearchTrie.h"

void Test0000();
tstrie* Test0000MakeTrie();
void Test0000free(tstrie *t);
void Test0000search(tstrie *t, char *s);
void Test0000dump(tstrie *t);
void Test0000dump_(tstrie *t, int cnt);
tstrie* Test0000MakePattern_00();

int main() {
  Test0000();
  return 0;
}

void Test0000() {
  tstrie *trie;
//  trie = Test0000MakeTrie();
//  
//  Test0000search(trie, "s");
//  Test0000search(trie, "h");
//  Test0000search(trie, "t");
//  Test0000search(trie, "a");
//  Test0000search(trie, "b");
//  Test0000dump(trie);
//
//  Test0000free(trie);

  trie = Test0000MakePattern_00();
  Test0000dump(trie);

  Test0000search(trie, "sea");
  Test0000search(trie, "sea");
  Test0000search(trie, "seat");
  Test0000search(trie, "sean");

//  trie->middle->right = tstNew('l', 0);
//  trie->middle->right->middle = tstNew('l', 0);
  printf("sell must be present.\n");
  Test0000search(trie, "sell");
  Test0000search(trie, "sel");
  Test0000search(trie, "seat");

  Test0000free(trie);
}

void Test0000search(tstrie *t, char *s) {
  tstrie *a = tstSearch(t, s);
  if (a != NULL) {
    printf("search found: %s\n", s);
  }
  else {
    printf("search miss: %s\n", s);
  }
}  

tstrie* Test0000MakeTrie() {
  tstrie *ret;
  ret = tstNew('s', 0);

  ret->left = tstNew('h', 0);
  ret->right = tstNew('t', 0);
  ret->left->left = tstNew('a', 0);
                                 
  return ret;
}

tstrie* Test0000MakePattern_00() {
  tstrie *ret;
  ret = tstNew('s', 0);

  ret->middle = tstNew('e', 0);
  ret->middle->right = tstNew('l', 0);
  ret->middle->right->middle = tstNew('l', 0);
  ret->middle->middle = tstNew('a', 0);
  ret->middle->middle->middle = tstNew('t', 0);

  Test0000dump(ret);

//  ret->left = tstNew('h', 0);
//  ret->right = tstNew('t', 0);
//  ret->left->left = tstNew('a', 0);
//  ret->left->left->middle = tstNew('b', 0);
//  ret->left->left->middle->middle = tstNew('y', 0);
//  ret->left->left->left = tstNew('n', 0);
//  ret->left->left->left->middle = tstNew('t', 0);
//  ret->left->left->left->left = tstNew('e', 0);
//  ret->left->left->left->left->middle = tstNew('t', 0);
                                 
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

void Test0000dump(tstrie *t) {
  printf("[\n");
  Test0000dump_(t, 0);
  printf("]");
  printf("\n");
}

void printspace(int cnt) {
  int x;
  for (x = 0; x < cnt+1; x++) {
    printf(" ");
  }
}

void Test0000dump_(tstrie *t, int cnt) {
  if (t == NULL) {
    printf("null here.");
  }
  else {
    printspace(cnt);
    printf("->%c\n", t->item);
    printspace(cnt);
    if (t->left != NULL) {
      printf(" turning left\n");
      Test0000dump_(t->left, cnt+1);
    }
    else {
      printf(" left is null.\n");
    }
    printspace(cnt);
    if (t->middle != NULL) {
      printf(" go to middle\n");
      Test0000dump_(t->middle, cnt+1);
    }
    else {
      printf(" middle is null.\n");
    }
    printspace(cnt);
    if (t->right != NULL) {
      printf(" turning right\n");
      Test0000dump_(t->right, cnt+1);
    }
    else {
      printf(" right is null.\n");
    }
  }
}  
