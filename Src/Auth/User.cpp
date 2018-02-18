//
// Created by Shashank Mohabia on 2/6/2018.
//

#include "User.h"

map<string, User> User::_registration_list = {};

User* current_user = new User;

User::User(string first_name, string last_name, string username, string password, string email, string contact, string dor, string address, string city, string state, string country, string pincode, char gender) {
    _first_name = std::move(first_name);
    _last_name = std::move(last_name);
    _username = std::move(username);
    _password = std::move(password);
    _email = std::move(email);
    _contact = std::move(contact);
    _date_of_registration = std::move(dor);
    _address = std::move(address);
    _city = std::move(city);
    _state = std::move(state);
    _country = std::move(country);
    _pincode = std::move(pincode);
    _gender = gender;
    _registration_type = "";
}

map<string, User>& User::all() {
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

string User::get_registration_type() {
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

void User::change_password(string new_password) {
    _password = std::move(new_password);            //Check for empty strings/same password
}

void User::make_payment() {
    _payment_status = true;
}

void User::save() {
    if(User::all().find(this->get_username())!=User::all().end()){
        UserError("User already exists");
    }
    else{
        _registration_list.insert(pair<string, User>(this->get_username(), *this));
    }
}

void User::remove(string username) {
    if(User::all().find(username)==User::all().end()){
        UserError("User doesn't exists");
    }
    else{
        User::all().erase(User::all().find(username));
    }
}

void User::show_user_details() {

}

void User::create_superuser(string username) {
    if(_superuser_status) {
        UserError("This User is already a superuser!");
    }
    else {
        _superuser_status = true;
    }
}

void User::remove_superuser(string username) {
    if(!_superuser_status) {
        UserError("This User is already not a superuser!");
    }
    else {
        _superuser_status = false;
    }
}

void User::modify_user_details() {

}

UserError::UserError(const string& err) {
    _err = err;
}

string UserError::print_error() {
    return _err;
}