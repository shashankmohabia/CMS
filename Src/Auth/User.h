//
// Created by Shashank Mohabia on 2/6/2018.
//
#ifndef CMS_USER_H
#define CMS_USER_H

#include <iostream>
#include <string>
#include <map>

using namespace std;


class UserError {
private:
    string _err;
public:
    explicit UserError(const string &);

    string print_error();
};

class User {
    static map<string, User> _registration_list;
    bool _superuser_status = false, _payment_status = false;
    string _first_name, _last_name, _username, _password, _email, _contact;
    string _date_of_registration, _address, _city, _state, _country, _pincode, _registration_type;       //type = A B C
    char _gender{};


public:
    User() = default;

    //Parametrised constructor
    // _first_name, _last_name, _username, _password, _email, _contact, _date_of_registration, _address, _city, _state, _country, _pincode, _gender
    User(string, string, string, string, string, string, string, string, string, string, string, string, char);

    static map<string, User>& all();

    string get_username();

    string get_full_name();

    string get_password();

    string get_registration_type();

    bool check_password(string);

    bool is_payment_done();

    bool is_superuser();

    void change_password(string);

    void make_payment();

    void save();

    void remove(string);

    void show_user_details();

    void create_superuser(string);

    void remove_superuser(string);  // removes by _username

    void modify_user_details();
};

extern User* current_user;

#endif //CMS_USER_H
