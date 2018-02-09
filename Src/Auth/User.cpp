//
// Created by Shashank Mohabia on 2/6/2018.
//

#include "User.h"

User::User(string first_name, string last_name, string username, string password, string email, string contact, string dor, string address, string city, string state, string country, string pincode, char gender, char r_type) {
    _first_name = first_name;
    _last_name = last_name;
    _username = username;
    _password = password;
    _email = email;
    _contact = contact;
    _date_of_registration = dor;
    _address = address;
    _city = city;
    _state = state;
    _country = country;
    _pincode = pincode;
    _gender = gender;
    _registration_type = r_type;
}

map<string, User> User::all() {
    return _registration_list;
}

string User::get_username() {
    return _username;
}

string User::get_full_name() {
    return _first_name + " " + _last_name;
}

string User::get_password() {
    return _password;
}

char User::get_registration_type() {
    return _registration_type;
}

bool User::check_password(string password) {
    return _password == password;
}

bool User::is_payment_done() {
    return _payment_status;
}

bool User::is_superuser() {
    return _superuser_status;
}

void User::change_password() {

}

void User::make_payment() {

}

void User::save() {

}

void User::remove() {

}

void User::show_user_details() {

}

void User::create_superuser() {

}

void User::remove_superuser(string) {

}

void User::modify_user_details() {

}

UserError::UserError(const string& err) {
    _err = err;
}

string UserError::print_error() {
    return _err;
}
