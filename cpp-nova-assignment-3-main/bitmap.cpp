#include "bitmap.h"
#include <iostream>
#include <cstring> 
using namespace std;

Account::Account() : accno(0), balance(0.0) {
    strcpy(name, "Unknown");
}

Account::Account(int accNum, const char* accName, double accBalance)
    : accno(accNum), balance(accBalance) {
    strcpy(name, accName);
}

void Account::accept() {
    cout << "Enter Account Number: ";
    cin >> accno;
    cin.ignore(); 
    cout << "Enter Name: ";
    cin.getline(name, 20);
    cout << "Enter Balance: ";
    cin >> balance;
}

void Account::display() {
    cout << "Account Number: " << accno << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: $" << balance << endl;
}

void Account::deposite(int amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

void Account::withdraw(int amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawn: $" << amount << endl;
    } else {
        cout << "Invalid or insufficient balance for withdrawal." << endl;
    }
}

int Account::getAccno() {
    return accno;
}

void Account::setAccno(int accNum) {
    accno = accNum;
}

char* Account::getName() {
    return name;
}

void Account::setName(const char* accName) {
    strcpy(name, accName);
}

double Account::getBalance() {
    return balance;
}

void Account::setBalance(double accBalance) {
    balance = accBalance;
}

bool Account::searchAccountById(Account* accounts, int numAccounts, int searchAccNum) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].getAccno() == searchAccNum) {
            accounts[i].display(); 
            return true;
        }
    }
    return false; 
}

double Account::getHighestBalance(Account* accounts, int numAccounts) {
    if (numAccounts <= 0) return 0.0;

    double highest = accounts[0].getBalance();
    for (int i = 1; i < numAccounts; ++i) {
        if (accounts[i].getBalance() > highest) {
            highest = accounts[i].getBalance();
        }
    }
    return highest;
}

double Account::getLowestBalance(Account* accounts, int numAccounts) {
    if (numAccounts <= 0) return 0.0;

    double lowest = accounts[0].getBalance();
    for (int i = 1; i < numAccounts; ++i) {
        if (accounts[i].getBalance() < lowest) {
            lowest = accounts[i].getBalance();
        }
    }
    return lowest;
}