#include <stdio.h>
#include "railway.h"
void displayDataSummary(void)
{
    printf("\n========== DATA SUMMARY ==========\n");
    printf("Total Trains     : %d\n", trainCount);
    printf("Total Passengers : %d\n", passengerCount);
    printf("Total Tickets    : %d\n", ticketCount);
    printf("Waiting Entries  : %d\n", waitingCount);
}
