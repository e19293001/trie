#ifndef testTsTrie_h
#define testTsTrie_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "TernarySearchTrie.h"
#include "TernarySearchTrie.h"

void Test0000(); // test search
void Test0001();
void Test0002(); // test copy
void Test0003(); // test insert
tstrie* Test0000MakeTrie();
void Test0000free(tstrie *t);
int Test0000search(tstrie *t, char *s);
void Test0000dump(tstrie *t);
void Test0000dump_(tstrie *t, int cnt);
tstrie* Test0000MakePattern_00();
tstrie* Test0000MakePattern_01();

#endif
