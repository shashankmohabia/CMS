//
// Created by Shashank Mohabia on 2/7/2018.
//

#include "Init.h"

Init::Init() {
    // Dummy Data
    User user("Lakshya","Garg", "lakshyagarg", "lakshyagarg", "garg.2@iitj.ac.in", "8283875162", "13022018", "316, B1", "Jodhpur", "Rajasthan", "India", "342037", 'M');
    user.create_superuser();
    user.save();
    cout << Registration::give_total_number_of_registrations();
}
