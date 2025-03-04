# Old Age Allowance Management System

This project is an **Object-Oriented Programming (OOP) final project** designed to determine the eligibility of applicants for **Old Age Allowance** in Bangladesh. The program reads applicant data from an input file, processes their eligibility based on age and gender, and categorizes them accordingly.

## Features
- **Applicant Management:** Stores and processes applicant information.
- **Eligibility Checking:** Determines if an applicant qualifies for the allowance based on age and gender.
- **Profile Search:** Allows users to search for an applicant's details.
- **List Generation:** Displays a list of eligible and non-eligible applicants.
- **File Handling:** Reads input from a text file.

## OOP Concepts Used
This project implements several key OOP principles:

### 1. **Abstraction**
   - Implemented through the **`dummy`** abstract class, which defines a pure virtual function `getName()`.
   - Forces derived classes to implement the `getName()` method, ensuring a standard interface.

### 2. **Inheritance**
   - The **`applicant`** class serves as a base class.
   - Two derived classes, **`eligible`** and **`non_eligible`**, inherit from `applicant` to classify individuals.

### 3. **Polymorphism**
   - The `getName()` function is a **pure virtual function** in `dummy`, overridden in the `applicant` class and its derived classes.
   - Achieved through **function overriding**.

### 4. **Encapsulation**
   - The `applicant` class encapsulates data members such as `name`, `dateOfBirth`, `NID_no`, `gender`, `fatherName`, and `motherName`.
   - Getter functions provide controlled access to these private/protected attributes.

### 5. **Templates**
   - The function **`greaterThan<T>`** is implemented as a **template function**, allowing it to compare values of any data type.

### 6. **Operator Overloading**
   - The `<<` operator is **overloaded** in both `eligible` and `non_eligible` classes to neatly display applicant information.

### 7. **Standard Template Library (STL)**
   - **`vector`** is used to store lists of eligible and non-eligible applicants dynamically.

## How It Works
1. The program reads applicant data from `input.txt`, containing:
   - Name, Date of Birth, NID number, Gender, Father's Name, Mother's Name.
2. The program checks if the applicant meets the **Bangladeshi government’s age criteria** for old-age allowance:
   - **Male:** Must be **65 years or older**.
   - **Female:** Must be **62 years or older**.
3. The program classifies applicants into:
   - **Eligible (stored in `vector<eligible>`).**
   - **Non-eligible (stored in `vector<non_eligible>`).**
4. Users can:
   - View a list of eligible/non-eligible applicants.
   - Search for an applicant’s details.
## Screenshots

### Main Menu
![Main Menu](/project_screenshots/main_menu.png)

### Eligible Applicants List
![Eligible Applicants List](/project_screenshots/eligible_list.png)

### Non-Eligible Applicants List
![Non-Eligible Applicants List](/project_screenshots/non_eligible_list.png)

### Applicant Details : Searching if a particular user is eligible or not
![Applicant Details](/project_screenshots/profile_view.png)


## Usage
1. Compile the program using a C++ compiler (g++ or MSVC):
   ```sh
   g++ -o allowance_management allowance_management.cpp
