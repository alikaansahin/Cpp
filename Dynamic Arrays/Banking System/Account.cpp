//name: ali kaan sahin
//sec: 002
//id: 22002932

#include "Account.h"
#include <iostream>

Account::Account() {
    setAccountId(0);
    setBalance(0);
    setBranchId(0);
    setCustomerId(0);

}

Account::Account(const int branchId, const int customerId, const double balance) {

    setBalance(balance);
    setBranchId(branchId);
    setCustomerId(customerId);

}

Account::~Account() {

}

void Account::setAccountId(int accountId) {
    this->accountId = accountId;
}

void Account::setBranchId(int branchId) {
    this->branchId = branchId;
}

void Account::setCustomerId(int customerId) {
    this->customerId = customerId;
}

void Account::setBalance(int balance) {
    this->balance = balance;
}

int Account::getAccountId() {
    return accountId;
}

int Account::getBranchId() {
    return branchId;
}

int Account::getCustomerId() {
    return customerId;
}

double Account::getBalance() {
    return balance;
}
