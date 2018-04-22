//
// Created by Shashank Mohabia on 2/7/2018.
//

#ifndef CMS_CONFERENCE_H
#define CMS_CONFERENCE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "../Registration/Payment.h"

using namespace std;


class Conference {
private:
    string _c_name, _c_date, _c_venue, _c_time;
    int _seats_available;
    Payment _payment_details;
    vector<string> _registration_list;
    vector<string> _payment_done_list;
    static map<string, Conference> _conference_list;
public:
    Conference() = default;

    explicit Conference(string, string, string, string);    //_c_name, _c_date, _c_venue, _c_time, _seats_available

    int get_seats_available();

    string get_c_name();

    string get_c_date();

    string get_c_venue();

    string get_c_time();

    void update_seat_available(int);

    void update_c_name(string);

    void update_c_date(string);

    void update_c_time(string);

    void update_c_venue(string);

    bool get_user_registration_status(string);  //username

    bool get_user_payment_status(string);       //username

    void make_payment(string);                  //username

    void show_conference_details();

    void show_final_attendee_list();

    void show_registration_list();

    void show_pending_payment_user_list();

    void show_registration_type_list(string);   //r_type

    void update_registration_list(const string &);

    int give_total_number_of_registrations();

    int give_total_number_of_pending_registrations();

    int give_total_number_of_attendees();

    static map<string, Conference> &conference_list();

    Payment &payment_details();

    vector<string> & get_registration_list();

    vector<string> & get_payment_done_list();

};


extern Conference *conference;


#endif //CMS_CONFERENCE_H
