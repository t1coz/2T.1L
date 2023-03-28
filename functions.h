#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "words.h"
#ifndef ARCHIVER_FUNCTIONS_H
#define ARCHIVER_FUNCTIONS_H
void getStr(char **string);
int cycleWord(const char *token, char *temp);

void readFile(struct Node *node, const char *fileName);

char *findMaxLenPopularWord(const struct Node *node);
int getMaxCount(const struct Node *node);
char *findMinLenRareWord(const struct Node *node);
int getMinCount(const struct Node *node);

void deleteSymbol(char *temp);
void checkTransitionToANewLine(char *temp, const char *token);
void inputSpaces(const char *buffer, char *temp, int i);
void token(char *buffer, char *temp, char **array, int size);
char** fillingVocabulary(const char *filePath, struct Node *node, int *size);
int fileCompression(const char *filePath, struct Node *node);
int fileDecompression(const char *compressedFilePath);



//void getStr(char **string);
//void readFile(FILE* textFile, struct Unit *unit, const char *filePath);
//int getMaxCount(const struct Unit *unit);
//--------------------------------------------
//int getPopularLongWord(struct Unit* unit, int numWords);
//int getUnpopularShortWord(struct Unit* unit, int numWords, int longWordCount);
//--------------------------------------------
//int findLongPopWord(struct Unit* unit, int wordsCount);
//int findMinRareWord(struct Unit* unit, int wordsCount);
//void printCompressedFile(FILE* initialFile, FILE* compressedFile, char* wordA, char* wordB);
//void printVocabSeparatorAt(FILE* compressedFile, char* wordA, char* wordB);
//void compression(FILE* initialFile, struct Unit* unit, int* maxLenWordPos, int* minLenWordPos);
//--------------------------------------------
//char* findMaxLenWord(const struct Unit *unit);
//char* findMinLenWord(const struct Unit *unit);
//int strangeCompression(const char *filePath, const char *word, const char *newWord);
#endif //ARCHIVER_FUNCTIONS_H
