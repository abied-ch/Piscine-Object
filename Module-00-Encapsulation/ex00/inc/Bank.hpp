#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>

class Bank {
public:
    struct Account {
    private:
        int _id, _value;

    public:
        Account(int id, int value) : _id(id), _value(value) {}

        const int& getId() const { return _id; }
        const int& getValue() const { return _value; }

        friend std::ostream& operator<<(std::ostream& os, const Account& account) {
            os << "[" << account._id << "] - [" << account._value << "]";
            return os;
        }

        friend class Bank;
    };

private:
    int _liquidity;
    std::map<int, Account*> _clientAccounts;

    bool isUniqueId(int id) const;

public:
    Bank();

    const int& getLiquidity() const;
    void addLiquidity(int amount);

    bool createAccount(int id, int initialValue);
    bool deleteAccount(int id);
    bool addFundsToAccount(int id, int amount);
    bool giveLoan(int id, int amount);

    Account& operator[](int id) {
        std::map<int, Account*>::iterator account = _clientAccounts.find(id);
        if (account != _clientAccounts.end()) {
            return *account->second;
        }
        throw std::runtime_error("Account not found.");
    }

    friend std::ostream& operator<<(std::ostream& os, const Bank& bank) {
        os << "Bank information:\n";
        os << "Liquidity: " << bank._liquidity << "\n";
        std::map<int, Account*>::const_iterator account = bank._clientAccounts.begin();
        for (; account != bank._clientAccounts.end(); ++account) {
            os << *(account->second) << "\n";
        }
        return os;
    }

    ~Bank();
};

#endif  // BANK_HPP