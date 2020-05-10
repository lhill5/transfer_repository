
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int item) {
    printf("%d\n", item);
}

int* insertAtIndex(int* arr, int index, int length) {
    // arr is automatically freed after realloc
    int* resize_arr = realloc(arr, sizeof(int) * length);

    int i;

    // check if 0 occurs at beginning of arr
    if (index == 0) {
        for (i = length-2; i >= 0; i--) {
            resize_arr[i+1] = resize_arr[i];
        }
        resize_arr[0] = 0;

    // check if 0 occurs at end of arr
    } else if (index == length-2) {
        resize_arr[length-1] = 0;

    // otherwise it occurs in the middle of the arr
    } else {
        for (i = length-2; i >= index; i--) {
            resize_arr[i+1] = resize_arr[i];
        }
        resize_arr[index] = 0;
    }

    return resize_arr;

}

void duplicateZeros(int* arr, int arrSize) {
    int* dup_arr = malloc(sizeof(int) * arrSize);
    memmove(dup_arr, arr, sizeof(int) * arrSize);

    int size_dup_arr = arrSize;

    int i, dup_i;
    for (i = 0, dup_i = 0; i < arrSize; i++, dup_i++) {
        if (arr[i] == 0) {
            size_dup_arr++;
            dup_arr = insertAtIndex(dup_arr, dup_i, size_dup_arr);
            dup_i++;
        }
    }
    for (i = 0; i < arrSize; i++) {
        arr[i] = dup_arr[i];
    }
    for (i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }

}

int main(void) {

  int static_arr[10] = {1,2,3,0,5,6,0,0,9,10};
  int *arr = static_arr;
  duplicateZeros(arr, 10);


  return 0;
}
