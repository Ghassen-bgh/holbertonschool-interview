#include "sort.h"

// Function to get the maximum value in an array
int get_max(int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to perform the LSD radix sort algorithm
void radix_sort(int *array, size_t size) {
    int max = get_max(array, size);

    // Allocate memory for the count and output arrays
    int *count = (int*)malloc(sizeof(int) * 10);
    int *output = (int*)malloc(sizeof(int) * size);

    // Loop through each significant digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // Initialize count array to 0
        for (int i = 0; i < 10; i++) {
            count[i] = 0;
        }

        // Count the occurrences of each digit
        for (size_t i = 0; i < size; i++) {
            count[(array[i] / exp) % 10]++;
        }

        // Calculate the cumulative count
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = size - 1; i >= 0; i--) {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        // Copy the output array to the input array
        for (size_t i = 0; i < size; i++) {
            array[i] = output[i];
        }


        for (size_t i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    // Free the memory
    free(count);
    free(output);
}
