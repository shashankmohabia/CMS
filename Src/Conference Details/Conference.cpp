//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Conference.h"

Conference::Conference(string c_name, string c_date, string c_venue, string c_time, int seats_available) {
    _c_name = c_name;
    _c_date = c_date;
    _c_venue = c_venue;
    _c_time = c_time;
    _seats_available = seats_available;

}


string Conference::get_c_name() {
    return _c_name;
}

string Conference::get_c_date() {
    return _c_date;
}

string Conference::get_c_venue() {
    return _c_venue;
}

string Conference::get_c_time() {
    return _c_time;
}

string Conference::get_c_schedule() {
    return _c_schedule;
}

void Conference::update_c_name() {

}

void Conference::update_c_date() {

}

void Conference::update_c_time() {

}

void Conference::update_c_venue() {

}

void Conference::update_c_schedule() {

}

int Conference::get_seats_available() {
    return _seats_available;
}


void Conference::update_seat_availability() {

}


void Conference::show_conference_details() {

}
