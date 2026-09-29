#include <stdio.h>
#include <string.h>
#include "railway.h"
void searchTrain()
{
    int number;
    int i;
    int found = 0;
    printf("\nEnter Train Number: ");
    scanf("%d", &number);
    for (i = 0; i < trainCount; i++)
    {
        if (trains[i].trainNo == number)
        {
            printf("\nTrain Found!\n");
            printf("Train Number : %d\n", trains[i].trainNo);
            printf("Train Name   : %s\n", trains[i].trainName);
            printf("Source       : %s\n", trains[i].source);
            printf("Destination  : %s\n", trains[i].destination);
            printf("Available    : %d\n", trains[i].availableSeats);
            printf("Fare         : %.2f\n", trains[i].fare);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nTrain not found.\n");
}
void searchPassenger()
{
    int id;
    int i;
    int found = 0;
    printf("\nEnter Passenger ID: ");
    scanf("%d", &id);
    for (i = 0; i < passengerCount; i++)
    {
        if (passengers[i].passengerId == id)
        {
            printf("\nPassenger Found!\n");
            printf("ID     : %d\n", passengers[i].passengerId);
            printf("Name   : %s\n", passengers[i].name);
            printf("Age    : %d\n", passengers[i].age);
            printf("Gender : %s\n", passengers[i].gender);
            printf("Phone  : %s\n", passengers[i].phone);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nPassenger not found.\n");
}
void searchTicket()
{
    int ticket;
    int i;
    int found = 0;
    printf("\nEnter Ticket Number: ");
    scanf("%d", &ticket);
    for (i = 0; i < bookingCount; i++)
    {
        if (bookings[i].ticketNo == ticket)
        {
            printf("\nTicket Found!\n");
            printf("Ticket Number : %d\n", bookings[i].ticketNo);
            printf("Passenger ID  : %d\n", bookings[i].passengerId);
            printf("Train Number  : %d\n", bookings[i].trainNo);
            printf("Seat Number   : %d\n", bookings[i].seatNo);
            printf("Status        : %s\n", bookings[i].status);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nTicket not found.\n");
}
void sortTrains()
{
    int i;
    int j;
    Train temp;
    if (trainCount < 2)
    {
        printf("\nNot enough trains to sort.\n");
        return;
    }
    for (i = 0; i < trainCount - 1; i++)
    {
        for (j = 0; j < trainCount - i - 1; j++)
        {
            if (trains[j].fare > trains[j + 1].fare)
            {
                temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
            }
        }
    }
    printf("\nTrains sorted by fare successfully.\n");
}
void seatAvailability()
{
    int number;
    int i;
    int found = 0;

    printf("\nEnter Train Number: ");
    scanf("%d", &number);

    for (i = 0; i < trainCount; i++)
    {
        if (trains[i].trainNo == number)
        {
            printf("\nTrain Number     : %d", trains[i].trainNo);
            printf("\nTotal Seats      : %d", trains[i].totalSeats);
            printf("\nAvailable Seats  : %d\n",
                   trains[i].availableSeats);

            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nTrain not found.\n");
}