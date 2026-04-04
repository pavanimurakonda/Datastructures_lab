#include <stdio.h>
void merge(int arr[], int left, int mid, int right) {
    int temp[20];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[20];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[n + i]);
    }
    mergeSort(arr, 0, 2 * n - 1);
    for (int i = 0; i < 2 * n; i++) {
        printf("%d", arr[i]);
        if (i != 2 * n - 1)
            printf(" ");
    }
    return 0;
}