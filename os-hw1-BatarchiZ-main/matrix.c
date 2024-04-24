
#include <stdio.h>
#include <stdlib.h>



 /// Works for non-square matrices. For square matrices would have been matrix[i][j] = matrix[j][i]
int main()
{
    int n, m;
    scanf("%d", &n); // columns
    scanf("%d", &m); // rows

    int **matrix = malloc(sizeof(int*) * m);
    for (int i = 0; i < m; ++i)
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

    int **matrixT = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        matrixT[i] = malloc(sizeof(int) * m);
    }

    printf("Initial Matrix : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrixT[j][i] = matrix[i][j];
        }
    }

    printf("Transposed matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d", matrixT[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");


    for (int i = 0; i < m; ++i)
    {
        free (matrix[i]);
        matrix[i] = NULL;
    }
    free(matrix);
    matrix = NULL;
    return 0;
}
