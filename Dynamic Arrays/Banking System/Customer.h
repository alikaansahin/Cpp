//name: ali kaan sahin
//sec: 002
//id: 22002932

#ifndef HOMEWORK1_CUSTOMER_H
#define HOMEWORK1_CUSTOMER_H

#include <iostream>
#include "Account.h"

using namespace std;

class Customer {
public:

    Customer();
    Customer(const int customerId , const string name);
    ~Customer();
    void setCustomerId(int customerId);
    int  getCustomerId();
    void setName(string name);
    string  getName();

private:
    int customerId;
    string name;

};

#endif //HOMEWORK1_CUSTOMER_H
