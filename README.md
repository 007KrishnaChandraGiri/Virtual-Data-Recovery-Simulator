# Virtual Data Recovery Simulator

## Project Overview

The **Virtual Data Recovery Simulator** is a C++ Object-Oriented Programming project that simulates basic file management and data recovery operations on a virtual disk.

The system allows users to create, search, delete, and recover files within a simulated 20-block virtual disk. It demonstrates how deleted files can be recovered by reallocating available disk space.

This project is developed as an academic project for the **Bachelor of Information Technology (B.I.T.)** program.

---

## Objectives

The main objectives of this project are:

- To simulate a virtual disk environment.
- To implement file creation and allocation.
- To search for existing files.
- To delete files and release their allocated space.
- To recover deleted files.
- To display available disk space.
- To demonstrate Object-Oriented Programming concepts in C++.
- To implement basic file handling for data persistence.

---

## Features

The simulator provides the following features:

1. **Create File**
   - Creates a file with a specified name and size.
   - Only `.txt` file names are accepted.
   - Checks available disk space before allocation.

2. **Search File**
   - Searches for an existing file using its file name.
   - Displays the file name and file size when found.

3. **Delete File**
   - Deletes an existing file.
   - Releases the disk blocks occupied by the file.

4. **Recover File**
   - Recovers a deleted file.
   - Reallocates available disk blocks to the deleted file.
   - Checks whether sufficient free space is available.

5. **Display Files**
   - Displays the currently active files and their sizes.
   - Shows the remaining free space.

6. **Check Free Space**
   - Displays total disk capacity.
   - Displays used space.
   - Displays available free space.

7. **Data Persistence**
   - Active file information is stored in `simulator.txt`.
   - Saved data can be loaded when the program starts.

---

## Virtual Disk

The simulator uses a virtual disk containing **20 blocks**.

Each block can either be:

- Empty
- Occupied by a file

When a file is created, the required number of free blocks are allocated to that file.

When a file is deleted, its occupied blocks are released and become available again.

---

## Object-Oriented Programming Concepts

The project demonstrates several important C++ OOP concepts.

### 1. Classes and Objects

The project uses classes such as:

- `Data`
- `File`
- `ActiveFile`
- `DeletedFile`

### 2. Inheritance

`ActiveFile` and `DeletedFile` inherit from the base `File` class.

```cpp
class ActiveFile : public File
{
    // ...
};
class DeletedFile : public File

    // ...
};
```
### 3. Function Overloading
The ActiveFile class contains overloaded search() functions.
```
void search(string name);
void search(string name, int size);
```
### 4. Operator Overloading
The equality operator == is overloaded in the File class to compare files.
```
bool operator==(const File &other);
```
### 5. Constructors
The Data class uses a constructor to initialize the virtual disk and free space.

### 6. Encapsulation
Data and operations related to files and disk management are organized within classes.

### 7. File Handling
The project uses C++ file handling to save and load active file information using:
- ofstream
- ifstream
- 
  Main Menu
The simulator provides the following main menu:
1. Create File
2. Search File
3. Delete File
4. Recover File
5. Display Files
6. Check Free Space
7. Exit

   Technologies Used
- Programming Language: C++
- Programming Paradigm: Object-Oriented Programming
- Compiler: MinGW / GCC or compatible C++ compiler
- IDE: Visual Studio Code / Dev-C++
- Operating System: Windows
- Libraries Used:
  - <iostream>
  - <string>
  - <fstream>
  - <conio.h>
  - <windows.h>
    
How to Run
Step 1: Clone or Download the Repository
Download the project from this GitHub repository.
Step 2: Open the Project
Open the project folder in Visual Studio Code or another C++ IDE.
Step 3: Compile the Program
Using a C++ compiler:

Project Structure
```
Virtual-Data-Recovery-Simulator/
│
├── Virtual_Data_Recovery_Simulator.cpp
├── README.md
└── simulator.txt
```

File Description

| File | Description |
|------|-------------|
| `Virtual_Data_Recovery_Simulator.cpp` | Main C++ source code |
| `README.md` | Project documentation |
| `simulator.txt` | Stores active file information |
Example
Suppose the user creates:
```
File Name: report.txt
File Size: 5
```
The simulator allocates 5 blocks to report.txt.
If the file is deleted, those 5 blocks become free.
The user can then use Recover File to recover report.txt if sufficient free space is available.

Limitations
- The simulator uses a fixed virtual disk size of 20 blocks.
- It is a simulation and does not recover real deleted computer files.
- Only .txt file names are accepted.
- Deleted file information is not permanently stored after program termination.
- The simulator is designed for educational purposes.
  
Future Improvements
Possible future improvements include:
- Increasing virtual disk capacity.
- Supporting different file types.
- Implementing more advanced file allocation methods.
- Improving recovery mechanisms.
- Adding a graphical user interface.
- Maintaining deleted-file information between program sessions.
- Adding more detailed disk visualization.
  
Testing
The following operations were tested during development:
- Creating files with valid names and sizes.
- Rejecting invalid file names.
- Rejecting invalid or non-positive file sizes.
- Preventing allocation when sufficient disk space is unavailable.
- Searching for existing and non-existing files.
- Deleting existing files.
- Recovering deleted files.
- Checking available disk space.
- Saving and loading active file information.
  
Project Information
Project Title: Virtual Data Recovery Simulator
Program: Bachelor of Information Technology (B.I.T.)
University: Purbanchal University
Project Type: C++ Object-Oriented Programming Project

Disclaimer
This project is an educational simulation of file allocation, deletion, and recovery. It does not perform actual recovery of deleted files from physical storage devices.

Author:
-Samrat Timilsina
-Krishna Chandra Giri
-Dipesh Dhungana
