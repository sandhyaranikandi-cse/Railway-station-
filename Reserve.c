#include <stdio.h>
#include "railway.h"

/* Reserve a railway ticket */
void reserveTicket(void)
{
    int passengerId;
    int trainNo;
    int passengerIndex;
    int trainIndex;
    int i;

    printf("\nEnter passenger ID: ");
    scanf("%d", &passengerId);

    /* Check passenger */
    passengerIndex = findPassenger(passengerId);

    if (passengerIndex == -1)
    {
        printf("Passenger not found.\n");
        printf("Please add the passenger first.\n");
        return;
    }

    printf("Enter train number: ");
    scanf("%d", &trainNo);

    /* Check train */
    trainIndex = findTrainLinear(trainNo);

    if (trainIndex == -1)
    {
        printf("Train not found.\n");
        return;
    }

    /* Check duplicate booking */
    for (i = 0; i < ticketCount; i++)
    {
        if (tickets[i].passengerId == passengerId &&
            tickets[i].trainNo == trainNo)
        {
            printf("Passenger already has a ticket for this train.\n");
            return;
        }
    }

    /* Check seat availability */
    if (trains[trainIndex].availableSeats > 0)
    {
        if (ticketCount >= MAX_TICKETS)
        {
            printf("Ticket storage is full.\n");
            return;
        }

        tickets[ticketCount].ticketId = nextTicketId++;
        tickets[ticketCount].passengerId = passengerId;
        tickets[ticketCount].trainNo = trainNo;

        ticketCount++;

        trains[trainIndex].availableSeats--;

        printf("\n========== RESERVATION SUCCESSFUL ==========\n");
        printf("Passenger ID : %d\n", passengerId);
        printf("Train No     : %d\n", trainNo);
        printf("Ticket ID    : %d\n",
               tickets[ticketCount - 1].ticketId);
    }
    else
    {
        printf("\nNo seats available on this train.\n");
        printf("Passenger will be added to the waiting queue.\n");

        addToWaitingQueue(passengerId, trainNo);
    }
}

/* Display all confirmed tickets */
void displayTickets(void)
{
    int i;

    if (ticketCount == 0)
    {
        printf("\nNo confirmed tickets.\n");
        return;
    }

    printf("\n========== CONFIRMED TICKETS ==========\n");

    printf("%-12s %-15s %-12s\n",
           "Ticket ID",
           "Passenger ID",
           "Train No");

    for (i = 0; i < ticketCount; i++)
    {
        printf("%-12d %-15d %-12d\n",
               tickets[i].ticketId,
               tickets[i].passengerId,
               tickets[i].trainNo);
    }
}
