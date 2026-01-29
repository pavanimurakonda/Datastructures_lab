#include <stdio.h>
int main() {
    int arr[100], n, i, j, isUnique;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements in the array: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nUnique elements in the array are: ");
    for(i = 0; i < n; i++) {
        isUnique = 1;
        
        for(j = 0; j < n; j++) {
            if(i != j && arr[i] == arr[j]) {
                isUnique = 0;
                break;
            }
        }
        if(isUnique == 1) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
