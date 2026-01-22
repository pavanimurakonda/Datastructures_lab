#include <stdio.h>
struct Car {
    int carID;
    char model[50];
    float rentalRate;
};
int main() {
    struct Car cars[3];
    int days;
    float totalCost = 0;

    for (int i = 0; i < 3; i++) {
        printf("Enter details for Car %d:\n", i + 1);
        printf("Car ID: ");
        scanf("%d", &cars[i].carID);
        printf("Model: ");
        scanf("%s", cars[i].model);
        printf("Rental Rate per Day: ");
        scanf("%f", &cars[i].rentalRate);
        printf("\n");
    }

    printf("Enter the number of days for rental: ");
    scanf("%d", &days);

    printf("\n--- Rental Details ---\n");
    for (int i = 0; i < 3; i++) {
        float cost = cars[i].rentalRate * days;
        printf("Car ID: %d | Model: %s | Total Cost: %.2f\n", 
                cars[i].carID, cars[i].model, cost);
        totalCost += cost;
    }
    printf("\nCombined Total Rental Cost for all cars: %.2f\n", totalCost);
    return 0;
}
