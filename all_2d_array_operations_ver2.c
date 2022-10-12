// CREATED BY PHOENIXX-3

// 2-D ARRAY OPERATIONS

#include <stdio.h>
#include <stdlib.h>

void create1(int m, int n, int array1[m][n])
{
    printf("Enter first array elements: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &array1[i][j]);
        }
    }
}

void create2(int a, int b, int array2[a][b])
{
    printf("Enter second array elements: ");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &array2[i][j]);
        }
    }
}

void display(int m, int n, int a, int b, int array1[m][n], int array2[a][b])
{
    printf("Your first array is: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", array1[i][j]);
        }
        printf("\n");
    }
    printf("Your second array is: \n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d  ", array2[i][j]);
        }
        printf("\n");
    }
}

void Addition(int m, int n, int a, int b, int array1[m][n], int array2[a][b])
{
    if (m == a && n == b)
    {
        for (int i = 0; i < a; i++)
        {
            printf("\t");
            for (int j = 0; j < b; j++)
            {
                printf("%d  ", array2[i][j] + array1[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Both the matrices cannot be added since they are of different sizes");
    }
}

void Subtraction(int m, int n, int a, int b, int array1[m][n], int array2[a][b])
{
    int y;
    if (m == a && n == b)
    {
        printf("\t1.Subtract 2 from 1\n\t2.Subtract 1 from 2");
        printf("\n\tSelect an option: ");
        scanf("%d", &y);
        if (y == 1)
        {

            for (int i = 0; i < a; i++)
            {
                printf("\t");
                for (int j = 0; j < b; j++)
                {
                    printf("%d  ", array1[i][j] - array2[i][j]);
                }
                printf("\n");
            }
        }
        else if (y == 2)
        {
            for (int i = 0; i < a; i++)
            {
                printf("\t");
                for (int j = 0; j < b; j++)
                {
                    printf("%d  ", array2[i][j] - array1[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("\tInvalid input");
        }
    }
    else
    {
        printf("\tSubtraction is not possible since sizes of matrices are different");
    }
}

void Multiplication(int m, int n, int a, int b, int array1[m][n],
                    int array2[a][b])
{
    if (n == a)
    {
        int product[n][a];
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; i < b; i++)
            {
                for (int k = 0; k < a; k++)
                {
                    sum = sum + array1[i][k] * array2[k][j];
                }
                product[i][j] = sum;
                sum = 0;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < b; j++)
            {
                printf("%d ", product[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Multiplication not possible");
    }
}

void Transpose(int m, int n, int a, int b, int array1[m][n], int array2[a][b])
{
    int y;
    printf("\t1.Transpose of matrix 1\n\t2.Transpose of matrix 2\n");
    printf("\tSelect an option: ");
    scanf("%d", &y);
    if (y == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("\t");
            for (int j = 0; j < m; j++)
            {
                printf("%d  ", array1[j][i]);
            }
            printf("\n");
        }
    }
    else if (y == 2)
    {
        for (int i = 0; i < b; i++)
        {
            printf("\t");
            for (int j = 0; j < a; j++)
            {
                printf("%d  ", array2[j][i]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\tInvalid input");
    }
}

int main()
{
    int m, n, a, b, option;
    printf("Enter no of rows of first matrix: ");
    scanf("%d", &m);
    printf("Enter columns of first matrix: ");
    scanf("%d", &n);
    int array1[m][n];
    create1(m, n, array1);
    printf("Enter no of rows of second matrix: ");
    scanf("%d", &a);
    printf("Enter columns of second matrix: ");
    scanf("%d", &b);
    int array2[a][b];
    create2(a, b, array2);
    display(m, n, a, b, array1, array2);
    do
    {
        printf("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n5.Exit");
        printf("\nSelect an option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            Addition(m, n, a, b, array1, array2);
            break;
        case 2:
            Subtraction(m, n, a, b, array1, array2);
            break;
        case 3:
            Multiplication(m, n, a, b, array1, array2);
            break;
        case 4:
            Transpose(m, n, a, b, array1, array2);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid input");
        }

    } while (1);

    return 0;
}
