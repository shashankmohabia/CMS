//
// Created by Shashank Mohabia on 2/7/2018.
//

#include <algorithm>
#include "Payment.h"

int Payment::get_payment_amount(string type) {
    return find_if(_registration_type_list.begin(), _registration_type_list.end(),
                   [&](const pair<string, int> &element) { return element.first == type; })->second;
}

void Payment::add_registration_type(string type, int amount) {
    _registration_type_list.emplace_back(type, amount);
}

vector<pair<string, int>> &Payment::get_registration_type_list() {
    return _registration_type_list;
}

void Payment::update_registration_type(string type, int amount) {
    auto it = find_if(_registration_type_list.begin(), _registration_type_list.end(),
                      [&](const pair<string, int> &element) { return element.first == type; });
    if (it != _registration_type_list.end()) {
        it->second = amount;
    }
    else {
        _registration_type_list.emplace_back(type, amount);
    }
}
