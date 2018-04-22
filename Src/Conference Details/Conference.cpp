//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Conference.h"


Conference *conference = new Conference;

map<string, Conference> Conference::_conference_list = {};

Conference::Conference(string c_name, string c_date, string c_venue, string c_time) {
    _c_name = std::move(c_name);
    _c_date = std::move(c_date);
    _c_venue = std::move(c_venue);
    _c_time = std::move(c_time);
    _conference_list.insert(pair<string, Conference>(this->get_c_name(), *this));
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

void Conference::update_c_name(string c_name) {
    _conference_list.erase(_c_name);
    _c_name = std::move(c_name);
    _conference_list.insert(pair<string, Conference>(this->get_c_name(), *this));
}

void Conference::update_c_date(string c_date) {
    _conference_list.erase(_c_name);
    _c_date = std::move(c_date);
    _conference_list.insert(pair<string, Conference>(this->get_c_name(), *this));
}

void Conference::update_c_time(string c_time) {
    _conference_list.erase(_c_name);
    _c_time = std::move(c_time);
    _conference_list.insert(pair<string, Conference>(this->get_c_name(), *this));
}

void Conference::update_c_venue(string c_venue) {
    _conference_list.erase(_c_name);
    _c_venue = std::move(c_venue);
    _conference_list.insert(pair<string, Conference>(this->get_c_name(), *this));
}

int Conference::get_seats_available() {
    return _seats_available;
}

void Conference::show_conference_details() {
    cout << "Name: " << _c_name;
    cout << "\nDate: " << _c_date;
    cout << "\nTime: " << _c_time;
    cout << "\nSeats Available" << _seats_available;
}

void Conference::update_seat_available(int seats) {
    _conference_list.erase(_c_name);
    _seats_available = seats;
    _conference_list.insert(pair<string, Conference>(this->get_c_name(), *this));
}

bool Conference::get_user_payment_status(string username) {
    return find(_payment_done_list.begin(), _payment_done_list.end(), username) != _payment_done_list.end();
}

void Conference::make_payment(string username) {
    if (find(_payment_done_list.begin(), _payment_done_list.end(), username) == _payment_done_list.end()) {
        _payment_done_list.push_back(username);
    } else {
        /*Error "You have already paid!";*/
    }
}

void Conference::show_final_attendee_list() {
    cout << "Final Attendee List\n";
    for (const auto &i : _payment_done_list) {
        cout << i << endl;
    }
}

void Conference::show_registration_list() {
    cout << "Registration List\n";
    for (const auto &i : _registration_list) {
        cout << i << endl;
    }
}

void Conference::show_pending_payment_user_list() {
    cout << "Pending Payment User List\n";
    for (const auto &i : _registration_list) {
        if (find(_payment_done_list.begin(), _payment_done_list.end(), i) == _payment_done_list.end())
            cout << i << endl;
    }
}

void Conference::show_registration_type_list(string r_type) {
    for (const auto &i : _payment_details.get_registration_type_list()) {
        cout << i.first << endl;
    }
}

void Conference::update_registration_list(const string &username) {
    _registration_list.push_back(username);
    _seats_available--;
}

int Conference::give_total_number_of_registrations() {
    return static_cast<int>(_registration_list.size());
}

int Conference::give_total_number_of_pending_registrations() {
    return static_cast<int>(_registration_list.size() - _payment_done_list.size());
}

int Conference::give_total_number_of_attendees() {
    return static_cast<int>(_payment_done_list.size());
}

map<string, Conference> &Conference::conference_list() {
    return _conference_list;
}

Payment &Conference::payment_details() {
    return _payment_details;
}

bool Conference::get_user_registration_status(string username) {
    return find(_registration_list.begin(), _registration_list.end(), username) != _registration_list.end();
}

vector<string> &Conference::get_registration_list() {
    return _registration_list;
}

vector<string> &Conference::get_payment_done_list() {
    return _payment_done_list;
}
