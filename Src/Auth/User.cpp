//
// Created by Shashank Mohabia on 2/6/2018.
//

#include "User.h"

#include <utility>

map<string, User> User::_user_list = {};

User* current_user = new User;

User::User(string username, string password) {
    _username = std::move(username);
    _password = std::move(password);
}

map<string, User>& User::all() {
    return _user_list;
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

string User::get_email() {
    return _email;
}

string User::get_contact() {
    return _contact;
}

string User::get_date_of_registration() {
    return _date_of_registration;
}

string User::get_address() {
    return _address;
}

string User::get_city() {
    return _city;
}

string User::get_state() {
    return _state;
}

string User::get_country() {
    return _country;
}

string User::get_pincode() {
    return _pincode;
}

char User::get_gender() {
    return _gender;
}

bool User::check_password(string password) {
    return _password == password;
}

bool User::is_payment_done(string conference_name) {

}

bool User::is_superuser() {
    return _superuser_status;
}

void User::change_password(string new_password) {
    _password = std::move(new_password);            //Check for empty strings/same password
}

void User::save() {
    if(User::all().find(this->get_username())!=User::all().end()){
        UserError("User already exists");
    }
    else{
        _user_list.insert(pair<string, User>(this->get_username(), *this));
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
    auto user = User::all().find(username)->second;
    if(user.is_superuser()) {
        UserError("This User is already a superuser!");
    }
    else {
        /*User::all().find(username)->second.create_superuser();*/
    }
}

void User::remove_superuser(string username) {
    auto user = User::all().find(username)->second;
    if(!user.is_superuser()) {
        UserError("This User is already not a superuser!");
    }
    else {
        /*User::all().find(username)->second.remove_superuser();*/
    }
}

void User::set_first_name(const string &_first_name) {
    User::_first_name = _first_name;
}

void User::set_last_name(const string &_last_name) {
    User::_last_name = _last_name;
}

void User::set_username(const string &_username) {
    User::_username = _username;
}

void User::set_password(const string &_password) {
    User::_password = _password;
}

void User::set_email(const string &_email) {
    User::_email = _email;
}

void User::set_contact(const string &_contact) {
    User::_contact = _contact;
}

void User::set_date_of_registration(const string &_date_of_registration) {
    User::_date_of_registration = _date_of_registration;
}

void User::set_address(const string &_address) {
    User::_address = _address;
}

void User::set_city(const string &_city) {
    User::_city = _city;
}

void User::set_state(const string &_state) {
    User::_state = _state;
}

void User::set_country(const string &_country) {
    User::_country = _country;
}

void User::set_pincode(const string &_pincode) {
    User::_pincode = _pincode;
}

void User::set_gender(char _gender) {
    User::_gender = _gender;
}

User::User(string first_name, string last_name, string username, string password, string email, string contact,
           string date_of_registration, string address, string city, string state, string country, string pincode,
           char gender) {
    _first_name = std::move(first_name);
    _last_name = std::move(last_name);
    _username = std::move(username);
    _password = std::move(password);
    _email = std::move(email);
    _contact = std::move(contact);
    _date_of_registration = std::move(date_of_registration);
    _address = std::move(address);
    _city = std::move(city);
    _state = std::move(state);
    _country = std::move(country);
    _pincode = std::move(pincode);
    _gender = gender;
}

/*void User::create_superuser() {
    _superuser_status = true;
}

void User::remove_superuser() {
    _superuser_status = false;
}*/

UserError::UserError(const string& err) {
    _err = err;
}

string UserError::print_error() {
    return _err;
}