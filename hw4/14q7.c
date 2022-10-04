#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int* pt = (int *) malloc(100 * sizeof(int));
    *(pt) = 4;
    free(pt + 8);
    return 0;
}
