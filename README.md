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

### 3. Function Overloading
The ActiveFile class contains overloaded search() functions.
{
    // ...
};
