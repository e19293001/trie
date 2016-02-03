#include "tokenmanager.h"

TokenManager* TokenManagerNew(char *inFileName) {
  TokenManager *ret = malloc(sizeof(TokenManager));
  if ((ret->inFile = fopen(inFileName, "r")) == NULL) {
    printf("could not open file: %s\n", inFileName);
    exit(-1);
  }
  ret->currentChar = '\0';
  ret->currentColumnNumber = 0;
  ret->currentLineNumber = 0;
  ret->inputLine = NULL;
  ret->tok = NULL;
  return ret;
}

void getNextChar(TokenManager **t) {
  TokenManager *tm = *t;
  char *strline;

  strline = malloc(512*sizeof(char));
  memset(strline,'\0',512);

  if (tm->currentChar == EOF) {
    return;
  }

// TODO: add functionality here
//  if (tm->currentChar == '\n') {
//    if ((fgets(strline, 512, tm->inFile)) == NULL) {
//      tm->currentChar = EOF;
//    }
//    else {
//      strline
}

Token TokenManagerGetNextToken(TokenManager **t) {
  Token ret;

  while (isspace((*t)->currentChar)) {
    getNextChar(t);
  }

  return ret;
}

void TokenManagerDelete(TokenManager* t) {
  fclose(t->inFile);
  free(t);
}
