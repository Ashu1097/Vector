#include <stdio.h>
#include "vector.h"
int main(void) {
    Vector vector;
    vector_init(&vector, sizeof(int));
    const int a = 10;
    const int b = 20;
    const int c = 30;
    push_back(&vector, &a);
    push_back(&vector, &b);
    push_back(&vector, &c);
    for (size_t i = 0; i < vector.size; i++) {
        const int *element = (int *)at(&vector, i);
        if (element != NULL) {
            printf("%d ", *element);
        }
    }
    printf("\n");
    pop_back(&vector);
    for (int i = 0; i < vector.size; i++) {
        printf("%d ", vector.data[i]);
    }
    printf("\n");
    printf("After replacing");
    printf("\n");
    const int replacement = 99;
    replace(&vector, 1, &replacement);
    for (int i = 0; i < vector.size; i++) {
        printf("%d ", vector.data[i]);
    }
    printf("\n");
    printf("Element at index 2: %d\n", *(int *)at(&vector, 1));
    clear(&vector);

    Vector chars;
    vector_init(&chars, sizeof(char));

    const char c1 = 'A';
    const char c2 = 'B';
    const char c3 = 'C';

    push_back(&chars, &c1);
    push_back(&chars, &c2);
    push_back(&chars, &c3);

    printf("Char vector: ");
    for (size_t i = 0; i < chars.size; i++) {
        printf("%c ", *(char *)at(&chars, i));
    }
    printf("\n");

    destroy(&chars);

    return 0;
}
