#ifndef SRC_SMARTCALCMAIN_H_
#define SRC_SMARTCALCMAIN_H_

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHR_NONE '\0'

#define MOD '%'
#define SIN '1'
#define COS '2'
#define TAN '3'
#define ACOS '4'
#define ASIN '5'
#define ATAN '6'
#define SQRT '7'
#define LN '8'
#define LOG '9'
#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'
#define POWER '^'
#define PLUS '+'
#define UNAR_MINUS '~'
#define MINUS '-'
#define MULTIPLY '*'
#define DIVIDE '/'

#define HIGH 1
#define LOW 0

#define PRIORITY_NULL -1

typedef struct node_t {
  double value;
  int isX;
  char sign;

  struct node_t *next;
} Node;

int start(char *result_culc, double *res, double resX);
int parser(Node **headNode, char *result_culc);
int resultCalc(Node **NodeResCalc, double *res, double resX);
int calcOneArg(double *firstNum, char sign);
int calcTwoArg(double *firstNum, double secondNum, char sign);
void removeNode(Node **head);
int closeBracket(Node **headNode, Node **sumbolNode);
int priority(Node **sumbolNode, Node **headNode, char symbol);
int signPriority(char c);
void readDigit(char *result_culc, double *result, int *i);
void readString(char *results, char *result_culc, int *i);
int refractor(char *tmp, char *result);
int peek(Node **head, char *val);
void push(Node **head, double value, int is_x, char sign);
int pop(Node **head, double *value, int *is_x, char *sign);
int isSign(char c);
int nodeIsValue(Node **node);
int nodeIsX(Node **node);
int nodeIsSign(Node **node);
int nodeIsTrig(Node **node);
void pushInNode(Node **node, Node **twonote);
void inverse(Node **node, Node **inverses);

#endif  // SRC_SMARTCALCMAIN_H_
