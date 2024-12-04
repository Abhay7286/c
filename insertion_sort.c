#include <stdio.h>

void printArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void insertionSort(int* A, int n){
    int key, j;
    //for passes
    for (int i = 1; i <= n-1; i++)
    {
        key = A[i];
        j = i-1;
        // for each pass
        while (j>=0 && A[j]>key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        
    }
    
}

int main() {
    int A[] = {7,8,9,3,5,6};
    int n = 6;

    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);

    return 0;
}