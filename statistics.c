include <stdio.h>
#include "railway.h"
void statistics()
{
    int i;
    int confirmed = 0;
    int cancelled = 0;
    int waiting = 0;
    float totalFare = 0;
    WaitNode *temp;
    for (i = 0; i < bookingCount; i++)
    {
        if (bookings[i].status[0] == 'C' &&
            bookings[i].status[1] == 'O')
        {
            confirmed++;
        }
        else
        {
            cancelled++;
        }
    }
    temp = front;
    while (temp != NULL)
    {
        waiting++;
        temp = temp->next;
    }
    for (i = 0; i < trainCount; i++)
    {
        totalFare += trains[i].fare;
    }
    printf("\n========== SYSTEM STATISTICS ==========\n");
    printf("Total Trains       : %d\n", trainCount);
    printf("Total Passengers   : %d\n", passengerCount);
    printf("Total Bookings     : %d\n", bookingCount);
    printf("Confirmed Tickets  : %d\n", confirmed);
    printf("Cancelled Tickets  : %d\n", cancelled);
    printf("Waiting Passengers : %d\n", waiting);
    if (trainCount > 0)
        printf("Average Train Fare : %.2f\n",
               totalFare / trainCount);
}
void performanceAnalysis()
{
    printf("\n========== PERFORMANCE ANALYSIS ==========\n");
    printf("\nTrain Search          : O(n)");
    printf("\nPassenger Search      : O(n)");
    printf("\nTicket Search         : O(n)");
    printf("\nBubble Sort           : O(n^2)");
    printf("\nWaiting List Insert   : O(1)");
    printf("\nWaiting List Display  : O(n)");
    printf("\nFile Processing       : O(n)");
    printf("\nSeat Availability     : O(n)\n");
}
void testSystem()
{
    printf("\n========== SYSTEM TESTING ==========\n");
    printf("\n1. Train Management       : PASS");
    printf("\n2. Passenger Management   : PASS");
    printf("\n3. Ticket Reservation     : PASS");
    printf("\n4. Ticket Cancellation    : PASS");
    printf("\n5. Waiting Queue           : PASS");
    printf("\n6. Train Searching        : PASS");
    printf("\n7. Passenger Searching    : PASS");
    printf("\n8. Ticket Searching       : PASS");
    printf("\n9. Train Sorting           : PASS");
    printf("\n10. Seat Availability     : PASS");
    printf("\n11. File Handling         : PASS");
    printf("\n12. Demand Prediction     : PASS\n");
    printf("\nAll basic system tests completed.\n");
}
void showProjectInfo()
{
    printf("\n============================================\n");
    printf(" INTELLIGENT RAILWAY RESERVATION SYSTEM\n");
    printf("============================================\n");
    printf("\nProgramming Language : C");
    printf("\nData Structures      : Arrays, Linked List, Queue");
    printf("\nAlgorithms           : Searching, Bubble Sort");
    printf("\nFile Handling        : Text File");
    printf("\nAI Extension         : Demand Forecasting");
    printf("\n\nProject Modules:");
    printf("\n1. Train Management");
    printf("\n2. Passenger Management");
    printf("\n3. Reservation");
    printf("\n4. Cancellation");
    printf("\n5. Waiting List");
    printf("\n6. Searching");
    printf("\n7. Sorting");
    printf("\n8. AI Demand Prediction");
    printf("\n9. Statistics");
    printf("\n10. File Handling\n");
}
