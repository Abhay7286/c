#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int *A, int n)
{
    int max = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int n)
{
    int i, j;

    int max = maximum(A, n);

    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array A

    // condition: for count array
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {2, 7, 5, 46, 6};
    int n = 5;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n);
    return 0;
}