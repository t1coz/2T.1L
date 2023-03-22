#include "functionsForWords.h"
#include "words.h"

void createUnit(struct Unit *unit, const char *buffer){
    struct Words *word = (struct Words *) malloc(sizeof(struct Words));
    if (strlen(buffer) <= 50){
        strcpy(word->word, buffer);
    }else{
        free(word);
        exit(0);
    }
    word->count = 1;
    word->next = NULL;
    word->last = unit->tail;
    if (unit->head == NULL){
        unit->head = word;
        unit->tail = word;
    }else{
        unit->tail->next = word;
        word->last = unit->tail;
        unit->tail = word;
    }
    unit->size++;
}
void newNode(struct Unit *unit, const char *temp){
    struct Words *tempIteration = unit->head;
    while (tempIteration != NULL) {
        if (strcmp(tempIteration->word, temp) == 0){
            tempIteration->count++;
            break;
        }
        tempIteration = tempIteration->next;
    }
    if (tempIteration == NULL) {
        createUnit(unit, temp);
    }
}
void display(struct Unit *unit){
    struct Words *tempIterator = unit->head;
    while (tempIterator != NULL){
        printf("%s --> %d;\n", tempIterator->word, tempIterator->count);
        tempIterator = tempIterator->next;
    }
}
void deletingList(struct Unit *unit) {
    struct Words *tempIterator = unit->head;
    while (tempIterator != NULL){
        struct Words *following = tempIterator->next;
        free(tempIterator);
        tempIterator = following;
    }
    unit->size = 0;
    unit->head = NULL;
    unit->tail = NULL;
}
