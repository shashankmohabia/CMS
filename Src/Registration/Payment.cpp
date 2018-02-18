//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Payment.h"

map<string, int> Payment::_registration_type_list = {};

int Payment::get_payment_amount(string type) {
    return _registration_type_list.find(type)->second;
}

void Payment::add_registration_type(string type, int amount) {
    _registration_type_list.insert(pair<string, int>(type, amount));
}

void Payment::update_registration_type_list() {

}
