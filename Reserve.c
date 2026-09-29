#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Passenger
{
    int id;
    char name[30];
    int seat;
    struct Passenger *next;
};
struct Passenger *head = NULL;
char waitingName[5][30];
int front = 0;
int rear = 0;
int nextId = 1;
int nextSeat = 1;
void bookTicket()
{
    struct Passenger *newPassenger;
    char name[30];
    printf("Enter passenger name: ");
    scanf("%29s", name);
    if (nextSeat <= 3)
    {
        newPassenger = malloc(sizeof(struct Passenger));
        newPassenger->id = nextId;
        strcpy(newPassenger->name, name);
        newPassenger->seat = nextSeat;
        newPassenger->next = head;
        head = newPassenger;
        printf("Ticket booked successfully.\n");
        printf("Passenger ID: %d\n", nextId);
        printf("Seat Number: %d\n", nextSeat);
        nextId++;
        nextSeat++;
    }
    else
    {
        if (rear < 5)
        {
            strcpy(waitingName[rear], name);
            rear++;
            printf("No seats available.\n");
            printf("Added to waiting list.\n");
        }
        else
        {
            printf("Waiting list is full.\n");
        }
    }
}
void displayPassengers()
{
    struct Passenger *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("No passengers.\n");
        return;
    }
    printf("\nBooked Passengers\n");
    while (temp != NULL)
    {
        printf("ID: %d  Name: %s  Seat: %d\n",
               temp->id,
               temp->name,
               temp->seat);
        temp = temp->next;
    }
}
