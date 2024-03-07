#include <stdio.h>

// Bubble sort function
int bubbleSort(int arr[], int n, int* bubbleMoveCount) {
    int i, j, temp, x=0;
    int moveCount = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                moveCount++;
                x++;
            }
        }
        bubbleMoveCount[i] = moveCount;
    }
    return x;
}

// Selection sort function
int selectionSort(int arr[], int n, int* selectionMoveCount) {
    printf("\n");
    int i, j, min_idx, temp, x = 0;
    int moveCount = 0;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                x++;
            }
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            moveCount++;
        }
        selectionMoveCount[i] = moveCount;
    }
    return x;
}

int main() {
    int arrBubble[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int arrSelection[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
    int bubbleMoveCount[9] = { 0 };
    int selectionMoveCount[9] = { 0 };
    int n = sizeof(arrBubble) / sizeof(arrBubble[0]), numBSort, numSSort;


    numBSort = bubbleSort(arrBubble, n, bubbleMoveCount);
    printf("Bubble sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arrBubble[i]);
    printf("\n");

    printf("Number of swaps for each element in Bubble Sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d is swaped %d times\n", arrBubble[i], bubbleMoveCount[i]);

    printf("Total number of swaps in Bubble Sort: %d\n", numBSort);

    numSSort = selectionSort(arrSelection, n, selectionMoveCount);
    printf("Selection sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arrSelection[i]);
    printf("\n");

    printf("Number of swaps for each element in Selection Sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d is swaped %d times\n", arrSelection[i], selectionMoveCount[i]);

    printf("Total number of swaps in Selection Sort: %d\n", numSSort);

    return 0;
}