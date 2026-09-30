#include <stdio.h>
#include "railway.h"

int findTrainLinear(int trainNo)
{
    int i;

    for (i = 0; i < trainCount; i++) {
        if (trains[i].no == trainNo) {
            return i;
        }
    }

    return -1;
}

int findTrainBinary(int trainNo)
{
    int left = 0;
    int right = trainCount - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (trains[mid].no == trainNo) {
            return mid;
        }

        if (trains[mid].no < trainNo) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int findPassenger(int passengerId)
{
    int i;

    for (i = 0; i < passengerCount; i++) {
        if (passengers[i].id == passengerId) {
            return i;
        }
    }

    return -1;
}

void sortTrainsBubble(void)
{
    int i, j;
    Train temp;

    for (i = 0; i < trainCount - 1; i++) {
        for (j = 0; j < trainCount - i - 1; j++) {
            if (trains[j].no > trains[j + 1].no) {
                temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
            }
        }
    }

    printf("\nTrains sorted by train number using Bubble Sort.\n");
}

void sortTrainsBySeatsSelection(void)
{
    int i, j, maxIndex;
    Train temp;

    for (i = 0; i < trainCount - 1; i++) {
        maxIndex = i;

        for (j = i + 1; j < trainCount; j++) {
            if (trains[j].availableSeats >
                trains[maxIndex].availableSeats) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            temp = trains[i];
            trains[i] = trains[maxIndex];
            trains[maxIndex] = temp;
        }
    }

    printf("\nTrains sorted by available seats using Selection Sort.\n");
}

void sortPassengersInsertion(void)
{
    int i, j;
    Passenger key;

    for (i = 1; i < passengerCount; i++) {
        key = passengers[i];
        j = i - 1;

        while (j >= 0 && passengers[j].id > key.id) {
            passengers[j + 1] = passengers[j];
            j--;
        }

        passengers[j + 1] = key;
    }

    printf("\nPassengers sorted by ID using Insertion Sort.\n");
}

void searchTrainLinearMenu(void)
{
    int trainNo, index;

    printf("\nEnter train number to search: ");
    scanf("%d", &trainNo);

    index = findTrainLinear(trainNo);

    if (index == -1) {
        printf("Train not found.\n");
    } else {
        printf("\nTrain found.\n");
        printf("Number    : %d\n", trains[index].no);
        printf("Name      : %s\n", trains[index].name);
        printf("Seats     : %d/%d available\n",
               trains[index].availableSeats,
               trains[index].totalSeats);
    }
}

void searchTrainBinaryMenu(void)
{
    int trainNo, index;

    if (trainCount == 0) {
        printf("\nNo trains available.\n");
        return;
    }

    sortTrainsBubble();

    printf("Enter train number to search: ");
    scanf("%d", &trainNo);

    index = findTrainBinary(trainNo);

    if (index == -1) {
        printf("Train not found.\n");
    } else {
        printf("\nTrain found using Binary Search.\n");
        printf("Number    : %d\n", trains[index].no);
        printf("Name      : %s\n", trains[index].name);
        printf("Seats     : %d/%d available\n",
               trains[index].availableSeats,
               trains[index].totalSeats);
    }
}

void searchPassengerMenu(void)
{
    int passengerId, index;

    printf("\nEnter passenger ID to search: ");
    scanf("%d", &passengerId);

    index = findPassenger(passengerId);

    if (index == -1) {
        printf("Passenger not found.\n");
    } else {
        printf("\nPassenger found.\n");
        printf("ID   : %d\n", passengers[index].id);
        printf("Name : %s\n", passengers[index].name);
    }
}
