#include <stdio.h>
#include <stdlib.h>
void scan(int arr[], int head, int size, int direction) {
    int distance = 0;
    int current = head;
    int currentPosition;
    int seekSequence[size + 1];
    int temp[size];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == head) {
            currentPosition = i;
            break;
        }
    }
    if (direction == 0) {
        for (int i = currentPosition; i < size; i++) {
            seekSequence[i - currentPosition] = temp[i];
        }
        for (int i = currentPosition - 1; i >= 0; i--) {
            seekSequence[currentPosition - i + size - currentPosition - 1] = temp[i];
        }
    }
    else if (direction == 1) {
        for (int i = currentPosition; i >= 0; i--) {
            seekSequence[currentPosition - i] = temp[i];
        }
        for (int i = currentPosition + 1; i < size; i++) {
            seekSequence[i - currentPosition + currentPosition + 1] = temp[i];
        }
    }
    for (int i = 0; i < size; i++) {
        distance += abs(current - seekSequence[i]);
        current = seekSequence[i];
    }
    printf("Seek Sequence: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", seekSequence[i]);
    }
    printf("\nTotal Seek Distance: %d\n", distance);
}

int main() {
    int size, head, direction;
    printf("Enter the size of the request array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the request array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the initial position of the head: ");
    scanf("%d", &head);
    printf("Enter the direction (0 for forward, 1 for reverse): ");
    scanf("%d", &direction);
    scan(arr, head, size, direction);

    return 0;
}
