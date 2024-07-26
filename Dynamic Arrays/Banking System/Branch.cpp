//name: ali kaan sahin
//sec: 002
//id: 22002932

#include "Branch.h"
#include <iostream>

using namespace std;

Branch::Branch() {

    this->branchId = 0;
    this->name = "";
}

Branch::Branch(const int branchId, const string name) {

    this->branchId = branchId;
    this->name = name;
}

Branch::~Branch() {

}

void Branch::setBranchId(int branchId) {
    this->branchId = branchId;
}

void Branch::setName(string name) {
    this->name = name;
}

int Branch::getBranchId() {
    return branchId;
}

string Branch::getName() {
    return name;
}
