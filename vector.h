//
// Created by MAXX on 23-10-2026.
//

#ifndef C_NEW_VECTOR_H
#define C_NEW_VECTOR_H

#endif //C_NEW_VECTOR_H
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
    size_t capacity;
    size_t element_size;
} Vector;

static inline void vector_init(Vector *vector, const size_t element_size) {
    if (vector == NULL || element_size == 0) {
        perror("Vector is NULL");
    }
    vector->size = 0;
    vector->capacity = 2;
    vector->element_size = element_size;
    vector->data = malloc(vector->capacity * sizeof(int));
}

static inline int push_back(Vector *vector, const void *data) {
    if (vector->size >= vector->capacity) {
        const size_t new_capacity = vector->capacity * 2;
        void *new_data = realloc(vector->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }
    memcpy(
        (unsigned char *)vector->data + vector->size * vector->element_size,
        data,
        vector->element_size
        );
    vector->size++;
    return 1;
}

static inline int pop_back(Vector *vector) {
    if (vector == NULL || vector->size == 0) {
        return 0;
    }
    vector->size--;
    return 1;
}

static inline void* at(const Vector *vector, const size_t index) {
    if (index < 0 || index >= vector->size) {
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
    }
    return (unsigned char *)vector->data
           + index * vector->element_size;
}

static inline int replace(const Vector *vector, const size_t index, const void* data) {
    if (vector == NULL || data ==  NULL || index >= vector->size) {
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
    }
    memcpy(
        (unsigned char *)vector->data + vector->size * vector->element_size,
        data,
        vector->element_size
        );
    return 1;
}

static inline void clear(Vector *vector) {
    if (vector != NULL)
        vector->size = 0;
}

static inline void destroy(Vector *vector) {
    if (vector == NULL) {
        return;
    }
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    vector->element_size = 0;
}
