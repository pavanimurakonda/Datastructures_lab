#include <stdio.h>
int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[n1 + n2];
    int i, k = 0;
    for (i = 0; i < n1; i++) {
        merged[k++] = arr1[i];
    }
    for (i = 0; i < n2; i++) {
        merged[k++] = arr2[i];
    }
    printf("Merged Array: ");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    return 0;
}
