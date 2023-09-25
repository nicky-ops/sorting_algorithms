#include <stdio.h>

void print_array(int *array, size_t size) {
    size_t i;
    for (i = 0; i < size; i++) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
}

void bubble_sort(int *array, size_t size) {
    size_t i, j;
    int temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                // Swap the elements
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                // Print the array after each swap
                print_array(array, size);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, size);

    bubble_sort(arr, size);

    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}
