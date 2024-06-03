#include "Account.hpp"

Account::Account(int id, int value) : _id(id), _value(value) {
}

const int& Account::getId() const {
    return _id;
}

const int& Account::getValue() const {
    return _value;
}

void Account::addValue(int amount) {
    _value += amount;
}

void Account::subtractValue(int amount) {
    _value -= amount;
}