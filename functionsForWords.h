#include <stdio.h>
#include "words.h"
#include <stdlib.h>
#include <string.h>
#ifndef ARCHIVER_FUNCTIONSFORWORDS_H
#define ARCHIVER_FUNCTIONSFORWORDS_H
void createUnit(struct Unit *unit, const char *buffer);
void newNode(struct Unit *unit, const char *temp);
void display(struct Unit *unit);
void deletingList(struct Unit *unit);
#endif
