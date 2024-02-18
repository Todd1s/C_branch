#include "s21_grep.h"

int main(int argc, char *argv[]) {
  int ignoreCase = 0;
  int invertMatch = 0;
  int countMatches = 0;
  int printLineNumbers = 0;
  int matchFoundFlag = 0;
  int printMatchingLines = 0;

  int option;
  struct option long_options[] = {{"ignore-case", no_argument, 0, 'i'},
                                  {"invert-match", no_argument, 0, 'v'},
                                  {"count", no_argument, 0, 'c'},
                                  {"files-with-matches", no_argument, 0, 'l'},
                                  {"line-number", no_argument, 0, 'n'},
                                  {"print-matching-lines", no_argument, 0, 'e'},
                                  {0, 0, 0, 0}};

  int option_index = 0;
  while ((option = getopt_long(argc, argv, "ivclne", long_options,
                               &option_index)) != -1) {
    switch (option) {
      case 'i':
        ignoreCase = 1;
        break;
      case 'v':
        invertMatch = 1;
        break;
      case 'c':
        countMatches = 1;
        break;
      case 'l':
        matchFoundFlag = 1;
        break;
      case 'n':
        printLineNumbers = 1;
        break;
      case 'e':
        printMatchingLines = 1;
        break;
      default:
        printf("Неверный аргумент.\n");
        return 1;
    }
  }

  if (optind >= argc) {
    printf("Неверное использование: ./grep <флаги> <шаблон> <файлы>\n");
    return 1;
  }

  performGrep(ignoreCase, invertMatch, countMatches, printLineNumbers,
              matchFoundFlag, printMatchingLines, argc, argv);

  return 0;
}