#ifndef FLITADZ1_V1_SET_H
#define FLITADZ1_V1_SET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Set {
    char *element;
    struct Set *next;
} Set;

Set *push_set(Set *pSet, char *nElement);

Set *input_set(Set* pSet);

Set *inputs_set(Set* pSet);

void print_set(Set *set);

bool is_unique(Set *set, char *element);

Set *delete_node(Set *pSet);

#endif //FLITADZ1_V1_SET_H
