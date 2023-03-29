#include "set.h"

#define ELEMENT_SIZE 125

int main() {
    Set *setA = inputs_set(NULL);
    Set *setB = inputs_set(NULL);

    int fDecidion = 10, sDecidion;
    Set* current_set;
    while (fDecidion) {
         puts("Choose action:\n1. Add elements\n2. Delete last element\n3. Show the set\n0. Stop everything");
        scanf("%d", &fDecidion);

        puts("Choose set: 1 or 2?");
        scanf("%d", &sDecidion);
        current_set = (sDecidion == 1) ? setA: (sDecidion == 2) ? setB : NULL;
        if (current_set != NULL) {
            switch (fDecidion) {
                case 1:
                    current_set = inputs_set(current_set);
                    break;
                case 2:
                    current_set = delete_node(current_set);
                    break;
                case 3:
                    print_set(current_set);
                case 0:
                    break;
                default:
                    printf("There's no such option as %d\n", fDecidion);
                    break;
            }
        } else puts("You've choose wrong set");
        setA = (sDecidion == 1) ? current_set : setA;
        setB = (sDecidion == 2) ? current_set : setB;
    }
    return 0;
}
