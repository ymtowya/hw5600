#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /* code */
    int* pt = (int *) malloc(2 * sizeof(int));
    *(pt) = 4;
    *(pt + 1) = 7;
    return 0;
}
