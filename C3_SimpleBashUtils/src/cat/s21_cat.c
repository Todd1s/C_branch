#include "s21_cat.h"

int main(int argc, char* argv[]) {
  int opt;
  int number_nonblank = 0;
  int number = 0;
  int squeeze_blank = 0;
  int e_flag = 0;
  int t_flag = 0;
  int E_flag = 0;
  int T_flag = 0;

  static struct option long_options[] = {
      {"number-nonblank", no_argument, 0, 'b'}, {"number", no_argument, 0, 'n'},
      {"squeeze-blank", no_argument, 0, 's'},   {"e-flag", no_argument, 0, 'e'},
      {"t-flag", no_argument, 0, 't'},          {"E-flag", no_argument, 0, 'E'},
      {"T-flag", no_argument, 0, 'T'},          {0, 0, 0, 0}};

  while ((opt = getopt_long(argc, argv, "bnsetET", long_options, NULL)) != -1) {
    switch (opt) {
      case 'b':
        number_nonblank = 1;
        break;
      case 'n':
        number = 1;
        break;
      case 's':
        squeeze_blank = 1;
        break;
      case 'e':
        e_flag = 1;
        break;
      case 't':
        t_flag = 1;
        break;
      case 'E':
        E_flag = 1;
        break;
      case 'T':
        T_flag = 1;
        break;
      default:
        printf("Неверный аргумент\n");
        exit(EXIT_FAILURE);
    }
  }

  if (optind >= argc) {
    printf("Не удается открыть файл\n");
    exit(EXIT_FAILURE);
  }

  display_files(argc, argv, number_nonblank, number, squeeze_blank, e_flag,
                t_flag, E_flag, T_flag);

  return 0;
}