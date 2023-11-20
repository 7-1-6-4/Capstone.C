This Capstone.C project is a bus management stystem/program written in C programming language. When the program is run on any C compiler i.e code blocks,falcon c++ or Vs code
with MingW compiler installed and Code Runner extension installed, then the user should be able to view and operate on all possible manipulations in the project.

The program contains structures(struct) for user, bus, schedules and bookings and some void functions. Some of the void functions include: Function to add bus, function to add 
booking and function to view all schedules.

The program also entails the use of files to store persistent data. In this program there is a text file to store bookings. 
Once the program is run, it requires one to login with username and a secure password. The struct for user stored variables for username and password.
The program has a function that hashes the password making it secure.
An authenticate user function ensures login is only possible when the username and the password are correct. Otherwise the function loops until the correct details are entered.
