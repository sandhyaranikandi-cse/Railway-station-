#include <stdio.h>
#include "railway.h"

/* Add a passenger */
void addPassenger(void)
{
    int i;
    int passengerId;

    if (passengerCount >= MAX_PASSENGERS)
    {
        printf("\nPassenger limit reached.\n");
        return;
    }

    printf("\nEnter passenger ID: ");
    scanf("%d", &passengerId);

    /* Check duplicate passenger ID */
    for (i = 0; i < passengerCount; i++)
    {
        if (passengers[i].id == passengerId)
        {
            printf("Passenger ID already exists.\n");
            return;
        }
    }

    passengers[passengerCount].id = passengerId;

    printf("Enter passenger name: ");
    scanf(" %49[^\n]", passengers[passengerCount].name);

    passengerCount++;

    printf("Passenger added successfully.\n");
}

/* Display all passengers */
void displayPassengers(void)
{
    int i;

    if (passengerCount == 0)
    {
        printf("\nNo passengers available.\n");
        return;
    }

    printf("\n======== PASSENGER LIST ========\n");

    printf("%-15s %-30s\n",
           "Passenger ID",
           "Name");

    for (i = 0; i < passengerCount; i++)
    {
        printf("%-15d %-30s\n",
               passengers[i].id,
               passengers[i].name);
    }
}
