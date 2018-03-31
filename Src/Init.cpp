//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Init.h"


Init::Init() {
    // Dummy Data
    User user("Lakshya", "Garg", "dummy", "dummy", "garg.2@iitj.ac.in", "8283875162", "13022018", "316, B1",
              "Jodhpur", "Rajasthan", "India", "342037", 'M');
    user.create_superuser();
    conference = new Conference("IEEE", "2 oct", "Jaipur", "12:12 PM");
    conference->update_seat_available(20);
    conference->payment_details().add_registration_type("Normal", 69);
    conference->payment_details().add_registration_type("VIP", 6969);
    Conference *conference1 = new Conference("CON1", "6 Sep", "Chandigarh", " 6:09 PM");
    conference1->payment_details().add_registration_type("Normal", 6969);
    conference1->payment_details().add_registration_type("VIP", 696969);
    conference1-> update_seat_available(69);
    //cout << user.is_superuser();
    user.save();
}

void Init::start() {
    Menu menu;
    /* Gets an instance of Menu class to select views on runtime, the implementation is in core/menu.cpp */
    do {
        menu.display();
    } while (!menu.exitcode());
}