//
// Created by Shashank Mohabia on 2/7/2018.
//

#ifndef CMS_CONFERENCE_H
#define CMS_CONFERENCE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "../Registration/Payment.h"

using namespace std;


class Conference {
private:
    string _c_name, _c_date, _c_venue, _c_time, _c_schedule;
    int _seats_available;
    Payment _payment_details;
    vector<string> _registration_list;
    vector<string> _payment_done_list;
    /*map _conference_list*/
public:
    Conference() = default;

    Conference(string, string, string, string);    //_c_name, _c_date, _c_venue, _c_time, _seats_available

    int get_seats_available();

    string get_c_name();

    string get_c_date();

    string get_c_venue();

    string get_c_time();

    void update_seat_available(int);

    void update_c_name();

    void update_c_date();

    void update_c_time();

    void update_c_venue();

    bool get_user_payment_status(string, string);   //c_name, username

    void make_payment(string, string);              //c_name, username

    void show_conference_details();

    void show_final_attendee_list();

    void show_registration_list();

    void show_pending_payment_user_list();

    void show_registration_type_list();

    void update_registration_list();

    int give_total_number_of_registrations();

    int give_total_number_of_pending_registrations();

    int give_total_number_of_attendees();

};


extern Conference* conference;


#endif //CMS_CONFERENCE_H
