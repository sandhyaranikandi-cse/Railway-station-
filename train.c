#include <stdio.h>
#include "railway.h"
void addTrain(void)
{
    int number, seats, i;
    if (trainCount >= MAX_TRAINS) {
        printf("\nTrain storage is full.\n");
        return;
    }
    printf("\nTrain number: ");
    if (scanf("%d", &number) != 1 || number <= 0) {
        printf("Enter a valid positive train number.\n");
        while (getchar() != '\n') { }
        return;
    }
    for (i = 0; i < trainCount; i++) {
        if (trains[i].no == number) {
            printf("This train number is already in use.\n");
            return;
        }
    }
    printf("Train name: ");
    scanf(" %49[^\n]", trains[trainCount].name);
    printf("Total seats: ");
    if (scanf("%d", &seats) != 1 || seats <= 0) {
        printf("Seat count must be a positive number. Train was not added.\n");
        while (getchar() != '\n') { }
        return;
    }
    trains[trainCount].no = number;
    trains[trainCount].totalSeats = seats;
    trains[trainCount].availableSeats = seats;
    trainCount++;
    printf("Train added. All %d seats are currently available.\n", seats);
}
void displayTrains(void)
{
    int i;
    if (trainCount == 0) {
        printf("\nNo trains are registered.\n");
        return;
    }
    printf("\n---------------- TRAIN DETAILS ----------------\n");
    printf("%-12s %-30s %-12s %-12s\n",
           "TRAIN NO", "TRAIN NAME", "TOTAL", "AVAILABLE");
    for (i = 0; i < trainCount; i++) {
        printf("%-12d %-30s %-12d %-12d\n",
               trains[i].no, trains[i].name,
               trains[i].totalSeats, trains[i].availableSeats);
    }
}
