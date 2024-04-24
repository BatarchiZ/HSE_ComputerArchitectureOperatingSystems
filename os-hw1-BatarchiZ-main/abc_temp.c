
#include <stdio.h>
#include <stdlib.h>

void swap(int *x1, int *x2)
{
    int intm = *x1;
    *x1 = *x2; // Dereference pointer to x1 and store x2 at the dereferenced location
    *x2 = intm;
    return;
}

int main()
{
    int n, m;
    scanf("%d", &n); // columns
    scanf("%d", &m); // rows

    int **matrix = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
    {
        matrix[i] = malloc(sizeof(int) * n);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int e;
            scanf("%d", &e);
            matrix[i][j] = e;
        }
    }





    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}
