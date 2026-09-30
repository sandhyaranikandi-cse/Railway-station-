#include <stdio.h>
#include "railway.h"
static void displayMenu(void)
{
    printf("\n");
    printf("===============================================\n");
    printf("     INTELLIGENT RAILWAY RESERVATION SYSTEM\n");
    printf("===============================================\n");
    printf(" 1. Add Train\n");
    printf(" 2. Display Trains\n");
    printf(" 3. Add Passenger\n");
    printf(" 4. Display Passengers\n");
    printf(" 5. Linear Search - Train\n");
    printf(" 6. Binary Search - Train\n");
    printf(" 7. Search Passenger\n");
    printf(" 8. Bubble Sort - Train Number\n");
    printf(" 9. Selection Sort - Available Seats\n");
    printf("10. Insertion Sort - Passenger ID\n");
    printf("11. Reserve Ticket\n");
    printf("12. Display Tickets\n");
    printf("13. Cancel Ticket\n");
    printf("14. Display Waiting Queue\n");
    printf("15. Demand Prediction\n");
    printf("16. System Statistics\n");
    printf("17. Save Data\n");
    printf("18. Load Data\n");
    printf(" 0. Exit\n");
    printf("===============================================\n");
}
int main(void)
{
    int choice;
    printf("Welcome to the Intelligent Railway Reservation System!\n");
    loadData();
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n') {
            }
            continue;
        }
        switch (choice) {
            case 1:
                addTrain();
                break;
            case 2:
                displayTrains();
                break;
            case 3:
                addPassenger();
                break;
            case 4:
                displayPassengers();
                break;
            case 5:
                searchTrainLinearMenu();
                break;

            case 6:
                searchTrainBinaryMenu();
                break;
            case 7:
                searchPassengerMenu();
                break;
            case 8:
                sortTrainsBubble();
                displayTrains();
                break;
            case 9:
                sortTrainsBySeatsSelection();
                displayTrains();
                break;
            case 10:
                sortPassengersInsertion();
                displayPassengers();
                break;
            case 11:
                reserveTicket();
                break;
            case 12:
                displayTickets();
                break;
            case 13:
                cancelTicket();
                break;
            case 14:
                displayWaitingQueue();
                break;
            case 15:
                predictDemand();
                break;
            case 16:
                showStatistics();
                break;
            case 17:
                saveData();
                break;
            case 18:
                loadData();
                break;
            case 0:
                printf("\nSaving data before exit...\n");
                saveData();
                printf("Thank you for using the system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
