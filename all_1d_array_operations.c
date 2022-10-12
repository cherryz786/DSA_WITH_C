// CREATED BY PHOENIXX-3

// 1-D ARRAY OPERATIONS

#include <stdio.h>
void main()
{
    int i, n, choice, arr[30];

    printf("Enter the size of an array :");
    scanf("%d", &n);
    printf("Enter the values of your array :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Your array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\nEnter 1 to insert an element in array \n");
    printf("Enter 2 to delete an element in array \n");
    printf("Enter 3 to search an element in array \n");
    printf("Enter 4 to sort elements of array in ascending order   \n");
    printf("Enter 5 to sort elements of array in descending order   \n");

    printf("Enter your array operation choice :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        int pos, val, i;
        printf("Enter your new element to insert in array :");
        scanf("%d", &val);
        printf("Enter the position where you want to insert value :");
        scanf("%d", &pos);
        for (i = n - 1; i >= pos; i--)
            arr[i + 1] = arr[i];
        arr[pos] = val;
        n++;
        printf("The elements of array after inserting new value are :");
        for (i = 0; i < n; i++)
            printf("%d\t", arr[i]);
    }
    break;
        //------------------------------------------------------------------

    case 2:
    {
        int i, pos;
        printf("Enter the position of element to delete :");
        scanf("%d", &pos);
        for (i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;

        printf("The elements of array after deletion : ");
        for (i = 0; i < n; i++)
            printf("%d\t", arr[i]);
    }
    break;
        //------------------------------------------------------------------

    case 3:
    {
        int i, num, count;
        printf("Enter your element to search : ");
        scanf("%d", &num);
        for (i = 0; i < n; i++)
        {
            if (arr[i] == num)
            {
                count++;
                printf("The element %d is found at index %d\n", num, i);
            }
        }
        if (count = 0)
            printf("The %d element not found", num);
    }
    break;
        //------------------------------------------------------------------

    case 4:
    {

        int i, j, temp;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        printf("Elements of array after sorting in ascending order are :");

        for (i = 0; i < n; i++)
            printf("%d\t", arr[i]);
    }
    break;
        //------------------------------------------------------------------

    case 5:
    {
        int i, j, temp;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        printf("Elements of array after sorting in descending order are :");
        for (i = 0; i < n; i++)

            printf("\t%d", arr[i]);
    }
    break;
    }
}
