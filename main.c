#include "functions.h"
#include "words.h"
#include "functionsForWords.h"
int main(){
    char *filePath;
    char* minLenWord;
    char* maxLenWord;
    struct Unit unit = {0, NULL, NULL};
    printf("\033[0;31mBeginning of the program.\033[0m\n");
    printf("Write the file path: ");
    getStr(&filePath);
    readFile(&unit, filePath);
    display(&unit);
    maxLenWord = findMaxLenWord(&unit);
    minLenWord = findMinLenWord(&unit);
    printf("Most repeated long word: %s;\nLeast repeated short word: %s.\n ", maxLenWord, minLenWord);
    strangeCompression(filePath, maxLenWord, minLenWord);
    deletingList(&unit);
    return 0;
