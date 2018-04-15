//
// Created by Shashank Mohabia on 2/6/2018.
//
#ifndef CMS_USER_H
#define CMS_USER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "../Conference Details/Conference.h"

using namespace std;


class UserError {
private:
    string _err;
public:
    explicit UserError(const string &);
    string print_error();
};

class User {
    static map<string, User> _user_list;
    vector <pair<string, string> > _registered_conference_list;                  //conference, type
    bool _superuser_status = false;
    string _first_name, _last_name, _username, _password, _email, _contact;
    string _date_of_registration, _address, _city, _state, _country, _pincode;
    char _gender{};


public:
    User() = default;

    //Parametrised constructor
    //_first_name, _last_name, _username, _password, _email, _contact, _date_of_registration, _address, _city, _state, _country, _pincode, _gender
    User(string, string, string, string, string, string, string, string, string, string, string, string, char);

    //Parametrised constructor
    //_username, _password
    User(string, string);

    static map<string, User>& all();

    string get_username();

    string get_full_name();

    string get_password();

    bool check_password(string);        //password

    bool is_payment_done(string);       //conference name

    bool is_superuser();

    void change_password(string);       //password

    void save();

    void remove(string);                //user

    void show_user_details();

    void create_superuser(string);      //username

    void remove_superuser(string);      //username

    void create_superuser();

    void remove_superuser();

    void set_first_name(const string &_first_name);

    void set_last_name(const string &_last_name);

    void set_username(const string &_username);

    void set_password(const string &_password);

    void set_email(const string &_email);

    void set_contact(const string &_contact);

    void set_date_of_registration(const string &_date_of_registration);

    void set_address(const string &_address);

    void set_city(const string &_city);

    void set_state(const string &_state);

    void set_country(const string &_country);

    void set_pincode(const string &_pincode);

    void set_gender(char _gender);

    void update_registered_conference_list(string, string);     //conference_name, registration_type

    void show_registered_conference_list();

    void registered_conference_list_payment();

    vector<pair<string, string>> & registered_conference_list();

    const string &get_first_name() const;

    const string &get_last_name() const;

    const string &get_email() const;

    const string &get_contact() const;

    const string &get_date_of_registration() const;

    const string &get_address() const;

    const string &get_city() const;

    const string &get_state() const;

    const string &get_country() const;

    const string &get_pincode() const;

    char get_gender() const;

};

extern User* current_user;

#endif //CMS_USER_H
