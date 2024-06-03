#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
private:
    int _id;
    int _value;

public:
    Account(int id, int value);
    int getId() const;
    int getValue() const;
    void addValue(int amount);
    void subtractValue(int amount);

    friend std::ostream& operator<<(std::ostream& os, const Account& account) {
        os << "[" << account._id << "] - [" << account._value << "]";
        return os;
    }
};

#endif  // ACCOUNT_HPP