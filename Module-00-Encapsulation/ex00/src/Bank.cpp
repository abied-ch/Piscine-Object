#include "Bank.hpp"

bool Bank::isUniqueId(int id) const {
    accountIterator account = _clientAccounts.begin();
    for (; account != _clientAccounts.end(); account++) {
        if (account->getId() == id) {
            return false;
        }
    }
    return true;
}