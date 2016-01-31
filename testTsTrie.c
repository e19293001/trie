#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "TernarySearchTrie.h"

void Test0000();
void Test0001();
tstrie* Test0000MakeTrie();
void Test0000free(tstrie *t);
int Test0000search(tstrie *t, char *s);
void Test0000dump(tstrie *t);
void Test0000dump_(tstrie *t, int cnt);
tstrie* Test0000MakePattern_00();
tstrie* Test0000MakePattern_01();

int main() {
//  Test0000();
  Test0001();
  return 0;
}

char tstItem(tstrie *t) {
  return (t == NULL) ? '\0' : t->item;
}

void Test0000() {
  tstrie *trie;

  { // test with pattern 00
    printf("[ ------------------------------\n");
    trie = Test0000MakePattern_00();

    assert(Test0000search(trie, "sell") == 1);
    assert(Test0000search(trie, "sel") == 1);
    assert(Test0000search(trie, "seat") ==  1);
    assert(Test0000search(trie, "sean") ==  0);

    //  printf("%c->%c->%c->%c\n", tstItem(trie), tstItem(trie->middle), tstItem(trie->middle->middle->right), tstItem(trie->middle->middle->right->middle));


    Test0000free(trie);
    printf("[ ------------------------------\n");
  }

  { // test with pattern 01
    printf("[ ------------------------------\n");
    trie = Test0000MakePattern_01();
    assert(Test0000search(trie, "she") == 1);
    assert(Test0000search(trie, "sells") == 1);
    assert(Test0000search(trie, "shells") == 1);
    assert(Test0000search(trie, "shella") == 0);
    assert(Test0000search(trie, "sea") == 1);
    assert(Test0000search(trie, "by") == 1);
    assert(Test0000search(trie, "the") == 1);
    assert(Test0000search(trie, "shore") == 1);
    Test0000free(trie);
    printf("[ ------------------------------\n");
  }
}

int Test0000search(tstrie *t, char *s) {
  tstrie *a = tstSearch(t, s);
  if (a != NULL) {
    printf("search found: %s\n", s);
    return 1;
  }
  else {
    printf("search miss: %s\n", s);
    return 0;
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
  ret->middle->middle = tstNew('a', 0);
  ret->middle->middle->middle = tstNew('t', 0);
  ret->middle->middle->right = tstNew('l', 0);
  ret->middle->middle->right->middle = tstNew('l', 0);

  return ret;
}

tstrie* Test0000MakePattern_01() {
  tstrie *ret;
  ret = tstNew('s', 0); // she

  ret->middle = tstNew('h', 0);
  ret->middle->middle = tstNew('e', 0); 
  ret->middle->middle->middle = tstNew('l', 0); // shells
  ret->middle->middle->middle->middle = tstNew('l', 0);
  ret->middle->middle->middle->middle->middle = tstNew('s', 0);

  ret->middle->left = tstNew('e', 0); // sells
  ret->middle->left->middle = tstNew('l', 0);
  ret->middle->left->middle->middle = tstNew('l', 0);
  ret->middle->left->middle->middle->middle = tstNew('s', 0);

  ret->middle->left->middle->left = tstNew('a', 0); // sea

  ret->left = tstNew('b', 0); // by
  ret->left->middle = tstNew('y', 0); // by

  ret->right = tstNew('t', 0); // the
  ret->right->middle = tstNew('h', 0);
  ret->right->middle->middle = tstNew('e', 0);

  ret->middle->middle->right = tstNew('o', 0); // shore
  ret->middle->middle->right->middle = tstNew('r', 0);
  ret->middle->middle->right->middle->middle = tstNew('e', 0);
  
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

void printspce(int cnt) {
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
    printspce(cnt);
    printf("->%c\n", t->item);
    printspce(cnt);
    if (t->left != NULL) {
      printf(" turning left\n");
      Test0000dump_(t->left, cnt+1);
    }
    else {
      printf(" left is null.\n");
    }
    printspce(cnt);
    if (t->middle != NULL) {
      printf(" go to middle\n");
      Test0000dump_(t->middle, cnt+1);
    }
    else {
      printf(" middle is null.\n");
    }
    printspce(cnt);
    if (t->right != NULL) {
      printf(" turning right\n");
      Test0000dump_(t->right, cnt+1);
    }
    else {
      printf(" right is null.\n");
    }
  }
}  

void Test0001() {
  tstrie* tst;
//  tst = tstNew('s', 0);
//  tst->right = tstNew('a', 1);
//  tst->middle = tstNew('b', 1);
//  tst->left = tstNew('c', 1);
//tstDump(tst);
  tst = Test0000MakePattern_01();
  tstDumpGraphical(tst);
  tstDelete(tst);  
}
