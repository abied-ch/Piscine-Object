#include "Bank.hpp"

Bank::Bank() : _liquidity(0) {
}

Bank::~Bank() {
    std::vector<Account *>::iterator account = _clientAccounts.begin();
    for (; account != _clientAccounts.end(); account++) {
        delete *account;
    }
}

int Bank::getLiquidity() const {
    return _liquidity;
}

void Bank::addLiquidity(int amount) {
    _liquidity += amount;
}

bool Bank::isUniqueId(int id) const {
    std::vector<Account *>::const_iterator account = _clientAccounts.begin();
    for (; account != _clientAccounts.end(); account++) {
        if ((*account)->getId() == id) {
            return false;
        }
    }
    return true;
}

bool Bank::createAccount(int id, int initialValue) {
    if (isUniqueId(id) and initialValue <= _liquidity) {
        _clientAccounts.push_back(new Account(id, initialValue));
        _liquidity -= initialValue;
        return true;
    }
    return false;
}

bool Bank::deleteAccount(int id) {
    std::vector<Account *>::iterator account = _clientAccounts.begin();
    for (; account != _clientAccounts.end(); account++) {
        if ((*account)->getId() == id) {
            _liquidity += (*account)->getValue();
            delete *account;
            _clientAccounts.erase(account);
            return true;
        }
    }
    return false;
}

bool Bank::addFundsToAccount(int id, int amount) {
    if (amount <= _liquidity) {
        std::vector<Account *>::iterator account = _clientAccounts.begin();
        for (; account != _clientAccounts.end(); account++) {
            if ((*account)->getId() == id) {
                int depositAmount = amount * 0.95;
                int bankFee = amount * 0.05;
                (*account)->addValue(depositAmount);
                _liquidity -= (depositAmount + bankFee);
                return true;
            }
        }
    }
    return false;
}

bool Bank::giveLoan(int id, int amount) {
    if (amount <= _liquidity) {
        std::vector<Account *>::iterator account = _clientAccounts.begin();
        for (; account != _clientAccounts.end(); account++) {
            if ((*account)->getId() == id) {
                (*account)->addValue(amount);
                _liquidity -= amount;
                return true;
            }
        }
    }
    return false;
}
