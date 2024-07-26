//name: ali kaan sahin
//sec: 002
//id: 22002932

#ifndef HOMEWORK1_BRANCH_H
#define HOMEWORK1_BRANCH_H
#include <iostream>
#include "Customer.h"
using namespace std;

class Branch{
public:
    Branch();
    Branch(const int branchId, const string name);
    ~Branch();
    void setBranchId(int branchId);
    void setName(string name);
    int getBranchId();
    string getName();

private:
    int branchId;
    string name;

};
#endif //HOMEWORK1_BRANCH_H
