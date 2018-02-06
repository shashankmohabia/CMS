//
// Created by Shashank Mohabia on 2/6/2018.
//
#ifndef CMS_USER_H
#define CMS_USER_H

#include <iostream>
#include <string>

using namespace std;

class User {

protected:
    string _first_name, _last_name, _username, _password, _email, _contact;  //contact optional
    char _gender;
    bool _superuser_status, _registration_status;;

public:
    User();

    User(string, string, string, string, string, string, char);

    void save_user();

    void delete_user();

    string get_username();

    string get_full_name();

    string get_password();

    bool check_password();


    virtual bool is_registered();

    virtual bool is_superuser();            // check whether the user is superuser or not
};

class Registered_User : public User {
private:
    bool _payment_status;
    string _date_of_registration, _address, _pincode, _city, _state, _country, _registration_type;       //A B C

public:
    Registered_User();

    Registered_User(string, string, string, string, string, string);


    void make_payment();

    void unregister();

    void show_user_details();

    string get_full_address();

    string get_date_of_registration();

    string get_registration_type();

    int get_payment_amount();

    bool is_payment_done();

    bool is_superuser() final;

    bool is_registered() final;
};

class Superuser : public User {
public:
    Superuser();


    void create_superuser();

    void remove_superuser();

    void modify_user_details();

    bool is_superuser() final;

    bool is_registered() final;

};

#endif //CMS_USER_H
