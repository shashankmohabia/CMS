//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Conference.h"


Conference* conference = new Conference;

Conference::Conference(string c_name, string c_date, string c_venue, string c_time) {
    _c_name = std::move(c_name);
    _c_date = std::move(c_date);
    _c_venue = std::move(c_venue);
    _c_time = std::move(c_time);
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

void Conference::update_c_name() {

}

void Conference::update_c_date() {

}

void Conference::update_c_time() {

}

void Conference::update_c_venue() {

}

int Conference::get_seats_available() {
    return _seats_available;
}


void Conference::show_conference_details() {

}

void Conference::update_seat_available(int seats) {
    _seats_available = seats;
}
