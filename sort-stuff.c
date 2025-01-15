#include <stdio.h>

void swap(int* a, int* b) {
    // Swapping the two variables without using a third variable
    // Since the memory locations we have to deal with are only 
    // __sometimes__ distinct, a XOR bitwise swap isn't feasible,
    // nor would an arithmetic operation like a = a + b ; b = a - b ; a = a - b;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high]; // Use the last element as the pivot
    int i = low - 1;         // Index for smaller elements

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]); // Swap smaller element with i-th position
        }
    }

    swap(&array[i + 1], &array[high]); // Place the pivot in the correct position
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high); // Partition index

        quickSort(arr, low, partition_index - 1); // Recursively sort elements before pivot
        quickSort(arr, partition_index + 1, high); // Recursively sort elements after pivot
    }
}

int main() {
    fprintf(stdout,"Please enter your numbers, one per line, and enter an empty value for the end\n");
    
    int number;

    int list_of_numbers[128];
    int max = 128;

    char buffer[128];

    int i = 0;

    // Using a while loop to get user input
    // We break free from it when the user inputs an empty value
    while (1) {
        printf("Enter number: ");
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            break; // Handle EOF or error
        }

        // Check for empty input
        if (buffer[0] == '\n') {
            break; // User pressed Enter without typing anything
        }

        // Parse the input
        if (sscanf(buffer, "%d", &number) == 1) {
            list_of_numbers[i++] = number;
        } else {
            printf("Invalid input. Please enter an integer.\n");
        }
    }

    quickSort(list_of_numbers, 0, i - 1);

    fprintf(stdout,"Sorted list : \n");
    for (int j = 0; j < i; j++) {
        fprintf(stdout, "%d ", list_of_numbers[j]);
    }
}