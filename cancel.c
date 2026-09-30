#include <stdio.h>
#include "railway.h"

/* Cancel a ticket */
void cancelTicket(void)
{
    int ticketId;
    int i;
    int j;
    int trainNo;
    int trainIndex;

    printf("\nEnter ticket ID to cancel: ");
    scanf("%d", &ticketId);

    /* Search for ticket */
    for (i = 0; i < ticketCount; i++)
    {
        if (tickets[i].ticketId == ticketId)
        {
            trainNo = tickets[i].trainNo;

            /* Find the train */
            trainIndex = findTrainLinear(trainNo);

            /* Return the seat */
            if (trainIndex != -1)
            {
                trains[trainIndex].availableSeats++;
            }

            /* Remove ticket from array */
            for (j = i; j < ticketCount - 1; j++)
            {
                tickets[j] = tickets[j + 1];
            }

            ticketCount--;

            printf("\nTicket %d cancelled successfully.\n",
                   ticketId);

            /*
             * A seat is now available.
             * The first waiting passenger can be promoted.
             */
            promoteWaitingPassenger(trainNo);

            return;
        }
    }

    printf("Ticket not found.\n");
}
