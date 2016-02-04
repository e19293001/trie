#include "parser.h"

parserData* ParserNew() {
  parserData *ret;

  ret = malloc(sizeof(parserData));

  ret->tm = TokenManagerNew("tst/testpattern_parser0000.txt");

  return ret;
}

void ParserStart(parserData *t) {
  _parser = t;
  _parser->currentToken = TokenManagerGetNextToken(&_parser->tm);
  if (t->currentToken.kind == PUSH) {
    printf("call push\n");
    consume(PUSH);
    push();
  }
  else if (t->currentToken.kind == PUSHC) {
    printf("call pushc\n");
  }
  else if (t->currentToken.kind == PUSHWC) {
    printf("call pushwc\n");
  }
  else if (t->currentToken.kind == HALT) {
    printf("call halt\n");
  }
  else {
    printf("error unknown token\n");
  }
}

void push() {
  //if (_parser->currentToken
}

void pushc() {
}

void pushwc() {
}

void halt() {
}

void ParserConsume() {
}

Token ParserGetToken() {
  Token ret;

  return ret;
}

void ParserAdvance() {
}

void consume(int expected) {
  if (_parser->currentToken.kind != expected) {
    ParserAdvance();
  }
  else {
    printf("Found token \"%s\", ", _parser->currentToken.image);
    printf("expecting kind of \"%s\"\n", tokenImage[expected]);
  }
}

void ParserDelete(parserData *t) {
  TokenManagerDelete(t->tm);
  free(t);
}
