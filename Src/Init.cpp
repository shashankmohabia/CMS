//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Init.h"
#include <iostream>
#include <string>
#include <map>
#include "Auth/User.h"

using namespace std;

Init::Init() {
    string first_name, last_name, username, password, email, contact, address, city, state, country, pincode, dor; //asked during registration
    first_name = "Shashank";
    last_name = "Mohabia";
    username = "smohabia";
    password = "mohabia";
    email = "shashankmohabia27@gmail.com";
    contact = "8504939946";
    dor = "today";
    address = city = "Jaipur";
    state = "Rajasthan";
    country = "India";
    pincode = "302021";
    dor = "today";
    char gender = 'M';
    User admin = User(first_name, last_name, username, password, email, contact, dor, address, city, state, country, pincode, gender);

}
