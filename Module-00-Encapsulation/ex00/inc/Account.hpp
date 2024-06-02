#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
private:
    int _id;
    int _value;

public:
    Account(int id, int value) : _id(id), _value(value) {}
    int getId() const { return _id; }
    int getValue() const { return _value; }
    void addValue(int amount) { _value += amount; }
    void subtractValue(int amount) { _value -= amount; }
};

#endif  // ACCOUNT_HPP