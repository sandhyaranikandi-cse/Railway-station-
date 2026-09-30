#include <stdio.h>
#include "railway.h"
/* Demand calculation and prediction */
void predictDemand(void)
{
    int i;
    int j;
    int booked;
    int waiting;
    int expectedDemand;
    double bookingPercentage;

    if (trainCount == 0)
    {
        printf("\nNo trains available for demand prediction.\n");
        return;
    }

    printf("\n========== DEMAND PREDICTION ==========\n");

    for (i = 0; i < trainCount; i++)
    {
        /* Calculate booked seats */
        booked = trains[i].totalSeats -
                 trains[i].availableSeats;

        /* Count waiting passengers for this train */
        waiting = 0;

        for (j = 0; j < waitingCount; j++)
        {
            if (waitingList[j].trainNo == trains[i].no)
            {
                waiting++;
            }
        }

        /* Simple demand calculation */
        expectedDemand = booked + waiting;

        /* Calculate booking percentage */
        if (trains[i].totalSeats > 0)
        {
            bookingPercentage =
                ((double)booked / trains[i].totalSeats) * 100.0;
        }
        else
        {
            bookingPercentage = 0.0;
        }

        printf("\nTrain %d - %s\n",
               trains[i].no,
               trains[i].name);

        printf("Total Seats        : %d\n",
               trains[i].totalSeats);

        printf("Booked Seats       : %d\n",
               booked);

        printf("Waiting Passengers : %d\n",
               waiting);

        printf("Booking Percentage : %.2f%%\n",
               bookingPercentage);

        printf("Expected Demand    : %d\n",
               expectedDemand);

        /* Rule-based demand classification */
        if (bookingPercentage >= 80.0 || waiting >= 5)
        {
            printf("Demand Level       : HIGH\n");
        }
        else if (bookingPercentage >= 50.0 || waiting >= 2)
        {
            printf("Demand Level       : MEDIUM\n");
        }
        else
        {
            printf("Demand Level       : LOW\n");
        }
    }
}

/* Display overall project statistics */
void showStatistics(void)
{
    int i;

    int totalSeats = 0;
    int availableSeats = 0;
    int bookedSeats = 0;

    /* Calculate total and available seats */
    for (i = 0; i < trainCount; i++)
    {
        totalSeats += trains[i].totalSeats;
        availableSeats += trains[i].availableSeats;
    }

    /* Calculate booked seats */
    bookedSeats = totalSeats - availableSeats;

    printf("\n========== SYSTEM STATISTICS ==========\n");

    printf("Total Trains       : %d\n",
           trainCount);

    printf("Total Passengers   : %d\n",
           passengerCount);

    printf("Confirmed Tickets  : %d\n",
           ticketCount);

    printf("Waiting
