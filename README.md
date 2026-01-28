# Student Management System (C)

## Description
A simple terminal-based student management system written in C.
The program allows the user to add, view, and update a single student's data.

This project was built to practice:
- control flow
- functions
- Strutcts
- Enums
- input validation
- basic program structure in C

## Project structure
student-management-c/
├── src/
│ └── main.c
├── .gitignore
└── README.md

## .gitignore
Ignore compiled artifacts like .exe files

## Features
- Add student (name, age and gpa)
- Display student data
- Update name, age, gpa or all
- Input validation for menu options, name, age and gpa

## How to Run
1. Compile the program:
gcc src/main.c -o student

2. Run the executable:
./student

- Run on Windows:
student.exe

## What I Learned
- How to structure a menu-driven program
- How to validate user input safely using strings, strtol and strtof
- Why code duplication is a problem
- How functions, enums and typedef improve readability and maintenance

## Future Improvements
- Support multiple students
- Store data in files

## Contributing
Feel free to open issues or PRs if you want to help improve this project 😊

