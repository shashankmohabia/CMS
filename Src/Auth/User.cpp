//
// Created by Shashank Mohabia on 2/6/2018.
//

#include "User.h"

#include <utility>

#define system_pause {                                          \
            cout << "Press Enter to continue!\n";               \
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); \
        }

map<string, User> User::_user_list = {};

User *current_user = new User;

User::User(string username, string password) {
    _username = std::move(username);
    _password = std::move(password);
}

map<string, User> &User::all() {
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

bool User::check_password(string password) {
    return _password == password;
}

bool User::is_payment_done(string conference_name) {
    Conference::conference_list().find(conference_name)->second.get_user_payment_status(this->get_username());
}

bool User::is_superuser() {
    return _superuser_status;
}

void User::change_password(string new_password) {
    _password = std::move(new_password);            //Check for empty strings/same password
}

void User::save() {
    if (User::all().find(this->get_username()) != User::all().end()) {
        UserError("User already exists");
    }
    else {
        _user_list.insert(pair<string, User>(this->get_username(), *this));
    }
}

void User::remove(string username) {
    if (User::all().find(username) == User::all().end()) {
        UserError("User doesn't exists");
    }
    else {
        User::all().erase(User::all().find(username));
    }
}

void User::show_user_details() {
    cout << "Name: " << get_full_name();
    cout << "\nUsername: " << _username;
    cout << "\nE-mail: " << _email;
    cout << "\nContact: " << _contact;
    cout << "\nDate of Registration: " << _date_of_registration;
    cout << "\nAddress: " << _address;
    cout << "\nCity: " << _city;
    cout << "\nState: " << _state;
    cout << "\nCountry: " << _country;
    cout << "\nPincode: " << _pincode;
    cout << "\nGender: " << _gender;
    cout << "\nSuperuser Status: ";
    cout << std::boolalpha << _superuser_status << "\n\n";
}

void User::create_superuser(string username) {
    auto user = User::all().find(username)->second;
    if (user.is_superuser()) {
        UserError("This User is already a superuser!");
    }
    else {
        User::all().find(username)->second.create_superuser();
    }
}

void User::remove_superuser(string username) {
    auto user = User::all().find(username)->second;
    if (!user.is_superuser()) {
        UserError("This User is already not a superuser!");
    }
    else {
        User::all().find(username)->second.remove_superuser();
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

void User::update_registered_conference_list(string conference, string type) {
    for (int i = 0; i < _registered_conference_list.size(); i++) {
        if (_registered_conference_list[i].first == conference) {
            UserError error("You are already registered for the conference!");
            cout << error.print_error();
            return;
        }
    }
    _registered_conference_list.emplace_back(conference, type);
}

void User::create_superuser() {
    _superuser_status = true;
}

void User::remove_superuser() {
    _superuser_status = false;
}

void User::show_registered_conference_list() {
    if (User::all().find(current_user->get_username())->second.registered_conference_list().empty()) {
        cout << "Not registered for any conferences!\n";
    }
    else {
        for (auto &i : User::all().find(current_user->get_username())->second.registered_conference_list()) {
            cout << i.first << "\t" << i.second << endl;
        }
    }
}

void User::registered_conference_list_payment() {
    if (_registered_conference_list.empty()) {
        cout << "Not registered for any conferences!\n";
    }
    else {
        wrong_choice:
        for (int i = 0; i < _registered_conference_list.size(); i++) {
            cout << i + 1 << "\t" << _registered_conference_list[i].first << "\t"
                 << _registered_conference_list[i].second << endl;
        }
        cout << "\nPlease enter the number of the conference for which you want to pay!\n";
        int choice;
        cin >> choice;
        if (choice > 0 && choice <= _registered_conference_list.size()) {
            choice--;
            if(Conference::conference_list().find(_registered_conference_list[choice].first)->second.get_user_payment_status(current_user->get_username())){
                cout << "Payment already processed!\n";
                system_pause
                return;
            }
            /*cout << "hi\n";*/
            cout << "The amount to be paid is Rs. " << Conference::conference_list().find(
                    _registered_conference_list[choice].first)->second.payment_details().get_payment_amount(
                    _registered_conference_list[choice].second);
            cout << "\nDo you really want to pay?\nPress Y to pay!\n";
            char a;
            cin >> a;
            if (a == 'Y') {
                Conference::conference_list().find(_registered_conference_list[choice].first)->second.make_payment(
                        this->get_username());
                cout << "Payment Successful\n";
            }
            else {
                cout << "Payment Cancelled!\n";
            }
        }
        else {
            cout << "Please enter a valid choice!\n";
            system_pause
            goto wrong_choice;
        }
    }
}

vector<pair<string, string>> & User::registered_conference_list() {
    return _registered_conference_list;
}

const string &User::get_first_name() const {
    return _first_name;
}

const string &User::get_last_name() const {
    return _last_name;
}

const string &User::get_email() const {
    return _email;
}

const string &User::get_contact() const {
    return _contact;
}

const string &User::get_date_of_registration() const {
    return _date_of_registration;
}

const string &User::get_address() const {
    return _address;
}

const string &User::get_city() const {
    return _city;
}

const string &User::get_state() const {
    return _state;
}

const string &User::get_country() const {
    return _country;
}

const string &User::get_pincode() const {
    return _pincode;
}

char User::get_gender() const {
    return _gender;
}

UserError::UserError(const string &err) {
    _err = err;
}

string UserError::print_error() {
    return _err;
}