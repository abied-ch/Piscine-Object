#include "Bank.hpp"

Bank::Bank() : _liquidity(0) {
}

Bank::~Bank() {
    std::map<int, Account *>::iterator account = _clientAccounts.begin();
    for (; account != _clientAccounts.end(); account++) {
        delete account->second;
    }
}

const int &Bank::getLiquidity() const {
    return _liquidity;
}

void Bank::addLiquidity(int amount) {
    _liquidity += amount;
}

bool Bank::isUniqueId(int id) const {
    return _clientAccounts.find(id) == _clientAccounts.end();
}

bool Bank::createAccount(int id, int initialValue) {
    if (isUniqueId(id) and initialValue <= _liquidity) {
        _clientAccounts[id] = new Account(id, initialValue);
        _liquidity -= initialValue;
        return true;
    }
    return false;
}

bool Bank::deleteAccount(int id) {
    std::map<int, Account *>::iterator account = _clientAccounts.begin();
    for (; account != _clientAccounts.end(); account++) {
        if ((account->second)->getId() == id) {
            _liquidity += account->second->getValue();
            delete account->second;
            _clientAccounts.erase(account);
            return true;
        }
    }
    return false;
}

bool Bank::addFundsToAccount(int id, int amount) {
    if (amount <= _liquidity) {
        std::map<int, Account *>::iterator account = _clientAccounts.begin();
        for (; account != _clientAccounts.end(); account++) {
            if (account->second->getId() == id) {
                int depositAmount = amount * 0.95;
                int bankFee = amount * 0.05;
                account->second->_value += depositAmount;
                _liquidity -= (depositAmount + bankFee);
                return true;
            }
        }
    }
    return false;
}

bool Bank::giveLoan(int id, int amount) {
    if (amount <= _liquidity) {
        std::map<int, Account *>::iterator account = _clientAccounts.begin();
        for (; account != _clientAccounts.end(); account++) {
            if (account->second->getId() == id) {
                account->second->_value += amount;
                _liquidity -= amount;
                return true;
            }
        }
    }
    return false;
}
