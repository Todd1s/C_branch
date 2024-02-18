#ifndef S21_GREP_H
#define S21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void matchFound(const char* fileName);
void performGrep(int ignoreCase, int invertMatch, int countMatches,
                 int printLineNumbers, int matchFoundFlag,
                 int printMatchingLines, int argc, char* argv[]);

#endif /* S21_GREP_H */