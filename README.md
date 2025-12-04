# Banking Management System - BSE 3B DSA Lab Project
   

**Course:** Data Structures and Algorithms (DSA)  
**University:** Bahria University BSE-3B  

## General Information

This project is a **Banking Management System** developed as part of the DSA course project. The system is implemented in C++ and makes extensive use of **Data Structures**, **STLs**, and efficient algorithms to simulate a real-life banking solution.

### Objective

The project assumes ownership of a bank operating **10 ATMs** in a city. The system is designed to handle **banking operations** and **ATM management**, ensuring seamless functionality and user interaction. It incorporates persistent data storage, enabling information to be saved across executions.

---

## Table of Contents

1. [General Information](#general-information)  
2. [Features](#features)  
   - [Banking Mode](#banking-mode)  
   - [ATM Mode](#atm-mode)  
3. [Technologies Used](#technologies-used)  
4. [Setup and Execution](#setup-and-execution)  

---

## Features

### Modes of Operation

The system operates in **two modes**, which can be toggled using the command **`Z`**:
1. **BANKING Mode**  
2. **ATM Mode**

---

### Banking Mode

| Command | Description                    |
| ------- | ------------------------------ |
| S       | Open bank                      |
| O       | Open an account                |
| B       | Balance enquiry                |
| W       | Withdrawal                     |
| D       | Deposit                        |
| C       | Close account                  |
| A       | Activate ATM                   |
| U       | Unlock ATM                     |
| P       | Print all accounts             |
| I       | Apply interest to all accounts |
| E       | Exit and close all accounts    |

---

### ATM Mode

| Command | Description     |
| ------- | --------------- |
| X       | PIN change      |
| F       | Fund transfer   |
| B       | Balance enquiry |
| W       | Withdrawal      |
| M       | Mini statement  |

**Note:** Data persistence ensures all banking and ATM records are saved after each session, enabling seamless restoration upon the next execution.

---

## Technologies Used

- **Programming Language:** C++  
- **Compiler:** GNU Make (or your preferred compiler)  
- **Libraries:** Standard Template Library (STL)  

---

## Setup and Execution

To run the Banking Management System, follow these steps:

1. **Clone the Repository:**  
   ```bash
   git clone <repository-url>
   cd BankingManagementSystem
