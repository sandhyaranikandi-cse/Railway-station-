#include "railway.h"
Train trains[MAX_TRAINS];
Passenger passengers[MAX_PASSENGERS];
Ticket tickets[MAX_TICKETS];
WaitingEntry waitingList[MAX_WAITING];
int trainCount = 0;
int passengerCount = 0;
int ticketCount = 0;
int waitingCount = 0;
int nextTicketId = 1001;
