#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "words.h"
#ifndef ARCHIVER_FUNCTIONS_H
#define ARCHIVER_FUNCTIONS_H
void getStr(char **string);
void readFile(struct Unit *unit, char *filePath);
int getMaxCount(const struct Unit *unit);
char* findMaxLenWord(const struct Unit *unit);
char* findMinLenWord(const struct Unit *unit);
int strangeCompression(const char *filePath, const char *word, const char *newWord);
int decompression(const char *filePath);
#endif //ARCHIVER_FUNCTIONS_H
