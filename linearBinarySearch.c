#include <stdio.h>

int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element) {
    int low = 0, high = size - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == element) {
            return mid;
        } else if (arr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    // For linear search
    int arr1[] = {5, 54, 4, 22, 5415, 44};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int element1 = 22;
    int searchIndex1 = linearSearch(arr1, size1, element1);
    printf("The element %d was found at index %d\n", element1, searchIndex1);

    // For binary search
    int arr2[] = {1, 2, 3, 4, 5, 8, 44, 55, 60};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int element2 = 8;
    int searchIndex2 = binarySearch(arr2, size2, element2);
    printf("The element %d was found at index %d\n", element2, searchIndex2);

    return 0;
}
