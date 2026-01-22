#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};
int main() {
    int n, i;
    struct Employee *ptr;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    ptr = (struct Employee*)malloc(n * sizeof(struct Employee));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &(ptr + i)->id);
        printf("Name: ");
        scanf("%s", (ptr + i)->name);
        printf("Salary: ");
        scanf("%f", &(ptr + i)->salary);
    }
    printf("\n--- Employee Information ---\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", 
                (ptr + i)->id, (ptr + i)->name, (ptr + i)->salary);
    }
    free(ptr);
    return 0;
}
