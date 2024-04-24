#include <stdio.h>
void swap(int *x1, int* x2)
{
    int intm = *x1;
    *x1 = *x2; // Dereference pointer to x1 and store x2 at the dereferenced location
    *x2 = intm;
    return;
}

int main()
{
    int x1,x2;
    scanf("%d", &x1);
    scanf("%d", &x2);
    int a = 42;
    swap(&x1,&x2);
//    printf("Hello, World!\n");
    printf("%d", x1);
    printf("\n");
    printf("%d", x2);
    return 0;
}


