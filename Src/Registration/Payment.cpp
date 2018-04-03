//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Payment.h"

int Payment::get_payment_amount(string type) {
    return _registration_type_list.find(type)->second;
}

void Payment::add_registration_type(string type, int amount) {
    _registration_type_list.insert(pair<string, int>(type, amount));
}

map<string, int> &Payment::get_registration_type_list() {
    return _registration_type_list;
}

void Payment::update_registration_type(string type, int amount) {
    if(_registration_type_list.find(type)!=_registration_type_list.end()){
        _registration_type_list.find(type)->second = amount;
    }
    else{
        add_registration_type(type, amount);
    }
}
