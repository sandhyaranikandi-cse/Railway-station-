#include <stdio.h>
#include "railway.h"

/* Add passenger to FIFO waiting queue */
void addToWaitingQueue(int passengerId, int trainNo)
{
    int i;

    if (waitingCount >= MAX_WAITING)
    {
        printf("Waiting list is full.\n");
        return;
    }

    /* Check duplicate waiting entry */
    for (i = 0; i < waitingCount; i++)
    {
        if (waitingList[i].passengerId == passengerId &&
            waitingList[i].trainNo == trainNo)
        {
            printf("Passenger is already in the waiting list.\n");
            return;
        }
    }

    waitingList[waitingCount].passengerId = passengerId;
    waitingList[waitingCount].trainNo = trainNo;

    waitingCount++;

    printf("Passenger added to waiting list.\n");
}

/* Display FIFO waiting queue */
void displayWaitingQueue(void)
{
    int i;

    if (waitingCount == 0)
    {
        printf("\nWaiting list is empty.\n");
        return;
    }

    printf("\n========== WAITING QUEUE ==========\n");
    printf("%-15s %-15s\n",
           "Passenger ID",
           "Train No");

    for (i = 0; i < waitingCount; i++)
    {
        printf("%-15d %-15d\n",
               waitingList[i].passengerId,
               waitingList[i].trainNo);
    }
}
