#include <stdio.h>
#include <string.h>
#define MAX 10
struct Passenger
{
    int id;
    char name[30];
    int age;
    int trainNo;
    int seatNo;
};
struct Train
{
    int trainNo;
    char name[30];
    char source[20];
    char destination[20];
    int seats;
};
struct Train trains[3] =
{
    {101, "Godavari Express", "Vizag", "Hyderabad", 10},
    {102, "Vande Bharat", "Vizag", "Vijayawada", 10},
    {103, "Konark Express", "Vizag", "Mumbai", 10}
};
struct Passenger passengers[MAX];
int passengerCount = 0;
int nextId = 1;
void displayTrains()
{
    int i;
    printf("\nTrain Details\n");
    printf("----------------------------------------\n");
    for (i = 0; i < 3; i++)
    {
        printf("Train No: %d\n", trains[i].trainNo);
        printf("Name: %s\n", trains[i].name);
        printf("From: %s\n", trains[i].source);
        printf("To: %s\n", trains[i].destination);
        printf("Available Seats: %d\n", trains[i].seats);
        printf("----------------------------------------\n");
    }
}
void bookTicket()
{
    int trainNo;
    int age;
    int i;
    int found = 0;
    if (passengerCount >= MAX)
    {
        printf("No more passengers can be added.\n");
        return;
    }
    printf("Enter train number: ");
    scanf("%d", &trainNo);
    for (i = 0; i < 3; i++)
    {
        if (trains[i].trainNo == trainNo)
        {
            found = 1;
            if (trains[i].seats == 0)
            {
                printf("No seats available.\n");
                return;
            }
            passengers[passengerCount].id = nextId++;
            passengers[passengerCount].trainNo = trainNo;
            passengers[passengerCount].seatNo = 11 - trains[i].seats;
            printf("Enter passenger name: ");
            scanf(" %[^\n]", passengers[passengerCount].name);
            printf("Enter age: ");
            scanf("%d", &age);
            passengers[passengerCount].age = age;
            trains[i].seats--;
            passengerCount++;
            printf("\nTicket booked successfully!\n");
            printf("Passenger ID: %d\n", passengers[passengerCount - 1].id);
            printf("Seat Number: %d\n",passengers[passengerCount - 1].seatNo);
            return;
        }
    }
    if (found == 0)
    {
        printf("Train not found.\n");
    }
}
