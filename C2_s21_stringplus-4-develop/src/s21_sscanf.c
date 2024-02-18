#include "s21_string.h"

typedef struct {
  int star;
  int width;
  int length;
} kal;

bool is_NULL(const char *buf, int iter);
bool is_SPACE(const char *buf, int iter);
bool is_DIGIT(const char *buf, int iter);
void skip_spaces(const char *buf, int *iter);
char *s21_str(const char *buf, int *iter, kal *sis);
int arg_write(const char *buf, int *iter, kal *sis, va_list *ap);
long long int s21_atoi(const char *buf, int *iter, kal *sis);
int arg_write_int(const char *buf, int *iter, kal *sis, va_list *ap);
int arg_write_u(const char *buf, int *iter, kal *sis, va_list *ap);
char s21_char(const char *buf, int *iter);
int arg_write_c(const char *buf, int *iter, kal *sis, va_list *ap);
long double s21_atod(const char *buf, int *iter, kal *sis);
int arg_write_f(const char *buf, int *iter, kal *sis, va_list *ap);
void make_NONE(kal *sis);
int s21_sscanf(const char *buf, const char *format, ...);

bool is_NULL(const char *buf, int iter) { return (buf[iter] == '\0'); }

bool is_SPACE(const char *buf, int iter) {
  return (buf[iter] == ' ' || buf[iter] == '\t' || buf[iter] == '\n');
}

bool is_DIGIT(const char *buf, int iter) {
  return (buf[iter] >= '0' && buf[iter] <= '9');
}

void skip_spaces(const char *buf, int *iter) {
  while (is_SPACE(buf, *iter)) {
    (*iter)++;
  }
}

char *s21_str(const char *buf, int *iter, kal *sis) {
  if (sis->length == 0) {
    sis->length = 2147483647;
  }
  static char stat[1000];
  int i = 0;
  while (!is_NULL(buf, *iter) && !is_SPACE(buf, *iter) && sis->length > 0) {
    stat[i] = buf[*iter];
    i++;
    sis->length--;
    (*iter)++;
  }
  stat[i] = '\0';
  return stat;
}

int arg_write(const char *buf, int *iter, kal *sis, va_list *ap) {
  skip_spaces(buf, iter);
  int count = 0;
  if (!is_NULL(buf, *iter)) {
    if (sis->star == 0) {
      s21_strcpy(va_arg(*ap, char *),
                 s21_str(buf, iter, sis));  // функция копирования строки
      count++;
    } else {
      s21_str(buf, iter, sis);
    }
  }
  return count;
}

long long int s21_atoi(const char *buf, int *iter, kal *sis) {
  long long int res = 0;
  if (sis->length == 0) {
    sis->length = 2147483647;
  }
  int flag = 1;
  if (buf[*iter] == '-') {
    flag = -1;
    (*iter)++;
    sis->length--;
  } else if (buf[*iter] == '+') {
    flag = 1;
    (*iter)++;
    sis->length--;
  }
  if (buf[*iter] == '0' && (buf[*iter + 1] == 'x' || buf[*iter + 1] == 'X')) {
    (*iter) += 2;
    while (sis->length > 0) {  // нужно ли еще условие какое нибудь
      if (buf[*iter] > 47 && buf[*iter] < 58) {
        res = 16 * res + (long long int)(buf[*iter] - 48);
        (*iter)++;
        sis->length--;
      } else if (buf[*iter] > 64 && buf[*iter] < 71) {
        res = 16 * res + (long long int)(buf[*iter] - 55);
        (*iter)++;
        sis->length--;
      } else if (buf[*iter] > 96 && buf[*iter] < 103) {
        res = 16 * res + (long long int)(buf[*iter] - 87);
        (*iter)++;
        sis->length--;
      } else
        break;
    }
  } else if (buf[*iter] == '0' &&
             (buf[*iter + 1] != 'x' || buf[*iter + 1] != 'X')) {
    (*iter)++;
    while (is_DIGIT(buf, *iter) &&
           sis->length > 0) {  // нужно ли еще условие какое нибудь
      if (buf[*iter] > 47 && buf[*iter] < 56) {
        res = 8 * res + (long long int)(buf[*iter] - 48);
        (*iter)++;
        sis->length--;
      }
    }
  } else if (buf[*iter] != '0' &&
             (buf[*iter + 1] != 'x' || buf[*iter + 1] != 'X')) {
    while (is_DIGIT(buf, *iter) && sis->length > 0) {
      res = 10 * res + (long long int)(buf[*iter] - '0');
      sis->length--;
      (*iter)++;
    }
  }
  return res * flag;
}

int arg_write_int(const char *buf, int *iter, kal *sis, va_list *ap) {
  skip_spaces(buf, iter);
  int count = 0;
  if (!is_NULL(buf, *iter)) {
    if (sis->star == 0) {
      if (sis->width == SHORT_SHORT) {
        *va_arg(*ap, signed char *) = (signed char)s21_atoi(buf, iter, sis);
      } else if (sis->width == SHORT) {
        *va_arg(*ap, short int *) = (short int)s21_atoi(buf, iter, sis);
      } else if (sis->width == LONG) {
        *va_arg(*ap, long int *) = (long int)s21_atoi(buf, iter, sis);
      } else if (sis->width == LONG_LONG) {
        *va_arg(*ap, long long int *) = (long long int)s21_atoi(buf, iter, sis);
      } else {
        *va_arg(*ap, int *) = (int)s21_atoi(buf, iter, sis);
      }
      count++;
    } else {
      s21_str(buf, iter, sis);
    }
  }
  return count;
}

int arg_write_u(const char *buf, int *iter, kal *sis, va_list *ap) {
  skip_spaces(buf, iter);
  int count = 0;
  if (!is_NULL(buf, *iter)) {
    if (sis->star == 0) {
      if (sis->width == SHORT_SHORT) {
        *va_arg(*ap, unsigned char *) = (unsigned char)s21_atoi(buf, iter, sis);
      } else if (sis->width == SHORT) {
        *va_arg(*ap, unsigned short int *) =
            (unsigned short int)s21_atoi(buf, iter, sis);
      } else if (sis->width == LONG) {
        *va_arg(*ap, unsigned long int *) =
            (unsigned long int)s21_atoi(buf, iter, sis);
      } else if (sis->width == LONG_LONG) {
        *va_arg(*ap, unsigned long long int *) =
            (unsigned long long int)s21_atoi(buf, iter, sis);
      } else {
        *va_arg(*ap, unsigned int *) = (unsigned int)s21_atoi(buf, iter, sis);
      }
      count++;
    } else {
      s21_str(buf, iter, sis);
    }
  }
  return count;
}

char s21_char(const char *buf, int *iter) {
  char c;
  c = buf[*iter];
  (*iter)++;
  return c;
}

int arg_write_c(const char *buf, int *iter, kal *sis, va_list *ap) {
  skip_spaces(buf, iter);
  int count = 0;
  if (!is_NULL(buf, *iter)) {
    if (sis->star == 0) {
      if (sis->width == LONG) {
        *va_arg(*ap, wchar_t *) = (wchar_t)s21_char(buf, iter);
      } else {
        *va_arg(*ap, char *) = (char)s21_char(buf, iter);
      }
      count++;
    } else {
      s21_str(buf, iter, sis);
    }
  }
  return count;
}

long double s21_atod(const char *buf, int *iter, kal *sis) {
  long double res = 0;
  if (sis->length == 0) {
    sis->length = 2147483647;
  }
  int flag = 1;
  if (buf[*iter] == '-') {
    flag = -1;
    (*iter)++;
    sis->length--;
  } else if (buf[*iter] == '+') {
    flag = 1;
    (*iter)++;
    sis->length--;
  }
  while (is_DIGIT(buf, *iter) && sis->length > 0) {
    res = 10 * res + (long double)(buf[*iter] - '0');
    sis->length--;
    (*iter)++;
  }

  if (buf[*iter] == '.') {
    (*iter)++;
    sis->length--;
    long double u = 0.1;
    while (is_DIGIT(buf, *iter) && sis->length > 0) {
      res = res + u * (long double)(buf[*iter] - '0');
      sis->length--;
      (*iter)++;
      u *= 0.1;
    }
  }
  res *= flag;
  return res;
}

int arg_write_f(const char *buf, int *iter, kal *sis, va_list *ap) {
  skip_spaces(buf, iter);
  int count = 0;
  if (!is_NULL(buf, *iter)) {
    if (sis->star == 0) {
      if (sis->width == LONG) {
        *va_arg(*ap, double *) = (double)s21_atod(buf, iter, sis);
      } else if (sis->width == LONG_DOUBLE) {
        *va_arg(*ap, long double *) = (long double)s21_atod(buf, iter, sis);
      } else {
        *va_arg(*ap, float *) = (float)s21_atod(buf, iter, sis);
      }
      count++;
    } else {
      s21_str(buf, iter, sis);
    }
  }
  return count;
}

void make_NONE(kal *sis) {
  sis->star = 0;
  sis->length = 0;
  sis->width = NONE;
}

int s21_sscanf(const char *buf, const char *format, ...) {
  kal sis = {0};
  int count = 0;
  va_list ap;
  va_start(ap, format);
  int iter = 0;
  if (s21_strcmp(buf, "") != 0) {
    for (int k = 0, n = s21_strlen(format); k < n;
         k++) {  // функция определения длины строки
      if (format[k] == '%') {
        continue;
      } else if (format[k] >= '0' && format[k] <= '9') {
        sis.length = sis.length * 10 + format[k] - '0';
        continue;
      } else if (format[k] == 's') {
        count += arg_write(buf, &iter, &sis, &ap);
        make_NONE(&sis);
      } else if (format[k] == '*') {
        sis.star = 1;
        continue;
      } else if (format[k] == 'h') {
        (sis.width == SHORT) ? (sis.width = SHORT_SHORT) : (sis.width = SHORT);
        continue;
      } else if (format[k] == 'l') {
        (sis.width == LONG) ? (sis.width = LONG_LONG) : (sis.width = LONG);
        continue;
      } else if (format[k] == 'L') {
        sis.width = LONG_DOUBLE;
        continue;
      } else if (format[k] == 'd' || format[k] == 'i') {
        count += arg_write_int(buf, &iter, &sis, &ap);
        make_NONE(&sis);
      } else if (format[k] == 'c') {
        count += arg_write_c(buf, &iter, &sis, &ap);
        make_NONE(&sis);
      } else if (format[k] == 'u' || format[k] == 'x' || format[k] == 'X' ||
                 format[k] == 'o') {
        count += arg_write_u(buf, &iter, &sis, &ap);
        make_NONE(&sis);
      } else if (format[k] == 'f' || format[k] == 'e' || format[k] == 'E' ||
                 format[k] == 'g' || format[k] == 'G') {
        count += arg_write_f(buf, &iter, &sis, &ap);
        make_NONE(&sis);
      }
    }
  } else
    count = -1;
  va_end(ap);
  return count;
}
