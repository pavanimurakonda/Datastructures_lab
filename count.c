#include <stdio.h>
int main() {
    int arr[100], n, count = 0;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter elements in array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }
    printf("\nTotal number of duplicate elements: %d", count);
    return 0;
}
