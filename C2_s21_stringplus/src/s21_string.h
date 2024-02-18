#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <inttypes.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#define s21_NULL ((void *)0)
#define BUFF_S 4096
typedef unsigned long s21_size_t;
#define NONE 0
#define SHORT_SHORT 1
#define SHORT 2
#define LONG_LONG 3
#define LONG 4
#define LONG_DOUBLE 5

typedef struct flags {
  int minus;
  int plus;
  int sharp;
  int space;
  int zero;
  int width;
  int precision;
  int prec;
  int length;
  int specificator;
} flags;

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;

/// моя часть
void *s21_memchr(
    const void *str, int c,
    s21_size_t n);  // поиск первого вхождения указанного символа в массиве
int s21_memcmp(const void *str1, const void *str2,
               s21_size_t n);  // сравнение массивов
void *s21_memcpy(void *dest, const void *src,
                 s21_size_t n);  // копирование непересекающихся массивов
void *s21_memset(void *str, int c,
                 s21_size_t n);  // заполнения массива указанными символами
char *s21_strncat(char *dest, const char *src, s21_size_t n);
// объединение строк c ограничением длины добавляемой строки

char *s21_strcat(char *dest, const char *src);

char *s21_strchr(const char *str,
                 int c);  // поиск первого вхождения символа в строку
int s21_strncmp(const char *str1, const char *str2,
                s21_size_t n);  // сравнение строк с ограничением количества
                                // сравниваемых символов.

int s21_strcmp(const char *str1, const char *str2);

/// часть Ромы
char *s21_strcpy(char *dest, const char *src);

char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

/// часть Андрея
int s21_sscanf(const char *str, const char *format, ...);

/// часть Руслана
int s21_sprintf(char *str, const char *format, ...);
const char *firstParser(const char *str, flags *data);
const char *secondParser(const char *str, flags *data);
char *callSpecifFun(va_list *ptr, flags data, char **str, const char **format,
                    unsigned int *count);
char *integers(char **str, flags a, va_list *ptr, unsigned int *count);
char *uintegers(char **str, flags a, va_list *ptr, unsigned int *count);
char *doubles(char **str, flags a, va_list *ptr, unsigned int *count);
char *chars(char **str, flags a, va_list *ptr, const char **format,
            unsigned int *count);
char *charPointers(char **str, flags a, va_list *ptr, const char **format,
                   unsigned int *count);
char *wCharPointers(char **str, flags data,  // для работы с символами,
                    va_list *ptr,  // которые выходят за рамки ASCII
                    const char **format, unsigned int *count);
char *pointers(char **str, flags a, va_list *ptr, unsigned int *count);
char *integerPointers(char **str, va_list *ptr, unsigned int count);

// вспомогательные функции (в libs.c)
void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *reverse(char s[]);
char *ourItoa(long long int value, char *result, int base);
char *ourUItoa(long long unsigned value, char *result, int base);
int stringToInteger(const char *str);
double stringToDouble(const char *s);
void cleanFlags(flags *data);
void widthHelper(char *result, flags data, int *i, int strlength);

void process_g(int *specificator, int *precision, char *nu, int *og,
               long double x);
void cut_off_zeros(char *nu, flags data, int og);
void to_upper(char *x);
void rounding_double(int length, int precision, char *nu, flags data);
void work_with_e(long double x, flags data, int precision, char **nu1, int og);
int value_to_str(long double x, char *nu, long double x1, int *length);
void double_to_str(long double x, long double x1, char *nu, int *length);
void recursive_long_int(long double d_arg, int symbols, char **str);
void e_to_str(long double x, char *nu, char *nunu, flags a, int *i,
              int precision);
void print_base(flags data, unsigned long x, char *result, int *i,
                int *precision);
void negativeSign(char *str, int i);
void positiveSign(flags data, char *str, int i);

/// часть Анны
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int startwith(const char *src, const char *totrim, int offset);
int endwith(const char *src, const char *totrim, int offset);

#endif
