#include "s21_grep.h"

void matchFound(const char* fileName) { printf("%s\n", fileName); }

void performGrep(int ignoreCase, int invertMatch, int countMatches,
                 int printLineNumbers, int matchFoundFlag,
                 int printMatchingLines, int argc, char* argv[]) {
  regex_t regex;
  int regexCompileResult;
  if (ignoreCase) {
    regexCompileResult =
        regcomp(&regex, argv[optind], REG_EXTENDED | REG_ICASE);
  } else {
    regexCompileResult = regcomp(&regex, argv[optind], REG_EXTENDED);
  }

  if (regexCompileResult != 0) {
    char errorMessage[MAX_LINE_LENGTH];
    regerror(regexCompileResult, &regex, errorMessage, sizeof(errorMessage));
    printf("Ошибка при компиляции регулярного выражения: %s\n", errorMessage);
    return;
  }

  int firstFileIndex = optind + 1;

  for (int fileIndex = firstFileIndex; fileIndex < argc; fileIndex++) {
    char line[MAX_LINE_LENGTH];
    int lineCount = 0;
    int matchCount = 0;
    FILE* file = fopen(argv[fileIndex], "r");
    if (file == NULL) {
      printf("Не удалось открыть файл: %s\n", argv[fileIndex]);
      continue;
    }

    while (fgets(line, sizeof(line), file)) {
      lineCount++;

      int regexMatchResult = regexec(&regex, line, 0, NULL, 0);

      if ((!invertMatch && regexMatchResult == 0) ||
          (invertMatch && regexMatchResult != 0)) {
        if (countMatches) {
          matchCount++;
        } else if (printLineNumbers) {
          if (argc > 4) {
            printf("%s:%d:%s", argv[fileIndex], lineCount, line);
          } else {
            printf("%d:%s", lineCount, line);
          }
        } else if (matchFoundFlag) {
          matchFound(argv[fileIndex]);
          break;
        } else if (printMatchingLines) {
          if (argc > 4) {
            printf("%s:%s", argv[fileIndex], line);
          } else {
            printf("%s", line);
          }
        } else {
          if (argc > 4) {
            printf("%s:%s", argv[fileIndex], line);
          } else {
            printf("%s", line);
          }
        }
      }
    }
    if (countMatches) {
      if (argc > 4) {
        printf("%s:%d\n", argv[fileIndex], matchCount);
      } else {
        printf("%d\n", matchCount);
      }
    }

    fclose(file);
  }

  regfree(&regex);
}
