#include <stdio.h>

int linearSearch(int arr[], int size, int target, int index) {
    if (index == size) 
        return -1;
    if (arr[index] == target) 
        return index;
    return linearSearch(arr, size, target, index + 1); 
}

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the target element: ");
    scanf("%d", &target);

    int pos = linearSearch(arr, n, target, 0);

    if (pos != -1)
        printf("Element found at index %d\n", pos);
    else
        printf("Element not found.\n");

    return 0;
}

