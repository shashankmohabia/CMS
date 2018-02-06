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
private:
    map<string, Registered_User> _registered_user_list;
    map<string, Superuser> _superuser_list;
public:
    Registration();

    void show_authenticated_user_list();                //shows list of users who made complete payments

    void show_registered_user_list();

    void show_pending_payment_user_list();

    void show_registration_type_list();

    void update_registration_list();                    //in case of any problems admin has the right to update registration's list

    int give_total_number_of_registrations();

    int give_total_number_of_pending_registrations();

    int give_total_number_of_authorised_registrations();

    void show_admin_list();

    void update_admin_list();

    int give_total_number_of_admins();
};


#endif //CMS_REGISTRATION_H
