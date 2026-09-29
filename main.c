#include <stdio.h>
#include "railway.h"
void showMenu()
{
    printf("\n\n==============================================");
    printf("\n     INTELLIGENT RAILWAY RESERVATION SYSTEM");
    printf("\n==============================================\n");
    printf("\n--- MEMBER 1 : TRAIN & PASSENGER MANAGEMENT ---");
    printf("\n1.  Add Train");
    printf("\n2.  Display Trains");
    printf("\n3.  Register Passenger");
    printf("\n4.  Display Passengers");
    printf("\n\n--- MEMBER 2 : SEARCHING & SORTING ---");
    printf("\n5.  Linear Search Train");
    printf("\n6.  Binary Search Train");
    printf("\n7.  Search Passenger");
    printf("\n8.  Search Ticket");
    printf("\n9.  Bubble Sort Trains");
    printf("\n10. Selection Sort Trains");
    printf("\n11. Insertion Sort Passengers");
    printf("\n12. Seat Availability");
    printf("\n\n--- MEMBER 3 : RESERVATION & WAITING LIST ---");
    printf("\n13. Reserve Ticket");
    printf("\n14. Display Bookings");
    printf("\n15. Cancel Ticket");
    printf("\n16. Display Waiting List");
    printf("\n17. Save Data");
    printf("\n\n--- MEMBER 4 : AI & ANALYSIS ---");
    printf("\n18. AI Demand Prediction");
    printf("\n19. System Statistics");
    printf("\n20. Performance Analysis");
    printf("\n21. Run System Tests");
    printf("\n22. Project Information");
    printf("\n\n0. Exit");
    printf("\n\nEnter your choice: ");
}
int main()
{
    int choice;
    loadData();
    while (1)
    {
        showMenu();
        scanf("%d", &choice);
        switch (choice)
        {
            /* ================= MEMBER 1 ================= */
            case 1:
                addTrain();
                break;
            case 2:
                displayTrains(trains, trainCount);
                break;
            case 3:
                registerPassenger();
                break;
            case 4:
                displayPassengers(passengers, passengerCount);
                break;
            /* ================= MEMBER 2 ================= */
            case 5:
            {
                int key;
                int pos;
                printf("\nEnter train number: ");
                scanf("%d", &key);
                pos = linearSearchTrain(trains,trainCount,key);
                if (pos == -1)
                {
                    printf("\nTrain not found.\n");
                }
                else
                {
                    printf("\nTrain found!\n");
                    printf("Train Number : %d\n",trains[pos].trainNo);
                    printf("Train Name   : %s\n", trains[pos].name);
                    printf("Seats        : %d\n",trains[pos].availableSeats);
                }
                break;
            }
            case 6:
            {
                int key;
                int pos;
                struct Train copy[MAX_TRAINS];
                int i;
                for (i = 0; i < trainCount; i++)
                {
                    copy[i] = trains[i];
                }
                bubbleSort(copy, trainCount);
                printf("\nEnter train number: ");
                scanf("%d", &key);
                pos = binarySearchTrain(
                    copy,
                    trainCount,
                    key
                );
                if (pos == -1)
                {
                    printf("\nTrain not found.\n");
                }
                else
                {
                    printf("\nTrain found!\n");
                    printf("Train Number : %d\n", copy[pos].trainNo);
                    printf("Train Name   : %s\n", copy[pos].name);
                    printf("Seats        : %d\n", copy[pos].availableSeats);
                }
                break;
            }
            case 7:
                searchPassengerMenu();
                break;
            case 8:
                searchTicket();
                break;
            case 9:
                sortTrains();
                break;
            case 10:
            {
                struct Train copy[MAX_TRAINS];
                int i;
                for (i = 0; i < trainCount; i++)
                {
                    copy[i] = trains[i];
                }
                selectionSort(copy, trainCount);
                printf("\nTrains sorted by available seats:\n");
                displayTrains(copy, trainCount);
                break;
            }
            case 11:
                insertionSort(passengers, passengerCount);
                printf("\nPassengers sorted by ID:\n");
                displayPassengers( passengers,passengerCount);
                break;
            case 12:
                seatAvailability();
                break;
            /* ================= MEMBER 3 ================= */
            case 13:
                reserveTicket();
                break;
            case 14:
                displayBookings();
                break;
            case 15:
                cancelTicket();
                break;
            case 16:
                displayWaitingList();
                break;
            case 17:
                saveData();
                break;
            /* ================= MEMBER 4 ================= */
            case 18:
                demandPrediction();
                break;
            case 19:
                statistics();
                break;
            case 20:
                performanceAnalysis();
                break;
            case 21:
                testSystem();
                break;
            case 22:
                showProjectInfo();
                break;
            /* ================= EXIT ================= */
            case 0:
                saveData();
                printf("\n================================");
                printf("\nThank you for using the system!");
                printf("\n================================\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
