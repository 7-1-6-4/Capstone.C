This Capstone.C project is a bus management stystem/program written in C programming language. When the program is run on any IDE that supports a C compiler i.e code blocks,falcon c++ or Vs code with MingW compiler installed and Code Runner extension installed, then the user should be able to view and operate on all possible manipulations in the system.

The program contains structures(structs) for user, bus, schedules and bookings and some void functions. Some of the void functions include: Function to add bus, function to add 
booking and function to view all schedules.
Each struct contains related variables. Example the struct for user has:
struct user {
  char username[50];
  char password[50];
};
The character variables store the user's username and password.
The program also entails the use of files to store persistent data. In this program there is a text file to store bookings(bookings.txt). 
I also have a fuction to display the main menu which has bus management, schedules management, bookings management sub-menus and an exit option.
I further have functions to display each sub-menu.
In order to create the sub-menus I have used nested while loops and initiated a main menu flag which enable the user to exit from one sub-menu to the main menu from where they can be able to choose another sub-menu.
Each sub-menu has a switch statement with it's corresponding cases that allow the user to operate the program to their liking.
In the main menu I have a switch statement with four different cases which represent the three choices of the sub-menus and an exit option.i.e(bus management, schedules management, bookings management and exit)

In the booking sub-menu; when the user decides to add a booking the program allows them to choose a seat of their desire provided the seat isn't already booked. This is achieved by the program displaying the seating arrangement of the bus selected and uses an 'x' to mark the selected seat and 'O' for all available seats.
The booking is saved in the text file (bookings.txt) and can also be viewed. A ticket is generated for the booking and can also be cancelled if the user wants to.

Once the program is run, it requires one to login with username and a secure password. The struct for user stored variables for username and password. This program uses hardcoded username and password.
The program has a function that hashes the password making it secure. This is made possible by the  conio.h library header file. This header file enables the use of getch()function which reads the characters entered in the password without echoing them on the console.

An authenticate user function ensures login is only possible when the username and the password are correct. Otherwise the function loops the user until the correct details are entered.
I intialized a sample of buses and schedules management which can be viewed under their respective sub-menus.




