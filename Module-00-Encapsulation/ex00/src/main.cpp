#include <iostream>

#include "Bank.hpp"

int main() {
    try {
        Bank bank;
        bank.addLiquidity(999);

        if (bank.createAccount(0, 100)) {
            std::cout << "Account 0 created.\n";
        } else {
            throw std::runtime_error("Failed to create Account 0");
        }

        if (bank.createAccount(1, 100)) {
            std::cout << "Account 1 created.\n";
        } else {
            throw std::runtime_error("Failed to create Account 1");
        }

        std::cout << "Bank state:\n" << bank << "\n";

        if (bank.giveLoan(0, 200)) {
            std::cout << "Loan given to Account 0\n";
        } else {
            throw std::runtime_error("Failed to give loan to Account 0");
        }
        std::cout << "After giving loan to Account 0:\n" << bank << "\n";

        if (bank.addFundsToAccount(1, 50)) {
            std::cout << "Funds added to Account 1\n";
        } else {
            throw std::runtime_error("Failed to add funds to Account 1");
        }
        std::cout << "After adding funds to Account 1:\n" << bank << "\n";

        std::cout << "Accessing Account 0: " << bank[0] << "\n";
        std::cout << "Accessing Account 1: " << bank[1] << "\n";

        if (bank.deleteAccount(0)) {
            std::cout << "Account 0 deleted\n";
        } else {
            throw std::runtime_error("Failed to delete Account 0");
        }
        std::cout << "After deleting Account 0:\n" << bank << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
