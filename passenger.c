#include <stdio.h>
#include "railway.h"

/* Register a passenger after checking the ID and available storage. */
void addPassenger(void)
{
    int id, i;

    if (passengerCount >= MAX_PASSENGERS) {
        printf("\nPassenger list is full.\n");
        return;
    }

    printf("\nPassenger ID: ");
    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("Please enter a positive numeric ID.\n");
        while (getchar() != '\n') { }
        return;
    }

    for (i = 0; i < passengerCount; i++) {
        if (passengers[i].id == id) {
            printf("That passenger ID is already registered.\n");
            return;
        }
    }

    passengers[passengerCount].id = id;
    printf("Passenger name: ");
    scanf(" %49[^\n]", passengers[passengerCount].name);

    passengerCount++;
    printf("Passenger registered successfully.\n");
}

void displayPassengers(void)
{
    int i;

    if (passengerCount == 0) {
        printf("\nNo passengers have been registered yet.\n");
        return;
    }

    printf("\n----------- REGISTERED PASSENGERS -----------\n");
    printf("%-16s %s\n", "PASSENGER ID", "NAME");
    for (i = 0; i < passengerCount; i++) {
        printf("%-16d %s\n", passengers[i].id, passengers[i].name);
    }
}
