//
// Created by Shashank Mohabia on 2/7/2018.
//

#include <fstream>
#include "Init.h"
#include "Database/File.h"

Init* Init::instance = nullptr;

Init::Init() {
    // Dummy Data
    /*User user("Lakshya", "Garg", "dummy", "dummy", "garg.2@iitj.ac.in", "8283875162", "13022018", "316, B1",
              "Jodhpur", "Rajasthan", "India", "342037", 'M');
    user.create_superuser();
    user.save();
    conference = new Conference("IEEE", "2 oct", "Jaipur", "12:12 PM");
    conference->update_seat_available(20);
    Conference::conference_list().find("IEEE")->second.payment_details().add_registration_type("Normal", 69);
    Conference::conference_list().find("IEEE")->second.payment_details().add_registration_type("VIP", 6969);*/
    //cout << user.is_superuser();
}

void Init::start() {
    File::read_conference_list();
    File::read_user_list();
    Menu* menu = Menu::getInstance();
    do {
        menu->display();
    } while (!menu->exitcode());
    File::write_conference_list();
    File::write_user_list();
}

Init* Init::getInstance() {
    if(instance == nullptr){
        instance = new Init;
        return instance;
    }
    return instance;
}

