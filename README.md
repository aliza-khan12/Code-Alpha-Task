# CGPA Calculator
Welcome to my repository for the Code Alpha internship! This project is a simple console-based CGPA Calculator written in C++.
# About the Project
This program helps users calculate their Grade Point Average (GPA) or Cumulative Grade Point Average (CGPA) based on the number of courses, grades received, and their respective credit hours.
# 🛠️Features
# Dynamic Input:
Asks the user for the total number of courses taken.

Grade & Credit Mapping:Takes individual course grades (e.g., 4.0, 3.3, 3.0) and credit hours as input.

Automated Calculation:Computes the final GPA/CGPA efficiently using arrays and loops.
💻 Code Structure
# Language: C++
File Included: CGPA calculator.cpp
# ⚙️ How to Run
Make sure you have a C++ compiler installed (like GCC or MinGW).
Clone this repository or download the CGPA calculator.cpp file.
Open your terminal or command prompt and run the following commands:
Bash
g++ "CGPA calculator.cpp" -o cgpa_calc
./cgpa_calc

# Banking Management System

A simple, console-based Banking Management System developed in C++ as part of the Code Alpha internship task. This application demonstrates Object-Oriented Programming (OOP) principles by managing customer accounts, handling deposits and withdrawals, processing fund transfers, and tracking transaction history.

# Features

Customer Account Creation: Automatically generates a unique customer ID and a sequential account number (starting from 1001) for every new user.
Deposit System :

Allows users to deposit positive amounts into their specified bank accounts with instant balance updates.
Withdrawal System :

Validates withdrawal requests to ensure sufficient funds and positive amounts before updating the account balance.
Fund Transfers : Facilitates secure money transfers between two different accounts, automatically logging transfer-in and transfer-out transactions.
Transaction History Tracking :

Keeps a detailed ledger of recent transactions (deposits, withdrawals, and transfers) with timestamps or balance states.
Interactive Console Menu: Provides an easy-to-navigate user interface to perform all banking operations seamlessly.

---

## 📂 Code Architecture & OOP Design

The project is structured around four primary classes:

1. Transaction :
2.
3.   Represents individual financial events, tracking the type of transaction (Deposit, Withdraw, Transfer-In, Transfer-Out), the amount, and the resulting balance[cite: 1].
4. Account :
5.
6.   Manages individual account balances, handles deposit/withdrawal logic, and maintains a vector-based history of transactions[cite: 1].
7. Customer :
8.
9.   Links personal customer details (ID and name) with their corresponding Account object[cite: 1].
10. Bank:
11.
12. Acts as the controller/manager class handling the collection of customers, search functionality, and overall banking operations (creation, deposits, withdrawals, and transfers)[cite: 1].

---

## Getting Started

### Prerequisites
You need a C++ compiler that supports 
C++11 or higher (e.g., GCC, Clang, MSVC).

Banking System 
1. Create Customer
2. Deposit
3. Withdraw
4. Transfer Funds
5. View Account Info
6. Exit
7. 
Enter choice:


Create Customer: Enter the account holder's name to generate an account number.

Deposit / Withdraw: Input the target account number and the transaction amount.

Transfer Funds: Specify the sender's account, receiver's account, and the transfer amount.

View Account Info: Display current customer details, overall balance, and recent transaction logs.

👤 Author
Developed as part of the Code Alpha C++ Programming Internship.
