//
// Created by Shashank Mohabia on 2/7/2018.
//

#ifndef CMS_CONFERENCE_H
#define CMS_CONFERENCE_H

#include <iostream>
#include <string>

using namespace std;


class Conference {
private:
    string _c_name, _c_date, _c_venue, _c_time, _c_schedule;
    int seats_available;
public:
    Conference();

    Conference(string, string, string, string);

    int get_seats_available();

    void set_seat_availability();                       //sets the number of seats available of different types

    void show_seat_availability();

    void update_seat_availability();

    void set_c_schedule();

    void get_c_name();

    void get_c_date();

    void get_c_venue();

    void get_c_time();

    void get_c_schedule();

    void update_c_name();

    void update_c_date();

    void update_c_time();

    void update_c_venue();

    void update_c_schedule();

    void show_conference_details();

};


#endif //CMS_CONFERENCE_H
