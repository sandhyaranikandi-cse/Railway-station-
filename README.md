Intelligent Railway Reservation System
A C-language mini-project that demonstrates Data Structures and Algorithms through a railway reservation system.
Project Overview
The Intelligent Railway Reservation System is a console-based application developed in C.
The system can:
Add and display trains
Add and display passengers
Search for trains and passengers
Sort train and passenger records
Reserve railway tickets
Cancel tickets
Maintain a FIFO waiting list
Automatically promote waiting passengers when a seat becomes available
Save and load data using file handling
Calculate system statistics
Provide simple rule-based railway demand prediction
Data Structures and Algorithms
The project demonstrates:
Structures
Arrays
Queue / FIFO waiting list
Linear Search
Binary Search
Bubble Sort
Selection Sort
Insertion Sort
File Handling
Basic statistical/rule-based demand prediction
Team Contribution
Member 1 - Core Data Management
File:
member1_core.c
Responsibilities:
Define shared data structures and arrays
Add trains
Display trains
Add passengers
Display passengers
Main concepts:
Structures

Arrays



Member 2 - Searching and Sorting

File:


member2_dsa.c


Responsibilities:



Linear search

Binary search

Bubble sort

Selection sort

Insertion sort

Train search

Passenger search


Main concepts:



Searching

Sorting

Arrays

Algorithm complexity



Member 3 - Reservation, Queue and File Handling

File:


member3_application.c


Responsibilities:



Ticket reservation

Ticket cancellation

FIFO waiting queue

Automatic waiting-list promotion

Save data

Load data


Main concepts:



Queue

FIFO

Arrays

File handling



Member 4 - AI/Demand Analysis

File:


member4_ai.c


Responsibilities:



Demand calculation

Booking percentage

Waiting passenger analysis

Demand classification

Overall system statistics


Main concepts:



Arrays

Structures

Basic statistics

Rule-based demand prediction



Note: The demand prediction in this version is a rule-based/AI-inspired extension. It is not a trained machine-learning model.




File Structure

Intelligent-Railway-Reservation-System/
│
├── main.c
├── railway.h
├── member1_core.c
├── member2_dsa.c
├── member3_application.c
├── member4_ai.c
├── README.md
├── .gitignore
└── railway_data.txt

railway_data.txt is generated automatically when the program saves data. It does not need to exist before the first run.


Compilation

GCC

Open a terminal in the project folder and run:


gcc -std=c99 -Wall -Wextra main.c member1_core.c member2_dsa.c member3_application.c member4_ai.c -o railway

Run the program:


Linux / macOS

./railway

Windows

railway.exe

How the System Works

1. Add Train

Enter:



Train number

Train name

Total seats


Initially:


Available Seats = Total Seats

2. Add Passenger

Enter:



Passenger ID

Passenger name


3. Reserve Ticket

The system checks:



Whether the passenger exists

Whether the train exists

Whether the passenger already has a ticket

Whether a seat is available


If a seat is available, a ticket is generated.


If no seat is available, the passenger is placed in the waiting queue.


4. Cancel Ticket

When a confirmed ticket is cancelled:



The seat becomes available.

The first waiting passenger for that train is promoted.

A new ticket is generated for that passenger.


This demonstrates FIFO queue behavior.


Searching

Linear Search

Checks records one by one.


Time complexity:


O(n)

Binary Search

Works on the train list after sorting by train number.


Time complexity of the search:


O(log n)

The current implementation sorts before the binary search, so the complete operation also includes the sorting cost.


Sorting

Bubble Sort

Used for train numbers.


Worst-case: O(n²)

Selection Sort

Used for sorting trains by available seats.


Worst-case: O(n²)

Insertion Sort

Used for sorting passengers by passenger ID.


Worst-case: O(n²)
Best-case: O(n)

Demand Prediction

The system calculates:


Booked Seats = Total Seats - Available Seats

and:


Expected Demand =
Booked Seats + Waiting Passengers

The demand is classified using simple rules:



HIGH

MEDIUM

LOW


This provides an introductory intelligent-analysis component without requiring external ML libraries.


Data Persistence
The program stores information in:
railway_data.txt
The file contains:
Train data
Passenger data
Ticket data
Waiting-list data
Next ticket ID
The program automatically attempts to load saved data when it starts and saves data when it exits.
GitHub Setup
Create a Git repository and add the project:
git init
git add .
git commit -m "Initial railway reservation system"
git branch -M main
git remote add origin YOUR_GITHUB_REPOSITORY_URL
git push -u origin main
Replace:
YOUR_GITHUB_REPOSITORY_URL
with the URL of your GitHub repository.
Suggested GitHub Repository Description
A C-based Intelligent Railway Reservation System demonstrating arrays, structures, queues, searching, sorting, file handling, reservation management, and rule-based demand prediction.
Learning Outcomes
After completing this project, the team demonstrates:
Use of structures in C
Array-based data management
Queue implementation
Searching algorithms
Sorting algorithms
File handling
Modular programming
Team-based GitHub development
Basic intelligent demand analysis
Algorithm complexity analysis
Future Improvements
Possible future extensions include:
Linked-list based passenger management
Circular queue implementation
Priority waiting list
Seat/coach allocation
Source and destination stations
Date-wise reservations
User login
Admin module
Graph-based route management
Real machine-learning demand prediction
GUI or web interface
