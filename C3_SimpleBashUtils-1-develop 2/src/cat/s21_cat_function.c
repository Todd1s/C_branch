#include "s21_cat.h"

void display_file(const char* filename, int number_nonblank, int number,
                  int squeeze_blank, int e_flag, int t_flag, int E_flag,
                  int T_flag) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Не удалось открыть файл: %s\n", filename);
    return;
  }

  int line_number = 1;
  char line[MAX_LINE_LENGTH];
  int prev_blank = 0;

  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    int is_blank = (line[0] == '\n');

    if (squeeze_blank && prev_blank && is_blank) continue;

    if (number_nonblank && !is_blank) printf("%6d	", line_number++);

    if (number) printf("%6d	", line_number++);

    int i = 0;
    while (line[i] != '\0') {
      char c = line[i];

      if (e_flag) {
        if (c == '\n')
          printf("$%c", c);
        else if ((c >= 0 && c < 9) || (c >= 11 && c <= 31) || c == 127)
          printf("^%c", c + 64);
        else
          printf("%c", c);
      } else if (t_flag) {
        if (c == '\t')
          printf("^I");
        else if ((c >= 0 && c <= 8) || (c > 10 && c <= 31) || c == 127)
          printf("^%c", c + 64);
        else
          printf("%c", c);
      } else {
        if (E_flag && c == '\n')
          printf("$%c", c);
        else if (T_flag && c == '\t')
          printf("^I");
        else
          printf("%c", c);
      }

      i++;
      prev_blank = is_blank;
    }
  }

  fclose(file);
}

void display_files(int argc, char* argv[], int number_nonblank, int number,
                   int squeeze_blank, int e_flag, int t_flag, int E_flag,
                   int T_flag) {
  int i;
  for (i = optind; i < argc; i++) {
    const char* filename = argv[i];
    display_file(filename, number_nonblank, number, squeeze_blank, e_flag,
                 t_flag, E_flag, T_flag);
  }
}