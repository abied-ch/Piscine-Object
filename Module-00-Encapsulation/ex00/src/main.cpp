#include <iostream>

#include "Bank.hpp"

int main() {
    Bank bank;
    bank.addLiquidity(999);

    if (bank.createAccount(0, 100)) {
        std::cout << "Account 0 created.\n";
    }

    if (bank.createAccount(1, 100)) {
        std::cout << "Account 1 created.\n";
    }

    std::cout << "Bank state:\n" << bank << "\n";

    bank.giveLoan(0, 200);
    std::cout << "After giving loan to Account 0:\n" << bank << "\n";

    bank.addFundsToAccount(1, 50);
    std::cout << "After adding funds to Account 1:\n" << bank << "\n";

    bank.deleteAccount(0);
    std::cout << "After deleting Account 0:\n" << bank << "\n";

    return 0;
}