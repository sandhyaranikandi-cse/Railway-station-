#include <stdio.h>
#include "railway.h"

/* Promote the first waiting passenger for a train */
void promoteWaitingPassenger(int trainNo)
{
    int i;
    int j;
    int trainIndex;

    trainIndex = findTrainLinear(trainNo);

    if (trainIndex == -1)
    {
        return;
    }

    /* Make sure a seat is available */
    if (trains[trainIndex].availableSeats <= 0)
    {
        return;
    }

    /*
     * Search from the front of the queue.
     * This maintains FIFO behavior.
     */
    for (i = 0; i < waitingCount; i++)
    {
        if (waitingList[i].trainNo == trainNo)
        {
            if (ticketCount >= MAX_TICKETS)
            {
                printf("Ticket storage is full.\n");
                return;
            }

            /* Create a new ticket */
            tickets[ticketCount].ticketId = nextTicketId++;

            tickets[ticketCount].passengerId =
                waitingList[i].passengerId;

            tickets[ticketCount].trainNo = trainNo;

            ticketCount++;

            /* Allocate the available seat */
            trains[trainIndex].availableSeats--;

            printf("\n========== WAITING PASSENGER PROMOTED ==========\n");
            printf("Passenger ID : %d\n",
                   waitingList[i].passengerId);

            printf("Train No     : %d\n", trainNo);

            printf("New Ticket ID: %d\n",
                   tickets[ticketCount - 1].ticketId);

            /*
             * Remove passenger from waiting queue.
             * Shift remaining passengers forward.
             */
            for (j = i; j < waitingCount - 1; j++)
            {
                waitingList[j] = waitingList[j + 1];
            }

            waitingCount--;

            return;
        }
    }

    printf("No waiting passenger found for train %d.\n",
           trainNo);
}
