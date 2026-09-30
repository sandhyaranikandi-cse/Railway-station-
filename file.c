#include <stdio.h>
#include "railway.h"

/* Save all system data */
void saveData(void)
{
    FILE *file;
    int i;

    file = fopen("railway_data.txt", "w");

    if (file == NULL)
    {
        printf("Unable to open data file.\n");
        return;
    }

    /*
     * Save counters and next ticket ID
     */
    fprintf(file, "%d %d %d %d %d\n",
            trainCount,
            passengerCount,
            ticketCount,
            waitingCount,
            nextTicketId);

    /* Save trains */
    for (i = 0; i < trainCount; i++)
    {
        fprintf(file, "%d|%s|%d|%d\n",
                trains[i].no,
                trains[i].name,
                trains[i].totalSeats,
                trains[i].availableSeats);
    }

    /* Save passengers */
    for (i = 0; i < passengerCount; i++)
    {
        fprintf(file, "%d|%s\n",
                passengers[i].id,
                passengers[i].name);
    }

    /* Save tickets */
    for (i = 0; i < ticketCount; i++)
    {
        fprintf(file, "%d|%d|%d\n",
                tickets[i].ticketId,
                tickets[i].passengerId,
                tickets[i].trainNo);
    }

    /* Save waiting queue */
    for (i = 0; i < waitingCount; i++)
    {
        fprintf(file, "%d|%d\n",
                waitingList[i].passengerId,
                waitingList[i].trainNo);
    }

    fclose(file);

    printf("Data saved successfully.\n");
}

/* Load all system data */
void loadData(void)
{
    FILE *file;
    int i;

    file = fopen("railway_data.txt", "r");

    if (file == NULL)
    {
        printf("No saved data found.\n");
        printf("Starting with empty system.\n");
        return;
    }

    /*
     * Load counters and ticket ID
     */
    if (fscanf(file,
               "%d %d %d %d %d\n",
               &trainCount,
               &passengerCount,
               &ticketCount,
               &waitingCount,
               &nextTicketId) != 5)
    {
        printf("Invalid data file.\n");

        fclose(file);

        trainCount = 0;
        passengerCount = 0;
        ticketCount = 0;
        waitingCount = 0;
        nextTicketId = 1001;

        return;
    }

    /* Check array limits */
    if (trainCount < 0 ||
        trainCount > MAX_TRAINS ||
        passengerCount < 0 ||
        passengerCount > MAX_PASSENGERS ||
        ticketCount < 0 ||
        ticketCount > MAX_TICKETS ||
        waitingCount < 0 ||
        waitingCount > MAX_WAITING)
    {
        printf("Data file contains invalid values.\n");

        fclose(file);

        trainCount = 0;
        passengerCount = 0;
        ticketCount = 0;
        waitingCount = 0;
        nextTicketId = 1001;

        return;
    }

    /* Load trains */
    for (i = 0; i < trainCount; i++)
    {
        fscanf(file,
               "%d|%49[^|]|%d|%d\n",
               &trains[i].no,
               trains[i].name,
               &trains[i].totalSeats,
               &trains[i].availableSeats);
    }

    /* Load passengers */
    for (i = 0; i < passengerCount; i++)
    {
        fscanf(file,
               "%d|%49[^\n]\n",
               &passengers[i].id,
               passengers[i].name);
    }

    /* Load tickets */
    for (i = 0; i < ticketCount; i++)
    {
        fscanf(file,
               "%d|%d|%d\n",
               &tickets[i].ticketId,
               &tickets[i].passengerId,
               &tickets[i].trainNo);
    }

    /* Load waiting queue */
    for (i = 0; i < waitingCount; i++)
    {
        fscanf(file,
               "%d|%d\n",
               &waitingList[i].passengerId,
               &waitingList[i].trainNo);
    }

    fclose(file);

    printf("Data loaded successfully.\n");
}
