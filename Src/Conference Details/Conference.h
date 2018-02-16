//
// Created by Shashank Mohabia on 2/7/2018.
//

#ifndef CMS_CONFERENCE_H
#define CMS_CONFERENCE_H

#include <iostream>
#include <string>
#include <map>

using namespace std;


class Conference {
private:
    string _c_name, _c_date, _c_venue, _c_time, _c_schedule;
    int _seats_available;
public:
    Conference() = default;

    Conference(string, string, string, string, int);

    int get_seats_available();

    string get_c_name();

    string get_c_date();

    string get_c_venue();

    string get_c_time();

    string get_c_schedule();

    void update_c_name();

    void update_c_date();

    void update_c_time();

    void update_c_venue();

    void update_c_schedule();

    void update_seat_availability();

    void show_conference_details();

};


#endif //CMS_CONFERENCE_H
