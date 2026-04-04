#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    int arr[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < N; i++) {
        printf("%d", arr[i]);
        if (i != N - 1)
            printf(" ");
    }
    return 0;
}