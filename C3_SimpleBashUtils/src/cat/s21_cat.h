#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 256

void display_file(const char* filename, int number_nonblank, int number,
                  int squeeze_blank, int e_flag, int t_flag, int E_flag,
                  int T_flag);
void display_files(int argc, char* argv[], int number_nonblank, int number,
                   int squeeze_blank, int e_flag, int t_flag, int E_flag,
                   int T_flag);

#endif /* S21_CAT_H */