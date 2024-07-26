//name: ali kaan sahin
//sec: 002
//id: 22002932

#include "Customer.h"

Customer::Customer(){
    setCustomerId(0);
    setName("");
}
Customer::Customer(const int customerId, const string name){

    setCustomerId(customerId);
    setName(name);
}
Customer::~Customer(){

}

void Customer::setCustomerId(int customerId) {
    this->customerId = customerId;
}

void Customer::setName(string name) {
    this->name = name;
}

int Customer::getCustomerId() {
    return customerId;
}

string Customer::getName() {
    return name;
}

