#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int* pt = (int *) malloc(100 * sizeof(int));
    *(pt) = 4;
    *(pt + 1) = 5;
    free(pt);
    printf("The value -0 is : %d\n", *(pt));
    printf("The value -1 is : %d\n", *(pt + 1));
    return 0;
}
