#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /* code */
    int* pt = (int *) malloc(100 * sizeof(int));
    *(pt) = 4;
    *(pt + 100) = 0;
    free(pt);
    return 0;
}
