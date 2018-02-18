//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Init.h"


Init::Init() {
    // Dummy Data
    User user("Lakshya", "Garg", "lakshyagarg", "lakshyagarg", "garg.2@iitj.ac.in", "8283875162", "13022018", "316, B1",
              "Jodhpur", "Rajasthan", "India", "342037", 'M');
    //user.create_superuser();
    user.save();
    conference = new Conference("IEEE", "2 oct", "Jaipur", "12:12 pm", 50);
    Payment::add_registration_type("Normal", 600);
    Payment::add_registration_type("VIP", 2000);
}

void Init::start() {
    Menu menu;
    /* Gets an instance of Menu class to select views on runtime, the implementation is in core/menu.cpp */
    do {
        menu.display();
    } while (!menu.exitcode());
}
