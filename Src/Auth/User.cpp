//
// Created by Shashank Mohabia on 2/6/2018.
//

#include "User.h"

User::User(string, string, string, string, string, string, string, string, string, string, string, string, char, char) {

}

map<string, User> User::all() {
    return map<string, User>();
}

string User::get_username() {
    return std::string();
}

string User::get_full_name() {
    return std::string();
}

string User::get_password() {
    return std::string();
}

char User::get_registration_type() {
    return 0;
}

bool User::check_password(string) {
    return false;
}

bool User::is_payment_done() {
    return false;
}

bool User::is_superuser() {
    return false;
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

UserError::UserError(const string &) {

}

string UserError::print_error() {
    return std::string();
}
