#ifndef RAILWAY_H
#define RAILWAY_H

#define MAX_TRAINS 20
#define MAX_PASSENGERS 50
#define MAX_TICKETS 100
#define MAX_WAITING 50

typedef struct {
    int no;
    char name[50];
    int totalSeats;
    int availableSeats;
} Train;

typedef struct {
    int id;
    char name[50];
} Passenger;

typedef struct {
    int ticketId;
    int passengerId;
    int trainNo;
} Ticket;

typedef struct {
    int passengerId;
    int trainNo;
} WaitingEntry;

/* Shared data */
extern Train trains[MAX_TRAINS];
extern Passenger passengers[MAX_PASSENGERS];
extern Ticket tickets[MAX_TICKETS];
extern WaitingEntry waitingList[MAX_WAITING];

extern int trainCount;
extern int passengerCount;
extern int ticketCount;
extern int waitingCount;
extern int nextTicketId;

/* Member 1 - Core data management */
void addTrain(void);
void displayTrains(void);
void addPassenger(void);
void displayPassengers(void);

/* Member 2 - Searching and sorting */
int findTrainLinear(int trainNo);
int findTrainBinary(int trainNo);
int findPassenger(int passengerId);
void sortTrainsBubble(void);
void sortTrainsBySeatsSelection(void);
void sortPassengersInsertion(void);
void searchTrainLinearMenu(void);
void searchTrainBinaryMenu(void);
void searchPassengerMenu(void);

/* Member 3 - Reservation, queue and files */
void addToWaitingQueue(int passengerId, int trainNo);
void displayWaitingQueue(void);
void promoteWaitingPassenger(int trainNo);
void reserveTicket(void);
void displayTickets(void);
void cancelTicket(void);
void saveData(void);
void loadData(void);

/* Member 4 - AI/demand analysis */
void predictDemand(void);
void showStatistics(void);

#endif
