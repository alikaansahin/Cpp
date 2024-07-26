//name: ali kaan sahin
//sec: 002
//id: 22002932

#ifndef HOMEWORK1_ACCOUNT_H
#define HOMEWORK1_ACCOUNT_H
class Account{
public:

    Account();
    Account(const int branchId, const int customerId, const double balance);
    ~Account();
    void setAccountId(int accountId);
    void setBranchId(int branchId);
    void setCustomerId(int customerId);
    void setBalance(int balance);
    int getAccountId();
    int getBranchId();
    int getCustomerId();
    double getBalance();
private:
    int accountId;
    int branchId;
    int customerId;
    double balance;
};
#endif //HOMEWORK1_ACCOUNT_H
