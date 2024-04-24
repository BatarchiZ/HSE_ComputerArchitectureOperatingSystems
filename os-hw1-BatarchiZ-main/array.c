#include <stdio.h>
#include <stdlib.h>
void swap(int *x1, int* x2)
{
    int intm = *x1;
    *x1 = *x2; // Dereference pointer to x1 and store x2 at the dereferenced location
    *x2 = intm;
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int * arr = malloc(n*sizeof(int));
    for(int i = 0; i < n; i ++)
    {
        int e;
        scanf("%d", &e);
        arr[i] = e;
    }

    // Reverse array
    for(int i = 0; i < n/2; i ++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for(int i = 0; i < n; i ++)
    {
        printf("%d\n", arr[i]);
    }

    // Deallocate
    free(arr);
    return 0;
}


