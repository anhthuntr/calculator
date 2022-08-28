# Project 2
# brief overview 
This is our group's second and final project. It is written in C++, and its composed of three header files, 7 "function" .cpp files, a main file, and a makefile. 
# project purpose and usage 
The purpose of the project is to implement techniques we have covered in lecture to create a calculator-like program.
This specifically includes the usage of hash tables, regular expression, as well as queues, to decode and express user input.
The flow of the program is as following:
- Compile, and run
- Sends you into the main file where project header appears
- Enter "create", "delete", or "print" followed by an alphanumeric Key exact per capitalization (ex: "create A1").
- Or enter n Key followed by ":=" and an expression to assign to a Key (ex: A1:=22+3)
- Each of these words will be verified in the RegEx.cpp functionalities to verify format before continuing into their respective functions
- "create", and "delete", will both send the result of the decode function into otherHash.cpp's "Match", function,  and then back into their .cpp files(insertHash.cpp, and deleteHash.cpp, respectively)
- "print" will send the result of the decode function into  otherHash.cpp, and then into the searchHash.cpp functions.
- The "expression" conditional will start in the main-file. It sends the result of the decode function into otherHash.cpp's "Match" function, then into otherHash.cpp's getValue function. From there it sends the decoded input to updateHash.cpp functions, where it is inputted to a queue.
- The user can continue to do this until they enter quit.

# How to use the makefile
When in the terminal for the folder type "make" to compile the program into Calculator.exe.
To run the program type ./Calculator.exe

-group 7
