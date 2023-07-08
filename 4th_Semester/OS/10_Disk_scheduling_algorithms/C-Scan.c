#include <stdio.h>
#include <stdlib.h>

int size = 8;
int disk_size = 200;

int cmpfunc(const void* a, const void* b);

void CSCAN(int arr[], int head) {
    int seek_count = 0;
    int distance, cur_track;
    int left[size + 1], right[size + 1];
    int left_count = 0, right_count = 0;

    left[left_count++] = 0;
    right[right_count++] = disk_size - 1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left[left_count++] = arr[i];
        if (arr[i] > head)
            right[right_count++] = arr[i];
    }

    qsort(left, left_count, sizeof(int), cmpfunc);
    qsort(right, right_count, sizeof(int), cmpfunc);

    for (int i = 0; i < right_count; i++) {
        cur_track = right[i];
        seek_count += abs(cur_track - head);
        head = cur_track;
    }

    head = 0;
    seek_count += (disk_size - 1);

    for (int i = 0; i < left_count; i++) {
        cur_track = left[i];
        seek_count += abs(cur_track - head);
        head = cur_track;
    }

    printf("Total number of seek operations = %d\n", seek_count);
}

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = { 98, 183, 41, 122, 14, 124, 65, 67 };
    int head = 53;
    CSCAN(arr, head);

    return 0;
}
