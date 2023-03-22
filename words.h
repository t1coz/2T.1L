#ifndef ARCHIVER_WORDS_H
#define ARCHIVER_WORDS_H
struct Unit{
    int size;
    struct Words *head;
    struct Words *tail;
};
struct Words{
    char word[50];
    struct Words *next;
    struct Words *last;
    int count;
};
#endif //ARCHIVER_WORDS_H
