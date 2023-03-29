#include "functions.h"
#include "functionsForWords.h"
#include "words.h"
void getStr(char **string){
    int size = 0;
    int realSize = 16;
    *string = (char *)malloc(realSize * sizeof(char));
    rewind(stdin);
    char check;
    while (1) {
        check = (char)getchar();
        if (check == '\n') {
            if (size + 1 < realSize) {
                *string = (char *) realloc(*string, (size + 1) * sizeof(char));
            }
            (*string)[size] = '\0';
            return;
        }
        (*string)[size] = check;
        size++;
        if (size + 1 == realSize) {
            realSize *= 2;
            *string = (char *) realloc(*string, realSize * sizeof(char));
        }
    }
}
int cycleWord(const char *token, char *temp){
    int i = 0;
    for (int j = 0; token[j]; j++){
        temp[i++] = (char)tolower(token[j]);
    }
    temp[i] = '\0';
    return i;
}
void readFile(struct Unit *unit, const char *filePath){
    FILE *textFile = fopen(filePath, "r");
    if (textFile == NULL) {
        printf("textFile is NULL.\n");
        exit(0);
    }
    char *savePtr;
    char buffer[50];
    char temp[50];
    while (fscanf(textFile, "%s", buffer) != EOF){
        temp[0] = '\0';
        const char *token = strtok_r(buffer, " \t\n", &savePtr);
        while (token != NULL) {
            int i;
            i = cycleWord(token,temp);
            if (i > 0) {
                newNode(unit,temp);
            }
            token = strtok_r(NULL, " \t\n",&savePtr);
        }
    }
    fclose(textFile);
}
char* findMaxLenWord(const struct Unit *unit) {
    if (unit == NULL || unit->head == NULL)
        return NULL;
    int maxCount = 0;
    char *tempArray = NULL;
    struct Words *tempIterator = unit->head;
    while (tempIterator != NULL) {
        if (strlen(tempIterator->word) > 4 && tempIterator->count >= maxCount) {
            maxCount = tempIterator->count;
            tempArray = tempIterator->word;
        }
        tempIterator = tempIterator->next;
    }
    if (tempArray == NULL)
        return "tempArray is NULL";
    return tempArray;
}
int getMaxCount(const struct Unit *unit){
    int maxCount = 0;
    struct Words *tempIteration = unit->head;
    while (tempIteration != NULL) {
        if (tempIteration->count > maxCount) {
            maxCount = tempIteration->count;
        }
        tempIteration = tempIteration->next;
    }
    return maxCount;
}
char* findMinLenWord(const struct Unit *unit){
    if (unit == NULL || unit->head == NULL)
        return NULL;
    int minCount = unit->head->count + 1;
    char *tempArray = NULL;
    struct Words *tempIterator = unit->head;
    while (tempIterator != NULL) {
        if (strlen(tempIterator->word) < 3 && tempIterator->count <= minCount && tempIterator->count < getMaxCount(unit)) {
            minCount = tempIterator->count;
            tempArray = tempIterator->word;
        }
        tempIterator = tempIterator->next;
    }
    if (tempArray == NULL)
        return "tempArray is NULL";
    return tempArray;
}
void deleteSymbol(char *temp) {
    while (strlen(temp) > 0 && !isalpha(temp[strlen(temp) - 1]) &&
    (temp[strlen(temp) - 1] != '.' && temp[strlen(temp) - 1] != ',')){
        temp[strlen(temp) - 1] = '\0';
    }
}
void checkTransitionToANewLine(char *temp, const char *token) {
    int hasNewline = 0;
    if (token[strlen(token) - 1] != '\n') {
        strcat(temp, " ");
    }else{
        temp[strlen(temp) - 1] = '\0';
        hasNewline = 1;
    }
    if (token == NULL && !hasNewline) {
        strcat(temp, "\n");
    }
}
void inputSpaces(const char *buffer, char *temp, int i) {
    int numSpaces = 0;
    while (buffer[i] != '\0' && isspace(buffer[i])){
        if (!isalpha(buffer[i])) {
            numSpaces++;
        }
        i++;
    }
    for (int j = i; j < numSpaces; j++) {
        strcat(temp, " ");
    }
}
void token(char *buffer, char *temp, const char *word, const char *nWord){
    char *savePtr;
    const char *token = strtok_r(buffer, " \t\n", &savePtr);
    while (token != NULL){
        unsigned long len = strlen(token);
        if (len == 0){
            continue;
        }
        char lastChar = token[len - 1];
        if (!isalnum(lastChar)){
            char *wordOnly = malloc(len);
            strncpy(wordOnly, token, len - 1);
            wordOnly[len - 1] = '\0';
            if(strcmp(wordOnly, word) == 0){
                strcat(temp, nWord);
            }else if(strcmp(token, nWord) == 0) {
                strcat(temp, word);
            }else{
                strcat(temp, token);
            }
            free(wordOnly);
        }else{
            if(strcmp(token, nWord) == 0) {
                strcat(temp, word);
            }else if(strcmp(token, word) == 0) {
                strcat(temp, nWord);
            }else{
                strcat(temp, token);
            }
        }
        checkTransitionToANewLine(temp, token);
        token = strtok_r(NULL, " \t\n", &savePtr);
    }
}
int strangeCompression(const char *filePath, const char *word, const char *newWord){
    if (word == NULL || newWord == NULL) {
        printf("textFile is NULL.\n");
        return 1;
    }
    FILE *initialFile = fopen(filePath, "r");
    FILE *compressedFile = fopen("compressedFile.txt", "w");
    if (initialFile == NULL || compressedFile == NULL) {
        printf("Error during opening files in compression.");
        if (initialFile != NULL) {
            fclose(initialFile);
        }
        if (compressedFile != NULL) {
            fclose(compressedFile);
        }
        return 1;
    }
    fprintf(compressedFile, "%s %s ", word, newWord);
    char buffer[1000];
    while (fgets(buffer, 1000, initialFile) != NULL) {
        char *temp = (char *) calloc(1000, sizeof(char));
        inputSpaces(buffer, temp, 0);
        token(buffer, temp, word, newWord);
        deleteSymbol(temp);
        strcat(temp, "\n");
        temp = (char *) realloc(temp, (strlen(temp) + 2) * sizeof(char));
        fprintf(compressedFile, "%s", temp);
        free(temp);
    }
    fclose(initialFile);
    fclose(compressedFile);
    return 0;
}
