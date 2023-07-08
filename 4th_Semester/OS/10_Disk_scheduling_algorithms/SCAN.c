#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 8;
int disk_size = 200;

int cmpfunc(const void* a, const void* b);

void SCAN(int arr[], int head, char* direction) {
    int seek_count = 0;
    int distance, cur_track;
    int left[size], right[size];
    int left_count = 0, right_count = 0;

    if (strcmp(direction, "left") == 0) {
        left[left_count++] = 0;
    } else if (strcmp(direction, "right") == 0) {
        right[right_count++] = disk_size - 1;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] < head) {
            left[left_count++] = arr[i];
        }
        if (arr[i] > head) {
            right[right_count++] = arr[i];
        }
    }

    qsort(left, left_count, sizeof(int), cmpfunc);
    qsort(right, right_count, sizeof(int), cmpfunc);

    int seek_sequence[size];
    int sequence_count = 0;

    int run = 2;
    while (run--) {
        if (strcmp(direction, "left") == 0) {
            for (int i = left_count - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence[sequence_count++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            strcpy(direction, "right");
        } else if (strcmp(direction, "right") == 0) {
            for (int i = 0; i < right_count; i++) {
                cur_track = right[i];
                seek_sequence[sequence_count++] = cur_track;
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            strcpy(direction, "left");
        }
    }

    printf("Total number of seek operations = %d\n", seek_count);
}

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = { 98, 183, 41, 122, 14, 124, 65, 67 };
    int head = 53;
    char direction[] = "right";

    SCAN(arr, head, direction);

    return 0;
}
