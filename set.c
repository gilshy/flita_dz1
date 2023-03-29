#include "set.h"

#define ELEMENT_SIZE 125

Set* push_set(Set *pSet, char *nElement) {
    Set *set = (Set*) malloc(sizeof(Set));
    set->element = nElement;
    set->next = pSet;
    return set;
}

Set* input_set(Set* pSet) {
    char* element = (char*) malloc((ELEMENT_SIZE + 1) * sizeof(char));
    scanf("%s", element);
    if (is_unique(pSet, element)) {
        return push_set(pSet, element);
    } else {
        free(element);
        return NULL;
    }
}

Set* inputs_set(Set* pSet) {
    puts("Let's fill the set! Enter end to stop filling.");
    do {
        pSet = input_set(pSet);
    } while (strcmp(pSet->element, "end"));
    return delete_node(pSet);
}

void print_set(Set *set) {
    for (Set *pSet = set; pSet != NULL; pSet = pSet->next) {
        printf("%s ", pSet->element);
    }
    putchar('\n');
}


bool is_unique(Set *set, char *element) {
    for (Set *pSet = set; pSet != NULL; pSet = pSet->next) {
        if (strcmp(element, pSet->element) == 0) {
            puts("It's not unique!");
            return false;
        }
    }
    return true;
}

Set* delete_node(Set *pSet) {
    Set *set = pSet->next;
    free(pSet->element);
    free(pSet);
    return set;
}
