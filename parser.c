#include "parser.h"

parserData* ParserNew() {
  parserData *ret;

  ret = malloc(sizeof(parserData));

  ret->tm = TokenManagerNew("tst/testpattern_parser0000.txt");
  ret->currentToken.next = NULL;
  ret->previousToken.next = NULL;

  return ret;
}

void ParserStart(parserData *t) {
  _parser = t;
  program(t);
  if (_parser->currentToken.kind != _EOF) {
    printf("expecting EOF. token is: %s\n", tokenImage[_parser->currentToken.kind]);
    exit(-1);
  }
}

void program() {
  _parser->currentToken = TokenManagerGetNextToken(&_parser->tm);
  if (_parser->currentToken.kind == PUSH) {
    printf("call push\n");
    push();
    program();
  }
  else if (_parser->currentToken.kind == PUSHC) {
    printf("call pushc\n");
    pushc();
    program();
  }
  else if (_parser->currentToken.kind == PUSHWC) {
    printf("call pushwc\n");
    pushwc();
    program();
  }
  else if (_parser->currentToken.kind == HALT) {
    printf("call halt\n");
    halt();
    program();
  }
  else if (_parser->currentToken.kind == _EOF) {
    // do nothing
  }
  else {
    printf("error unknown token\n");
  }
}

void push() {
  if (_parser->currentToken.kind == PUSH) {
    consume(PUSH);
    consume(UNSIGNED);
  }
}

void pushc() {
  if (_parser->currentToken.kind == PUSHC) {
    consume(PUSHC);
    consume(UNSIGNED);
  }
}

void pushwc() {
  if (_parser->currentToken.kind == PUSHWC) {
    consume(PUSHWC);
    consume(UNSIGNED);
  }
}

void halt() {
  if (_parser->currentToken.kind == HALT) {
    consume(HALT);
  }
}

Token ParserGetToken() {
  Token ret;

  return ret;
}

void ParserAdvance() {
  _parser->previousToken = _parser->currentToken;

  if (_parser->currentToken.next != NULL) {
    _parser->currentToken = *(_parser->currentToken.next);
  }
  else {
    _parser->currentToken = TokenManagerGetNextToken(&_parser->tm);
  }
}

void consume(int expected) {
  if (_parser->currentToken.kind != expected) {
    ParserAdvance();
  }
  else {
    printf("consume: %s\n", tokenImage[expected]);
    printf("Found token \"%s\", ", _parser->currentToken.image);
    printf("expecting kind of \"%s\"\n", tokenImage[expected]);
  }
}

void ParserDelete(parserData *t) {
  TokenManagerDelete(t->tm);
  free(t);
}
