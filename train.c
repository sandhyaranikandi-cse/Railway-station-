#include <stdio.h>
#include "railway.h"

/* Add a new train */
void addTrain(void)
{
    int i;
    int trainNo;

    if (trainCount >= MAX_TRAINS)
    {
        printf("\nTrain limit reached.\n");
        return;
    }

    printf("\nEnter train number: ");
    scanf("%d", &trainNo);

    /* Check duplicate train number */
    for (i = 0; i < trainCount; i++)
    {
        if (trains[i].no == trainNo)
        {
            printf("Train number already exists.\n");
            return;
        }
    }

    trains[trainCount].no = trainNo;

    printf("Enter train name: ");
    scanf(" %49[^\n]", trains[trainCount].name);

    printf("Enter total seats: ");
    scanf("%d", &trains[trainCount].totalSeats);

    if (trains[trainCount].totalSeats <= 0)
    {
        printf("Seats must be greater than 0.\n");
        return;
    }

    trains[trainCount].availableSeats =
        trains[trainCount].totalSeats;

    trainCount++;

    printf("Train added successfully.\n");
}

/* Display all trains */
void displayTrains(void)
{
    int i;

    if (trainCount == 0)
    {
        printf("\nNo trains available.\n");
        return;
    }

    printf("\n========== TRAIN LIST ==========\n");

    printf("%-10s %-30s %-12s %-12s\n",
           "Number",
           "Name",
           "Total",
           "Available");

    for (i = 0; i < trainCount; i++)
    {
        printf("%-10d %-30s %-12d %-12d\n",
               trains[i].no,
               trains[i].name,
               trains[i].totalSeats,
               trains[i].availableSeats);
    }
}
