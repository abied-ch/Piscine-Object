#ifndef BANK_HPP
#define BANK_HPP

#include <vector>

#include "Account.hpp"

class Account;

class Bank {
   private:
    int liquidity;
    std::vector<Account *> _clientAccounts;
    typedef std::vector<Account *>::const_iterator accountIterator;

    bool isUniqueId(int id) const;
};

#endif