#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define ValidUsername "crissy"
#define ValidPassword "crissy123"
#define maxRows 12
#define maxCols 4

char seats[maxRows][maxCols];
// Struct for user login
struct user {
  char username[50];
  char password[50];
};

// Define constants
# define maxBuses 50
# define maxSchedules 25
# define maxBookings 48

int busCount = 0;
int scheduleCount = 0;
int bookingCount = 0;

// Struct for bus
struct bus {
    int busID;
    char busName[30];
    int busNumber;
    int totalSeats;
    int availableSeats;
    int fare;
};

// Struct for schedule
struct schedule {
    int scheduleID;
    int busID;
    char source[30];
    char destination[30];
    char departureTime[8]; // Time format to accommodate "hh:mmAM/PM"
    int availableSeats;
};

// Struct for booking
struct booking {
    int scheduleID;
    int bookingID;
    int busID;
    int seatNumber;
    char passengerName[30];
    int fare;
};

// Function to add a bus
void addBus(struct bus *buses, int busID, const char *busName, int busNumber, int totalSeats, int fare) {
    if (busCount < maxBuses) {
        buses[busCount].busID = busID;
        buses[busCount].busNumber = busNumber;
        buses[busCount].totalSeats = totalSeats;
        buses[busCount].availableSeats = totalSeats;//initially all seats are available
        buses[busCount].fare = fare;
        strcpy(buses[busCount].busName, busName);
        busCount++;
        printf("Bus successfully added:\n");
    }
    else {
        printf("Maximum number of buses reached:\n");
    }
}

// Function to add a schedule
void addSchedule(struct schedule *schedules, int busID, const char *source, const char *destination, const char *departureTime, int availableSeats) {
    if (scheduleCount < maxSchedules) {
        schedules[scheduleCount].scheduleID = scheduleCount + 1; // Generate a unique ID
        schedules[scheduleCount].busID = busID;
        schedules[scheduleCount].availableSeats = availableSeats;
        strcpy(schedules[scheduleCount].source, source);
        strcpy(schedules[scheduleCount].destination, destination);
        strcpy(schedules[scheduleCount].departureTime, departureTime);
        scheduleCount++;
        printf("New schedule successfully added:\n");
    }
    else {
        printf("Maximum number of schedules reached:\n");
    }
}

// Function to view available seats in a schedule
void viewAvailableSeats(struct schedule *schedules, int scheduleID) {
    int index = -1;
    for (int i = 0; i < scheduleCount; i++) {
        if (schedules[i].scheduleID == scheduleID) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Available seats for Schedule ID %d: %d\n", scheduleID, schedules[index].availableSeats);
    }
    else {
        printf("Schedule not found with the specified ID.\n");
    }
}

// Function to delete a schedule
void deleteSchedule(struct schedule *schedules, int scheduleID) {
    int index = -1;
    for (int i = 0; i < scheduleCount; i++) {
        if (schedules[i].scheduleID == scheduleID) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < scheduleCount - 1; i++) {
            schedules[i] = schedules[i + 1];
        }
        scheduleCount--;
        printf("Schedule deleted successfully.\n");
    }
    else {
        printf("Schedule not found with the specified ID.\n");
    }
}

// Function to modify a schedule
void modifySchedule(struct schedule *schedules, int scheduleID, const char *source, const char *destination, const char *departureTime, int availableSeats) {
    int index = -1;
    for (int i = 0; i < scheduleCount; i++) {
        if (schedules[i].scheduleID == scheduleID) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        schedules[index].busID = schedules[index].busID; // Bus ID cannot be modified
        strcpy(schedules[index].source, source);
        strcpy(schedules[index].destination, destination);
        strcpy(schedules[index].departureTime, departureTime);
        schedules[index].availableSeats = availableSeats;
        printf("Schedule modified successfully.\n");
    }
    else {
        printf("Schedule not found with the specified ID.\n");
    }
}

// Function to display the list of buses
void viewAllBuses(struct bus *buses) {
    printf("List of all buses:\n");
    for (int i = 0; i < busCount; i++) {
        printf("Bus Number: %d, Bus Name: %s, fare %d\n", buses[i].busNumber, buses[i].busName, buses[i].fare);
    }
}

// Function to search buses by source and destination
void viewBusesBySourceDestination(struct schedule *schedules, struct bus *buses, const char *source, const char *destination) {
    printf("Buses from %s to %s:\n", source, destination);
    for (int i = 0; i < scheduleCount; i++) {
        if (strcmp(schedules[i].source, source) == 0 && strcmp(schedules[i].destination, destination) == 0) {
            int busID = schedules[i].busID;
            for (int j = 0; j < busCount; j++) {
                if (buses[j].busID == busID) {
                    printf("Bus Number: %d, Bus Name: %s, Available Seats: %d, Fare: %d\n",
                        buses[j].busNumber, buses[j].busName, schedules[i].availableSeats, buses[j].fare);
                    break;
                }
            }
        }
    }
}
// Function to delete an existing bus
void deleteBus(struct bus *buses, int busNumber) {
    int index = -1;
    for (int i = 0; i < busCount; i++) {
        if (buses[i].busNumber == busNumber) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < busCount - 1; i++) {
            buses[i] = buses[i + 1];
        }
        busCount--;
        printf("Bus with Bus Number %d deleted successfully.\n", busNumber);
    } else {
        printf("Bus not found with the specified Bus Number.\n");
    }
}

// Function to display all schedules
void viewAllSchedules(struct schedule *schedules) {
    printf("List of all schedules:\n");
    for (int i = 0; i < scheduleCount; i++) {
        printf("Schedule ID: %d, Bus ID: %d, source: %s, destination: %s, departure time: %s, available seats: %d\n",
        schedules[i].scheduleID, schedules[i].busID, schedules[i].source, schedules[i].destination, schedules[i].departureTime,
        schedules[i].availableSeats);
    }
}
// Function to initialize seats
void initializeSeats (){
   for (int i = 0; i < maxRows; i++){
    for (int j = 0; j < maxCols; j++){
     seats[i][j] = 'O' ;//'O' indicates the seat is available
    }
   }
   }
//Function to display the seating arrangement
void displaySeatingArrangement(){
   printf("Seating arrangement:\n");
   for (int i = 0; i < maxRows; i++){
    for (int j = 0; j < maxCols; j++){
        printf(" %c", seats[i][j]);
    } printf("\n");
   }
}
// Function to add booking with seat selection
void addBookingWithSeatSelection(struct schedule *schedules, struct booking *bookings, int scheduleID, int row, int col, const char *passengerName, struct bus *buses) {
    if (row >= 1 && row <= maxRows && col >= 1 && col <= maxCols) {
        if (seats[row - 1][col - 1] == 'O') {
            // Seat is available
            int bookingID = bookingCount + 1; // Generate a unique booking ID
            int fare = 0; // Initialize fare

            for (int i = 0; i < scheduleCount; i++) {
                if (schedules[i].scheduleID == scheduleID) {
                    if (schedules[i].availableSeats > 0) {
                        schedules[i].availableSeats--; // Decrease available seats
                        bookingCount++;
                        bookings[bookingCount - 1].scheduleID = scheduleID;
                        bookings[bookingCount - 1].bookingID = bookingID;
                        bookings[bookingCount - 1].busID = schedules[i].busID;
                        bookings[bookingCount - 1].seatNumber = (row - 1) * maxCols + col; // Convert row and column to seat number
                        strcpy(bookings[bookingCount - 1].passengerName, passengerName);

                        // Mark the seat as booked
                        seats[row - 1][col - 1] = 'X'; // 'X' represents a booked seat
                        displaySeatingArrangement();

                        // Calculate the fare based on the bus ID
                        for (int j = 0; j < busCount; j++) {
                            if (buses[j].busID == bookings[bookingCount - 1].busID) {
                                fare = buses[j].fare;
                                break;
                            }
                        }

                        // Assign the calculated fare
                        bookings[bookingCount - 1].fare = fare;
                        printf("Booking added successfully. Seat %d booked.\n", bookings[bookingCount - 1].seatNumber);
                        return; // Exit the function after a successful booking
                    } else {
                        printf("This schedule has no available seats left.\n");
                        return; // Exit the function if no seats are available
                    }
                }
            }
            printf("Schedule ID not found. Booking not added.\n");
        } else {
            printf("Seat %d is already booked. Please choose another seat.\n", (row - 1) * maxCols + col);
        }
    } else {
        printf("Invalid seat selection. Row and column numbers are out of range.\n");
    }
}
// Function to generate a ticket receipt
void generateTicket(struct booking *bookings, int bookingID) {
    if (bookingID > 0 && bookingID <= bookingCount) {
        printf("Ticket Receipt:\n");
        printf("Bus Number: %d\n", bookings[bookingID - 1].busID);
        printf("Seat Number: %d\n", bookings[bookingID - 1].seatNumber);
        printf("Fare Paid: %d\n", bookings[bookingID - 1].fare);
        printf("Schedule ID: %d\n", bookings[bookingID - 1].scheduleID);
    } else {
        printf("Invalid booking ID.\n");
    }
};

//Function to cancel ticket
void cancelTicket(struct booking *bookings, struct schedule *schedules, int bookingID){
    if (bookingID > 0 && bookingID <= bookingCount){
        int scheduleID = bookings[bookingCount - 1].scheduleID;
        for(int i = 0; i < scheduleCount; i++){
            if(schedules[i].scheduleID == scheduleID){
                schedules[i].availableSeats++;
                break;
            }
        } for (int i = bookingID - 1; i < bookingCount; i++){
             bookings[i] = bookings[i + 1];
        }bookingCount--;
        printf("Ticket with booking ID %d has been canceled successfully:\n", bookingID);
    }else {
         printf("Invalid booking Id:\n");
     }
}
// Function to cancel a booking
void cancelBooking(struct booking *bookings, struct schedule *schedules, int bookingID) {
    if (bookingID > 0 && bookingID <= bookingCount) {
        int scheduleID = bookings[bookingID - 1].scheduleID;

        // Update available seats in the corresponding schedule
        for (int i = 0; i < scheduleCount; i++) {
            if (schedules[i].scheduleID == scheduleID) {
                schedules[i].availableSeats++;
                break;
            }
        }

        // Remove the booking from the list
        for (int i = bookingID - 1; i < bookingCount - 1; i++) {
            bookings[i] = bookings[i + 1];
        }

        bookingCount--;
        printf("Booking canceled successfully.\n");
    } else {
        printf("Invalid booking ID.\n");
    }
}


// Function to view all bookings
void viewAllBookings(struct booking *bookings) {
    printf("List all bookings:\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("Schedule ID: %d, Booking ID: %d, Bus ID: %d, Seat Number: %d, Passenger Name: %s, Fare: %d\n",
        bookings[i].scheduleID, bookings[i].bookingID, bookings[i].busID, bookings[i].seatNumber, bookings[i].passengerName, bookings[i].fare);
    }
}

// Function to write all bookings to a file
void writeBookingsToFile(struct booking *bookings) {
    FILE *file = fopen("bookings.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    for (int i = 0; i < bookingCount; i++) {
        fprintf(file, "%d, %d, %d, %d, %s, %d\n", bookings[i].scheduleID, bookings[i].bookingID, bookings[i].busID, bookings[i].seatNumber, bookings[i].passengerName, bookings[i].fare);
    }
    fclose(file);
    printf("Bookings saved to file.\n");
}

// Function to read bookings from a file
int readBookingsFromFile(struct booking *bookings) {
    FILE *file = fopen("bookings.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return bookingCount;
    }
    int readCount = 0;
    while (readCount < maxBookings && fscanf(file, "%d, %d, %d, %d, %s, %d\n",
          &bookings[readCount].scheduleID, &bookings[readCount].bookingID, &bookings[readCount].busID,
          &bookings[readCount].seatNumber, bookings[readCount].passengerName, &bookings[readCount].fare) == 6) {
        readCount++;
    }
    fclose(file);
    return readCount;
}
// Function to delete bookings from file
void deleteBookingFromFile(struct booking *bookings, int bookingID) {
    FILE *file = fopen("bookings.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating a temporary file.\n");
        fclose(file);
        return;
    }
    int found = 0;

    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].bookingID == bookingID) {
            found = 1;
        } else {
            fprintf(tempFile, "%d, %d, %d, %d, %s, %d\n",
                bookings[i].scheduleID, bookings[i].bookingID, bookings[i].busID,
                bookings[i].seatNumber, bookings[i].passengerName, bookings[i].fare);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("bookings.txt");
        rename("temp.txt", "bookings.txt");
        bookingCount--;
        printf("Booking with Booking ID %d has been deleted from the file.\n", bookingID);
    } else {
        remove("temp.txt");
        printf("Booking with Booking ID %d not found in the file.\n", bookingID);
    }
}
// Function to display the main menu
void displayMainMenu() {
    printf("\nMain Menu:\n");
    printf("1. Bus Management\n");
    printf("2. Schedule Management\n");
    printf("3. Booking Management\n");
    printf("4. Exit\n");
}

// Function to display the bus management menu
void displayBusMenu() {
    printf("\nBus Management Menu:\n");
    printf("1. Add Bus\n");
    printf("2. View All Buses\n");
    printf("3. Search Buses by Source and Destination\n");
    printf("4. Delete existing bus\n");
    printf("5. Back to Main Menu\n");
}

// Function to display the schedule management menu
void displayScheduleMenu() {
    printf("\nSchedule Management Menu:\n");
    printf("1. Add Schedule\n");
    printf("2. View All Schedules\n");
    printf("3. View Available Seats in a Schedule\n");
    printf("4. Modify Schedule\n");
    printf("5. Delete Schedule\n");
    printf("6. Back to Main Menu\n");
}

// Function to display the booking management menu
void displayBookingMenu() {
    printf("\nBooking Management Menu:\n");
    printf("1. Add Booking\n");
    printf("2. save bookings to file\n");
    printf("3. View All Bookings\n");
    printf("4. Generate a Ticket\n");
    printf("5. Cancel Booking\n");
    printf("6. Delete Bookings from File\n");
    printf("7. Delete Ticket\n");
    printf("8. Back to Main Menu\n");
}

//function to hide password for security reasons
void readPassword (char *password, int MAX_LENGTH){

int i = 0;
char c;

while (i < MAX_LENGTH - 1){
    c = _getch();//use the '_getch' function to read characters without echoing/potraying them to the console

  if (c == '\r') {//handles enter key
    break;

  }else if (c == '\b' && i > 0){//handles the backspace key
    i--;
 printf("\b \b");//Erase character from the console

  }else if (c != '\b'){
    password[i] = c;
    i++;
 printf("*");//replacing the characters in the password with the asterisk

  }
}
  password[i] = '\0';//Null-terminate the password string
}
int authenticateUser(){

  char username[50];
  char password[50];

 printf("Enter your username: ");
 scanf("%s", username);

 printf("Enter your password: ");
 readPassword(password, sizeof(password));

 if (strcmp(username, ValidUsername) == 0 && strcmp(password, ValidPassword) == 0 ){
    printf("\nlogin successful! welcome %s:\n ", username);
    return 1;//indicates login is successful
 }else {
    printf("\nlogin failed! please check your password and username:\n");
    return 0;//indicate login failed
 }
 }
int main() {
    struct bus buses[maxBuses];
    struct schedule schedules[maxSchedules];
    struct booking bookings[maxBookings];
    initializeSeats();

    // Initializing with some sample data for both buses and schedules
    addBus(buses, 1, "Bliss", 1, 48, 1200);
    addBus(buses, 2, "Carlson", 2, 48, 1200);
    addBus(buses, 3, "Hellfire", 3, 48, 1400);
    addBus(buses, 4, "Khaleesi", 4, 48 , 800);

    addSchedule(schedules, 1, "Nairobi", "Mombasa", "08:00AM", 48);
    addSchedule(schedules, 2, "Nairobi", "Kisumu", "09:45AM", 48);
    addSchedule(schedules, 3, "Mombasa", "Nairobi", "11:00AM", 48);
    addSchedule(schedules, 4, "Nairobi", "Nakuru", "07:00AM", 48);


    printf("************************************WELCOME TO CRISSY'S TRAVELS*************************************\n");

  int loggedIn = 0;

  while(!loggedIn){
    printf("\n Welcome to bus management login\n:");
    loggedIn = authenticateUser();
    system("cls");
  }
    int choice;
    int mainMenuFlag = 1; // Flag to indicate if the user wants to return to the main menu
    while (1) {
       if (mainMenuFlag) {
       displayMainMenu();
       printf("Enter your choice:");
       scanf("%d", &choice);
       mainMenuFlag = 0;
    }
      switch (choice){
      case 1://Bus Management
      while (1){
        displayBusMenu();
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice){
    case 1: {
                int busID, busNumber, totalSeats, fare;
                char busName[30];
                printf("Enter Bus ID: ");
                scanf("%d", &busID);
                printf("Enter Bus Number: ");
                scanf("%d", &busNumber);
                printf("Enter Bus Name: ");
                scanf("%s", busName);
                printf("Enter Total Seats: ");
                scanf("%d", &totalSeats);
                printf("Enter bus fare:");
                scanf("%d", &fare);
                addBus(buses, busID, busName, busNumber, totalSeats, fare);
                break;
            }
        case 2:
                viewAllBuses(buses);
                break;
        case 3: {
                char source[30], destination[30];
                printf("Enter Source: ");
                scanf("%s", source);
                printf("Enter Destination: ");
                scanf("%s", destination);
                viewBusesBySourceDestination(schedules, buses, source, destination);
                break;
            }
            case 4: {
                int busNumber;
                printf("Enter Bus Number to delete: ");
                scanf("%d", &busNumber);
                deleteBus(buses, busNumber);
                break;
         }

        case 5:
            //Back to main menu
            mainMenuFlag = 1;
            break;
        default:
            printf("Invalid choice:\n");
        }
        if (mainMenuFlag)
            break;
    }
    break;
    case 2://Schedule management
      while(1){
        displayScheduleMenu();
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice){
        case 1: {
                int busID, availableSeats;
                char source[30], destination[30], departureTime[8];
                printf("Enter Bus ID: ");
                scanf("%d", &busID);
                printf("Enter Source: ");
                scanf("%s", source);
                printf("Enter Destination: ");
                scanf("%s", destination);
                printf("Enter Departure Time (hh:mmAM/PM): ");
                scanf("%s", departureTime);
                printf("Enter Available Seats: ");
                scanf("%d", &availableSeats);
                addSchedule(schedules, busID, source, destination, departureTime, availableSeats);
                break;
            }
        case 2:
                viewAllSchedules(schedules);
                break;
        case 3:  {
                int scheduleID;
                printf("Enter Schedule ID: ");
                scanf("%d", &scheduleID);
                viewAvailableSeats(schedules, scheduleID);
                break;
            }
        case 4: {
                int scheduleID, availableSeats;
                char source[30], destination[30], departureTime[8];
                printf("Enter Schedule ID to modify: ");
                scanf("%d", &scheduleID);
                printf("Enter new Source: ");
                scanf("%s", source);
                printf("Enter  new Destination: ");
                scanf("%s", destination);
                printf("Enter new Departure Time (hh:mmAM/PM): ");
                scanf("%s", departureTime);
                printf("Enter Available Seats: ");
                scanf("%d", &availableSeats);
                modifySchedule(schedules, scheduleID, source, destination, departureTime, availableSeats);
                break;
            }
        case 5: {
                int scheduleID;
                printf("Enter Schedule ID to delete: ");
                scanf("%d", &scheduleID);
                deleteSchedule(schedules, scheduleID);
                break;
            }
        case 6:
            //back to main menu
            mainMenuFlag = 1;
            break;
        }
        if (mainMenuFlag)
            break;
      }
      break;
        case 3://Booking management
            while (1){
                displayBookingMenu();
                printf("Enter your choice:");
                scanf("%d", &choice);

            switch (choice){
        case 1: {
                 int scheduleID;
                 printf("Enter Schedule ID: ");
                 scanf("%d", &scheduleID);
                 // Display seating arrangement
                 displaySeatingArrangement(); // Display seating arrangement

                 int row, col;
                 printf("Enter the row and column for the seat (e.g., 2 3): ");
                 scanf("%d %d", &row, &col);
                 char passengerName[30];
                 printf("Enter Passenger Name: ");
                 scanf("%s", passengerName);
                 addBookingWithSeatSelection(schedules, bookings, scheduleID, row, col, passengerName, buses);
                break;
              }
        case 2:
            writeBookingsToFile(bookings);
                break;
        case 3:
                 viewAllBookings(bookings);
                break;
        case 4: {
                int bookingID;
                printf("Enter the booking ID to generate ticket: ");
                scanf("%d", &bookingID);
                generateTicket(bookings, bookingID);
                break;
            }
        case 5: {
                int bookingID;
                printf("Enter Booking ID to cancel: ");
                scanf("%d", &bookingID);
                cancelBooking(bookings, schedules, bookingID);
                break;
            }
        case 6: {
                // Delete booking from file
                int bookingIDToDelete;
                printf("Enter Booking ID to delete from file: ");
                scanf("%d", &bookingIDToDelete);
                deleteBookingFromFile(bookings, bookingIDToDelete);
                break;
            }
        case 7: {
                // Delete Ticket
                int bookingID;
                printf("Enter Booking ID to delete: ");
                scanf("%d", &bookingID);
                cancelBooking(bookings, schedules, bookingID);
                break;
            }
        case 8:
            //Back to main menu
            mainMenuFlag = 1;
            break;
            }
            if (mainMenuFlag)
                break;
        }
        break;
        case 4:
            return 0;//exit the program

        default:
            printf("Invalid choice:\n");
    }

    }
    return 0;
};
