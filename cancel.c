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
void cancelTicket()
{
    struct Passenger *temp;
    struct Passenger *prev;
    int id;
    printf("Enter passenger ID: ");
    scanf("%d", &id);
    temp = head;
    prev = NULL;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            printf("Ticket cancelled.\n");
            if (front < rear)
            {
                printf("%s got the available seat.\n",
                       waitingName[front]);
                front++;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Passenger not found.\n");
}
void displayWaitingList()
{
    int i;
    if (front == rear)
    {
        printf("Waiting list is empty.\n");
        return;
    }
    printf("\nWaiting List\n");
    for (i = front; i < rear; i++)
    {
        printf("%s\n", waitingName[i]);
    }
}
