//
// Created by Shashank Mohabia on 2/7/2018.
//

#ifndef CMS_REGISTRATION_H
#define CMS_REGISTRATION_H

#include <iostream>
#include <string>
#include <map>
#include "../Auth/User.h"

using namespace std;

class Registration {


public:
    Registration();

    static void show_authenticated_user_list();                //shows list of users who made complete payments

    static void show_registered_user_list();

    static void show_pending_payment_user_list();

    static void show_registration_type_list(string);

    static void show_admin_list();

    static void update_registration_list();                    //in case of any problems admin has the right to update registration's list

    static void update_admin_list();

    static int give_total_number_of_admins();

    static unsigned long long int give_total_number_of_registrations();

    static int give_total_number_of_pending_registrations();

    static int give_total_number_of_authorised_registrations();
};


#endif //CMS_REGISTRATION_H
