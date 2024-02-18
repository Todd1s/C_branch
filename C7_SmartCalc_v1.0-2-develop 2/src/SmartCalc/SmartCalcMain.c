#include "SmartCalcMain.h"

int start(char *result_culc, double *res, double resX) {
  int flag = true;
  Node *headNode = NULL;
  Node *NodeResCalc = NULL;
  flag = parser(&headNode, result_culc);
  if (flag) inverse(&headNode, &NodeResCalc);
  if (flag) flag = resultCalc(&NodeResCalc, res, resX);
  if (!flag) *res = 0;
  removeNode(&headNode);
  removeNode(&NodeResCalc);
  return flag;
}

int parser(Node **headNode, char *result_culc) {
  int flag = true;
  Node *sumbolNode = NULL;
  int lenString = strlen(result_culc);
  double result = 0.0;
  char results = {0};
  for (int i = 0; i < lenString && flag; i++) {
    if (isdigit((result_culc[i])) || result_culc[i] == '.') {
      readDigit(result_culc, &result, &i);
      push(headNode, result, false, CHR_NONE);
    } else if (isalpha(result_culc[i]) && result_culc[i] != 'x') {
      readString(&results, result_culc, &i);
      priority(&sumbolNode, headNode, results);
    } else if (isSign(result_culc[i])) {
      if (result_culc[i] == '-' && ((i - 1) < 0)) {
        if (isdigit(result_culc[i + 1])) {
          i++;
          readDigit(result_culc, &result, &i);
          result *= -1;
          push(headNode, result, false, CHR_NONE);
        } else {
          flag = false;
        }
      } else if (result_culc[i] == '-' &&
                 (isSign(result_culc[i - 1]) ||
                  result_culc[i - 1] == OPEN_BRACKET)) {
        i++;
        readDigit(result_culc, &result, &i);
        result *= -1;
        push(headNode, result, false, CHR_NONE);
      } else {
        priority(&sumbolNode, headNode, result_culc[i]);
      }
    } else if (result_culc[i] == OPEN_BRACKET) {
      push(&sumbolNode, 0.0, false, result_culc[i]);
    } else if (result_culc[i] == CLOSE_BRACKET) {
      if (result_culc[i - 1] == '(') {
        flag = false;
      } else {
        flag = closeBracket(headNode, &sumbolNode);
      }
    } else if (result_culc[i] == 'x') {
      push(headNode, 0.0, true, CHR_NONE);
    } else if (result_culc[i] == ' ') {
      continue;
    }
  }
  if (*headNode == NULL) {
    flag = false;
  }
  if (flag) pushInNode(headNode, &sumbolNode);
  removeNode(&sumbolNode);
  return flag;
}

int resultCalc(Node **NodeResCalc, double *res, double resX) {
  int flag = true;
  double req[10] = {0};
  int i = 0;
  double value = 0.0;
  int isX = 0;
  char sign = {0};
  double firstNum = 0.0;
  double secondNum = 0.0;
  while (*NodeResCalc != NULL && flag) {
    if (nodeIsValue(NodeResCalc)) {
      pop(NodeResCalc, &value, &isX, &sign);
      req[i] = value;
      i++;
    } else if (nodeIsSign(NodeResCalc)) {
      pop(NodeResCalc, &value, &isX, &sign);
      i -= 2;
      if (i < 0) {
        flag = false;
        break;
      }
      firstNum = req[i];
      secondNum = req[i + 1];
      i++;
      flag = calcTwoArg(&firstNum, secondNum, sign);
      req[i] = 0.0;
      req[i - 1] = firstNum;
    } else if (nodeIsX(NodeResCalc)) {
      pop(NodeResCalc, &value, &isX, &sign);
      req[i] = resX;
      i++;
    } else if (nodeIsTrig(NodeResCalc)) {
      pop(NodeResCalc, &value, &isX, &sign);
      i -= 1;
      firstNum = req[i];
      flag = calcOneArg(&firstNum, sign);
      req[i] = firstNum;
      i++;
    }
  }

  if (req[1] != 0.0) {
    flag = false;
  }
  *res = req[0];
  return flag;
}

int calcOneArg(double *firstNum, char sign) {
  int flag = true;
  if (sign == SIN) {
    *firstNum = sin(*firstNum);
  } else if (sign == COS) {
    *firstNum = cos(*firstNum);
  } else if (sign == TAN) {
    *firstNum = tan(*firstNum);
  } else if (sign == ACOS) {
    if (*firstNum < -1 || *firstNum > 1) {
      flag = false;
    } else {
      *firstNum = acos(*firstNum);
    }
  } else if (sign == ASIN) {
    if (*firstNum < -1 || *firstNum > 1) {
      flag = false;
    } else {
      *firstNum = asin(*firstNum);
    }
  } else if (sign == ATAN) {
    *firstNum = atan(*firstNum);
  } else if (sign == SQRT) {
    if (*firstNum < 0) {
      flag = false;
    } else {
      *firstNum = sqrt(*firstNum);
    }
  } else if (sign == LN) {
    if (*firstNum <= 0) {
      flag = false;
    } else {
      *firstNum = log(*firstNum);
    }
  } else if (sign == LOG) {
    if (*firstNum <= 0) {
      flag = false;
    } else {
      *firstNum = log10(*firstNum);
    }
  } else {
    flag = false;
  }
  return flag;
}

int calcTwoArg(double *firstNum, double secondNum, char sign) {
  int flag = true;
  if (sign == POWER) {
    *firstNum = pow(*firstNum, secondNum);
  } else if (sign == PLUS) {
    *firstNum = *firstNum + secondNum;
  } else if (sign == MINUS) {
    *firstNum = *firstNum - secondNum;
  } else if (sign == MULTIPLY) {
    *firstNum = *firstNum * secondNum;
  } else if (sign == DIVIDE) {
    *firstNum = *firstNum / secondNum;
    if (!secondNum) {
      flag = false;
    }
  } else if (sign == MOD) {
    *firstNum = fmod(*firstNum, secondNum);
    if (!secondNum) {
      flag = false;
    }
  }
  return flag;
}

void removeNode(Node **head) {
  Node *prev = NULL;
  int flag = true;
  if (*head == NULL) flag = false;
  if (flag) {
    while ((*head)->next) {
      prev = (*head);
      (*head) = (*head)->next;
      free(prev);
    }
    free(*head);
  }
}

int closeBracket(Node **headNode, Node **sumbolNode) {
  int flag = true;
  double value = 0.0;
  int isX = 0;
  char sign = {0};
  peek(sumbolNode, &sign);
  while (sign != '(') {
    if (*sumbolNode == NULL) {
      flag = false;
      break;
    }

    pop(sumbolNode, &value, &isX, &sign);
    push(headNode, value, isX, sign);
    peek(sumbolNode, &sign);
  }
  if (sign == '(' && *sumbolNode != NULL)
    pop(sumbolNode, &value, &isX, &sign);
  return flag;
}

int priority(Node **sumbolNode, Node **headNode, char symbol) {
  int prior = 0;
  char val = {0};
  if (peek(sumbolNode, &val)) {
    double value = 0.0;
    int isX = 0;
    char sign = {0};
    if (signPriority(val) >= signPriority(symbol)) {
      while (signPriority(val) >= signPriority(symbol) &&
             *sumbolNode != NULL && !(val == '^' && symbol == '^')) {
        pop(sumbolNode, &value, &isX, &sign);
        push(headNode, 0.0, false, sign);
        peek(sumbolNode, &val);
      }
      push(sumbolNode, 0.0, false, symbol);
    } else if (signPriority(val) < signPriority(symbol)) {
      push(sumbolNode, 0.0, false, symbol);
    }
  } else {
    push(sumbolNode, 0.0, false, symbol);
  }
  return prior;
}

int signPriority(char c) {
  int priority = PRIORITY_NULL;
  if (c == SIN || c == COS || c == TAN || c == ACOS || c == ASIN || c == ATAN ||
      c == SQRT || c == LN || c == LOG)
    priority = 4;
  else if (c == POWER)
    priority = 3;
  else if (c == MULTIPLY || c == DIVIDE || c == MOD)
    priority = 1;
  else if (c == PLUS || c == MINUS)
    priority = 0;
  return priority;
}

void readDigit(char *result_culc, double *result, int *i) {
  char tmp[100] = {0};
  int j = 0;
  int countPoint = 0;
  while (((isdigit(result_culc[*i]) || result_culc[*i] == '.')) &&
         countPoint <= 1) {
    if (result_culc[*i] == '.') {
      countPoint++;
    }
    tmp[j] = result_culc[*i];
    j++;
    *i = *i + 1;
  }
  *i = *i - 1;
  *result = atof(tmp);
}

void readString(char *result, char *result_culc, int *i) {
  char tmp[256] = {0};
  int j = 0;
  while (isalpha(result_culc[*i])) {
    tmp[j] = result_culc[*i];
    j++;
    *i = *i + 1;
  }
  *i = *i - 1;
  refractor(tmp, result);
}

int refractor(char *tmp, char *result) {
  int flag = false;
  if (strcmp(tmp, "sin") == 0) {
    *result = SIN;
  } else if (strcmp(tmp, "cos") == 0) {
    *result = COS;
  } else if (strcmp(tmp, "tan") == 0) {
    *result = TAN;
  } else if (strcmp(tmp, "acos") == 0) {
    *result = ACOS;
  } else if (strcmp(tmp, "asin") == 0) {
    *result = ASIN;
  } else if (strcmp(tmp, "atan") == 0) {
    *result = ATAN;
  } else if (strcmp(tmp, "sqrt") == 0) {
    *result = SQRT;
  } else if (strcmp(tmp, "ln") == 0) {
    *result = LN;
  } else if (strcmp(tmp, "log") == 0) {
    *result = LOG;
  } else {
    flag = true;
  }
  return flag;
}

int peek(Node **head, char *val) {
  int status = 1;
  if (*head == NULL) status = 0;
  if (status) {
    *val = (*head)->sign;
  }
  return status;
}

void push(Node **head, double value, int isX, char sign) {
  Node *tmp = (Node *)malloc(sizeof(Node));
  if (tmp != NULL) {
    tmp->value = value;
    tmp->isX = isX;
    tmp->sign = sign;
    tmp->next = (*head);
    (*head) = tmp;
  }
}

int pop(Node **head, double *value, int *isX, char *sign) {
  Node *prev = NULL;
  int status = 1;
  if (*head == NULL) status = 0;
  if (status) {
    prev = (*head);
    *value = prev->value;
    *isX = prev->isX;
    *sign = prev->sign;
    (*head) = (*head)->next;
    free(prev);
  }
  return status;
}

int isSign(char c) {
  int flag = false;
  if (c == MULTIPLY || c == MINUS || c == PLUS || c == DIVIDE || c == POWER ||
      c == MOD) {
    flag = true;
  }
  return flag;
}

int nodeIsValue(Node **node) {
  int res = false;
  if (node != NULL && (*node)->isX == false && (*node)->sign == CHR_NONE) {
    res = true;
  }
  return res;
}

int nodeIsX(Node **node) {
  int res = false;
  if (node != NULL && (*node)->isX == true) {
    res = true;
  }
  return res;
}

int nodeIsSign(Node **node) {
  int res = false;
  if (node != NULL && (*node)->isX == false && (*node)->sign != CHR_NONE &&
      ((*node)->sign == PLUS || (*node)->sign == MINUS ||
       (*node)->sign == MULTIPLY || (*node)->sign == DIVIDE ||
       (*node)->sign == POWER || (*node)->sign == MOD)) {
    res = true;
  }
  return res;
}

int nodeIsTrig(Node **node) {
  int res = false;
  if (node != NULL && (*node)->isX == false && (*node)->sign != CHR_NONE) {
    res = true;
  }
  return res;
}

void pushInNode(Node **node, Node **twonote) {
  double value = 0.0;
  int isX = 0;
  char sign = {0};
  while (pop(twonote, &value, &isX, &sign)) {
    push(node, value, isX, sign);
  }
}

void inverse(Node **node, Node **inverses) {
  double value = 0.0;
  int isX = 0;
  char sign = {0};
  while (pop(node, &value, &isX, &sign)) {
    push(inverses, value, isX, sign);
  }
}
