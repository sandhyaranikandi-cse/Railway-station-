#include <stdio.h>
#include "railway.h"

/* Add a passenger to the end of the waiting list (FIFO order). */
void addToWaitingQueue(int passengerId, int trainNo)
{
    int i;

    if (waitingCount >= MAX_WAITING) {
        printf("Waiting list is full; passenger could not be queued.\n");
        return;
    }

    for (i = 0; i < waitingCount; i++) {
        if (waitingList[i].passengerId == passengerId &&
            waitingList[i].trainNo == trainNo) {
            printf("This passenger is already waiting for that train.\n");
            return;
        }
    }

    waitingList[waitingCount].passengerId = passengerId;
    waitingList[waitingCount].trainNo = trainNo;
    waitingCount++;

    printf("Added to the waiting list. Earlier entries have priority.\n");
}

void displayWaitingQueue(void)
{
    int i;

    if (waitingCount == 0) {
        printf("\nThe waiting list is empty.\n");
        return;
    }

    printf("\n------------- WAITING LIST (FIFO) -------------\n");
    printf("%-8s %-16s %-12s\n", "ORDER", "PASSENGER ID", "TRAIN NO");

    for (i = 0; i < waitingCount; i++) {
        printf("%-8d %-16d %-12d\n", i + 1,
               waitingList[i].passengerId, waitingList[i].trainNo);
    }
}
