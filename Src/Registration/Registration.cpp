//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Registration.h"

Registration::Registration() = default;

/*
void Registration::show_authenticated_user_list() {
    for (auto &it : User::all()) {
        if(it.second.is_payment_done()){
            cout << it.second.get_username()<<"\n";
        }
    }
}

void Registration::show_registered_user_list() {
    for (auto &it : User::all()) {
        cout << it.second.get_username()<<"\n";
    }
}

void Registration::show_pending_payment_user_list() {
    for (auto &it : User::all()) {
        if(!it.second.is_payment_done()){
            cout << it.second.get_username()<<"\n";
        }
    }
}

void Registration::show_registration_type_list(string registeration_type) {
    for (auto &it : User::all()) {
        if(it.second.get_registration_type() == registeration_type){
            cout << it.second.get_username()<<"\n";
        }
    }
}

void Registration::update_registration_list() {

}

unsigned long long int Registration::give_total_number_of_registrations() {
    return User::all().size();      //size() return type is unsigned Long long int
}

int Registration::give_total_number_of_pending_registrations() {
    int count = 0;
    for(auto &it : User::all()) {
        if(!it.second.is_payment_done()){
            count++;
        }
    }
    return count;
}

int Registration::give_total_number_of_authorised_registrations() {
    int count = 0;
    for(auto &it : User::all()) {
        if(it.second.is_payment_done()){
            count++;
        }
    }
    return count;
}

void Registration::show_admin_list() {
    for (auto &it : User::all()) {
        if(it.second.is_superuser()){
            cout << it.second.get_username() << "\n";
        }
    }
}

void Registration::update_admin_list() {

}

int Registration::give_total_number_of_admins() {
    int count = 0;
    for(auto &it : User::all()) {
        if(it.second.is_superuser()){
            count++;
        }
    }
    return count;
}
*/
