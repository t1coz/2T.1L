#include "functions.h"
#include "words.h"
#include "functionsForWords.h"
int main(){
    struct Node node = {0, NULL, NULL};
    char *filePath;
    printf("Write INITIAL text file path: ");
    getStr(&filePath);
    readFile(&node, filePath);

    fileCompression(filePath, &node);
    fileDecompression("compressedFile.txt");
    freeList(&node);
    return 0;
}