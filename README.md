# Mini-Project-1
Mini Project 1 is Persistent Library Management System (PLMS)
A C++ based Persistent Library Management System (PLMS) designed to perform CRUD operations with automatic data persistence using file handling.
------------------------------------

Persistent Library Management System

Mini Project 1 (PLMS)
1. Abstract

The Persistent Library Management System is a C++ application that digitalizes book inventory tracking. It allows users to add, view, and delete records while ensuring all data is saved permanently to a text file using C++ fstream.
2. Problem Statement

Traditional manual record-keeping is inefficient and vulnerable to loss. This project aims to solve the lack of persistence in basic digital programs by providing a permanent data ledger.
3. Objectives

  Develop a functional Command Line Interface (CLI) for library tasks.

  Implement permanent storage via File I/O.

  Utilize Object-Oriented Programming (OOP) for record management.

4. Methodology

The project follows a four-step lifecycle:

  Load: Reads library_data.txt on startup.

  Interact: User selects actions through a menu system.

  Process: Data is managed in RAM using std::vector.

  Save: Data is written back to the file upon program exit.

5. Tools & Technologies Used

    Language: C++.

    Compiler: g++ (MinGW).

    Persistence: Flat-file system (fstream).

6. Timeline (2 Weeks)

    Week 1: Analysis and Core Development (Add/View features).

    Week 2: File Persistence (Save/Load) and Documentation.

7. Expected Outcome

A standalone executable capable of managing thousands of book records with zero data loss between sessions.
