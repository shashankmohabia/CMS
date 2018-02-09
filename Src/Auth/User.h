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
    bool _superuser_status, _payment_status;
    string _first_name, _last_name, _username, _password, _email, _contact;
    string _date_of_registration, _address, _city, _state, _country, _pincode;       //type = A B C
    char _gender, _registration_type;


public:
    User() = default;

    //Parametrised constructor
    // _first_name, _last_name, _username, _password, _email, _contact, _date_of_registration, _address, _city, _state, _country, _pincode, _gender, _registration_type
    User(string, string, string, string, string, string, string, string, string, string, string, string, char, char);

    static map<string, User> all();

    string get_username();

    string get_full_name();

    string get_password();

    char get_registration_type();

    bool check_password(string);

    bool is_payment_done();

    bool is_superuser();

    void change_password();

    void make_payment();

    void save();

    void remove();

    void show_user_details();

    void create_superuser();

    void remove_superuser(string);

    void modify_user_details();
};









/*

class Registered_User : public User {
private:
    static map<string, Registered_User> _registered_user_list;
    bool _payment_status;
    string _date_of_registration, _address, _city, _state, _country, _pincode, _registration_type;       //A B C

public:
    Registered_User()= default;

    Registered_User(string, string, string, string, string, string);

    static map<string, Registered_User> all();

    void make_payment();

    void register_user();

    void unregister();

    void show_user_details();

    string get_full_address();

    string get_date_of_registration();

    string get_registration_type();

    //int get_payment_amount();

    bool is_payment_done();

    bool is_superuser() final;

    bool is_registered() final;
};

class Superuser : public User {
private:
    static map<string, Superuser> _superuser_list;
public:
    Superuser() = default;

    static map<string, Superuser> all();

    void create_superuser();

    void remove_superuser(string);

    void modify_user_details();

    bool is_superuser() final;

    bool is_registered() final;

};
*/
#endif //CMS_USER_H
