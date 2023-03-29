#include "functions.h"
#include "words.h"
#include "functionsForWords.h"
int main(){
    char *filePath, *minLenWord, *maxLenWord;
    struct Unit unit = {0, NULL, NULL};
    printf("\033[0;31mBeginning of the program.\033[0m\n");
    printf("Write the file path: ");
    getStr(&filePath);
    readFile(&unit, filePath);
    display(&unit);
    maxLenWord = findMaxLenWord(&unit);
    minLenWord = findMinLenWord(&unit);
    printf("Buffer: %s;\nNew word: %s.\n ", maxLenWord, minLenWord);
    strangeCompression(filePath, maxLenWord, minLenWord);
    decompression(filePath);
    deletingList(&unit);
    return 0;
}
