
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int* pt = (int *) malloc(1 * sizeof(int));
    pt = NULL;
    printf("value : %d\n", *pt);
    free(pt);
    return 0;
}
