//name: ali kaan sahin
//sec: 002
//id: 22002932

#include <iostream>
#include "Branch.h"
#include "Customer.h"
#include "Account.h"
#ifndef HOMEWORK1_BANKINGSYSTEM_H
#define HOMEWORK1_BANKINGSYSTEM_H

class BankingSystem {
public :
    BankingSystem ();
    ~ BankingSystem ();
    void addBranch ( const int branchId , const string branchName );
    void deleteBranch ( const int branchId );
    void addCustomer ( const int customerId , const string customerName );
    void deleteCustomer ( const int customerId );
    int addAccount ( const int branchId , const int customerId , const double amount );
    void deleteAccount ( const int accountId );
    void showAllAccounts ();
    void showBranch ( const int branchId );
    void showCustomer ( const int customerId );
    void showBranches();
    void showCustomers();

    int accountCount;
    int customerCount;
    int branchCount;
    int accountId;
    Branch* branches;
    Customer* customers;
    Account* accounts;

};

#endif //HOMEWORK1_BANKINGSYSTEM_H
