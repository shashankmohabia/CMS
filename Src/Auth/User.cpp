//
// Created by Shashank Mohabia on 2/6/2018.
//

#include "User.h"

User::User() {

}

User::User(string, string, string, string, string, string, char) {

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

bool User::is_superuser() {
    return false;
}

void User::save_user() {

}

void User::delete_user() {

}

bool User::is_registered() {
    return false;
}

bool User::check_password() {
    return false;
}

void User::set_password() {

}

void User::change_password() {

}

void Superuser::create_superuser() {

}

bool Superuser::is_superuser() {
    return User::is_superuser();
}

void Superuser::remove_superuser() {

}

void Superuser::modify_user_details() {

}

bool Superuser::is_registered() {
    return User::is_registered();
}

Superuser::Superuser() {

}

bool Registered_User::is_superuser() {
    return User::is_superuser();
}

Registered_User::Registered_User(){

}


void Registered_User::make_payment() {

}

void Registered_User::unregister() {

}

void Registered_User::show_user_details() {

}

bool Registered_User::is_registered() {
    return User::is_registered();
}

bool Registered_User::is_payment_done() {
    return false;
}

string Registered_User::get_date_of_registration() {
    return std::string();
}

string Registered_User::get_full_address() {
    return std::string();
}

string Registered_User::get_registration_type() {
    return std::string();
}

Registered_User::Registered_User(string, string, string, string, string, string) {

}

int Registered_User::get_payment_amount() {
    return 0;
}
