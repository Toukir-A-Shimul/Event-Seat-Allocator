# Hogwarts Banquet Hall & Convention Center

A console-based event and seat booking system developed in C++ for managing events and booking seats in different convention halls.

## Features

* Add new events
* View all available events
* Select a convention hall for an event
* Display the current seat arrangement
* Book multiple seats together
* Automatically find separate seats using First Fit
* Check seat availability before booking
* Show booking status using a simple seat map
* Display the current date and time

## Convention Halls

The system provides three different halls:

| Hall                       |   Capacity |
| -------------------------- | ---------: |
| Harry Convention Center    |  500 seats |
| Ron Convention Center      |  400 seats |
| Hermione Convention Center | 1000 seats |

Each hall uses a different seating configuration.

## Seat Booking

The system supports two types of seat booking:

### Together Booking

Users can select a starting row and column and book multiple consecutive seats together.

The system first checks whether the requested seats are available.

### First Fit Booking

If consecutive seats are not available, the system provides an option to book separate seats using the **First Fit** approach.

The algorithm scans the seating arrangement and books available seats until the requested number of seats is reached.

## Seat Display

The seating arrangement is displayed using:

* `O` → Available seat
* `X` → Booked seat

This provides a simple visual representation of the current seat availability.

## Technologies Used

* C++
* STL `vector`
* STL `map`
* Structures
* Functions
* References
* Dynamic 2D vectors
* Basic algorithms
* Date and time handling

## Data Structures Used

### Structures

The project uses structures for:

* Event information
* Seat information
* Current date information

### Vector

A two-dimensional `vector` is used to represent the seating arrangement for each event.

### Map

A `map` is used to associate each event with its corresponding seat arrangement.

## Main Menu

The system provides the following options:

1. Book Seats
2. Add New Event
3. Show Events
4. Exit

## Booking Algorithm

The project uses a simple **First Fit** strategy for separate seat allocation.

When consecutive seats cannot be booked, the system scans the seating rows from the beginning and assigns the first available seats until the requested number of seats is fulfilled.

## How to Run

### Compile

Using a C++ compiler such as GCC:

```bash
g++ EventSeat.cpp -o EventSeat
```

### Run

On Windows:

```bash
EventSeat
```

On Linux/macOS:

```bash
./EventSeat
```

## Project Purpose

The purpose of this project is to develop a simple event and seat booking system while applying C++ programming concepts, data structures, functions, and a basic seat allocation algorithm.

## Author

**Toukir Ahmed**

Computer Science & Engineering Student
Daffodil International University

---

*This project was developed as an academic project.*
