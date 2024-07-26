//name: ali kaan sahin
//sec: 002
//id: 22002932
# include <iostream>

using namespace std;

# include "BankingSystem.h"

int main() {
    /**BankingSystem B;
    B.addBranch(1451, " Bilkent ");
    B.addBranch(2435, " Kizilay ");
    B.addBranch(1672, " Bahcelievler ");
    B.addBranch(3216, " Ulus ");
    B.addBranch(2435, " Kizilay ");
    B.deleteBranch(1672);
    B.deleteBranch(1723);
    B.addBranch(9876, " Umitkoy ");
    B.addCustomer(1234, "Ali Ak");
    B.addCustomer(4567, " Aynur Dayanik ");
    B.addCustomer(891234, " Cihan Erkan ");
    B.addCustomer(891234, " Hakan Karaca ");
    B.addCustomer(5678, " Mustafa Gundogan ");
    B.addCustomer(8901, "Can Kara ");
    B.deleteCustomer(5678);
    B.deleteCustomer(1267);

    int account1 = B.addAccount(1451, 4567, 100.00);
    int account2 = B.addAccount(1451, 1234, 200.00);
    int account3 = B.addAccount(3216, 4567, 300.00);
    int account4 = B.addAccount(1451, 4567, 1000.00);
    int account5 = B.addAccount(1672, 8901, 100.00);
    int account6 = B.addAccount(2435, 5678, 100.00);
    int account7 = B.addAccount(3216, 1234, 500.00);
    B.deleteAccount(account2);
    B.deleteAccount(account5);
    B.deleteAccount(account7);
    int account8 = B.addAccount(2435, 891234, 500.00);

    B.showAllAccounts();

    B.showBranch(1451);
    B.showBranch(1672);
    B.showBranch(9876);
    B.showCustomer(1234);
    B.showCustomer(4567);
    B.showCustomer(1212);
    B.deleteBranch(1451);
    B.showCustomer(4567);*/


    /**BankingSystem B;

    B.addBranch(1, "1");
    B.addBranch(2, "2");
    B.addBranch(3, "3");
    B.deleteBranch(1);
    B.deleteBranch(3);
    B.deleteBranch(3);
    B.deleteBranch(2);
    B.deleteBranch(2);
    B.addBranch(1, "1");
    B.addBranch(2, "2");
    B.addBranch(3, "3");
    B.addBranch(1, "1");
    B.addBranch(2, "2");
    B.addBranch(3, "3");*/

    /**BankingSystem B;
    B.addCustomer(1, "1");
    B.addCustomer(2, "2");
    B.addCustomer(3, "3");
    B.addCustomer(3, "3");
    B.addCustomer(4, "3");
    B.deleteCustomer(4);
    B.deleteCustomer(4);
    B.deleteCustomer(1);
    B.deleteCustomer(2);
    B.deleteCustomer(3);
    B.addCustomer(1, "1");
    B.addCustomer(2, "2");
    B.addCustomer(3, "3");
    B.addCustomer(1, "1");
    B.addCustomer(2, "2");
    B.addCustomer(3, "3");
    B.deleteCustomer(3);
    B.deleteCustomer(2);
    B.deleteCustomer(1);
    B.deleteCustomer(3);
    B.deleteCustomer(2);
    B.deleteCustomer(1);*/

    /**BankingSystem B;
    B.addCustomer(1, "1");
    B.addBranch(1, "1");
    int acc1 = B.addAccount(1, 1, 100);
    int acc2 = B.addAccount(1, 1, 100);
    int acc3 = B.addAccount(1, 1, 100);
    int acc = B.addAccount(2,2,100);
    B.deleteAccount(acc);
    B.deleteAccount(1);
    B.deleteAccount(2);
    B.deleteAccount(3);
    B.deleteAccount(1);
    B.deleteAccount(2);
    B.deleteAccount(3);
    int acc4 = B.addAccount(1, 1, 100);
    int acc5 = B.addAccount(1, 1, 100);
    int acc6 = B.addAccount(1, 1, 100);
    B.deleteAccount(6);
    B.deleteAccount(5);
    B.deleteAccount(4);
    int acc7 = B.addAccount(1,2,100);
    int acc8 = B.addAccount(2,1,100);*/
    BankingSystem B;

    B.addBranch(1, "b1");
    B.addBranch(2, "b2");
    B.addBranch(3, "b3");
    B.addBranch(4, "b4");
    B.deleteBranch(1);
    B.deleteBranch(2);
    B.deleteBranch(3);
    B.deleteBranch(4);

    B.addBranch(1, "b1");
    B.addBranch(2, "b2");
    B.addBranch(3, "b3");
    B.addBranch(4, "b4");
    B.deleteBranch(4);
    B.deleteBranch(4);
    B.deleteBranch(3);
    B.deleteBranch(3);
    B.deleteBranch(2);
    B.deleteBranch(2);
    B.deleteBranch(1);
    B.deleteBranch(1);

    B.addBranch(4, "b4");
    B.addBranch(3, "b3");
    B.addBranch(2, "b2");
    B.addBranch(1, "b1");

    B.deleteBranch(2);
    B.deleteBranch(4);
    B.deleteBranch(1);
    B.deleteBranch(3);

    B.addBranch(1, "b1");
    B.addBranch(2, "b2");
    B.addBranch(3, "b3");
    B.addBranch(4, "b4");
    B.addCustomer(1, "c1");
    B.addAccount(1,1,100.0);
    B.addAccount(2,1,100.0);
    B.addAccount(3,1,100.0);
    B.addAccount(4,1,100.0);
    B.addAccount(1,1,200.0);
    B.addAccount(2,1,200.0);
    B.addAccount(3,1,200.0);
    B.addAccount(4,1,200.0);
    B.showAllAccounts();
    B.deleteBranch(1);
    B.deleteBranch(2);
    B.deleteBranch(3);
    B.deleteBranch(4);
    B.showAllAccounts();

    B.addBranch(1, "b1");
    B.addBranch(2, "b2");
    B.addBranch(3, "b3");
    B.addBranch(4, "b4");
    B.showAllAccounts();
    B.addCustomer(1, "c1");
    B.addAccount(1,1,100.0);
    B.addAccount(2,1,100.0);
    B.addAccount(3,1,100.0);
    B.addAccount(4,1,100.0);
    B.addAccount(1,1,200.0);
    B.addAccount(2,1,200.0);
    B.addAccount(3,1,200.0);
    B.addAccount(4,1,200.0);
    B.showAllAccounts();
    B.deleteCustomer(1);
    B.showAllAccounts();
    B.deleteBranch(1);
    B.deleteBranch(2);
    B.deleteBranch(3);
    B.deleteBranch(4);

    /**BankingSystem B;
    B.showAllAccounts();
    B.showCustomer(1);
    B.showBranch(1);
    B.addCustomer(1, "c1");
    B.showCustomer(1);
    B.addBranch(10, "b10");
    B.showBranch(10);
    B.addBranch(11, "b11");
    B.addCustomer(2, "c2");
    int acc1 = B.addAccount(11, 1, 100);
    int acc2 = B.addAccount(11, 1, 200);
    int acc3 = B.addAccount(11, 2, 300);
    int acc4 = B.addAccount(11, 2, 400);
    int acc5 = B.addAccount(10, 1, 500);
    int acc6 = B.addAccount(10, 1, 600);
    int acc7 = B.addAccount(10, 2, 700);
    int acc8 = B.addAccount(10, 2, 800);
    B.showAllAccounts();
    B.showBranch(10);
    B.showBranch(11);
    B.showCustomer(1);
    B.showCustomer(2);
    B.deleteBranch(11);
    B.showCustomer(1);
    B.showCustomer(2);
    B.showAllAccounts();*/
    return 0;
}
