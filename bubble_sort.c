#include "bubble_sort.h"

void bubbleSort(char** array, int size) {
    int i, j;
    char* temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(array[j], array[j + 1]) > 0) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
