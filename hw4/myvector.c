#include <stdlib.h>
#include <stdio.h>

struct myvector
{
    unsigned int capacity;
    int* arr;
    unsigned int size;
};

void myvector_insert(struct myvector* vec, int elm) {
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->arr = (int *) realloc(vec->arr, vec->capacity * sizeof(int));
    }
    *(vec->arr + vec->size) = elm;
    vec->size += 1;
}

int main(int argc, char const *argv[])
{
    /* code */
    
    struct myvector vec = {
        .capacity = 1,
        .arr = (int *) malloc(1 * sizeof(int)),
        .size = 0
    };
    for (int i = 0; i < 5; ++i) {
        myvector_insert(&vec, i);
    }

    printf("Capacity Now : %d\n", vec.capacity);
    printf("Size Now : %d\n", vec.size);

    for (int i = 0; i < 5; ++i) {
        printf("Elem[%d] : %d\n", i, vec.arr[i]);
    }

    free(vec.arr);
    vec.capacity = 0;
    vec.size = 0;

    return 0;
}
