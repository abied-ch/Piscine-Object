#ifndef BANK_HPP
#define BANK_HPP

#include <vector>

#include "Account.hpp"

class Bank {
private:
    int _liquidity;
    std::vector<Account*> _clientAccounts;

    bool isUniqueId(int id) const;

public:
    Bank();

    int getLiquidity() const;
    void addLiquidity(int amount);

    bool createAccount(int id, int initialValue);
    bool deleteAccount(int id);
    bool addFundsToAccount(int id, int amount);
    bool giveLoan(int id, int amount);

    friend std::ostream& operator<<(std::ostream& os, const Bank& bank) {
        os << "Bank information:\n";
        os << "Liquidity: " << bank._liquidity << "\n";
        std::vector<Account*>::const_iterator account = bank._clientAccounts.begin();
        for (; account != bank._clientAccounts.end(); account++) {
            os << **account << "\n";
        }
        return os;
    }

    ~Bank();
};

#endif  // BANK_HPP