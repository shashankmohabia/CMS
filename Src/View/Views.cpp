//
// Created by Shashank Mohabia on 2/16/2018.
//

#include "Views.h"


VIEW_CHOICES Views::display() {
}

VIEW_CHOICES SplashView::display() {
    cout << "Splash view" << endl;
    cout << "choose 1 option" << endl;
    int choice;
    cout << "1. Login\n2. Register\n3. Details\n4. Exit" << endl;
    cin >> choice;
    switch (choice) {
        case 1: {
            return VIEW_CHOICES(LOGIN);
        }
        case 2: {
            return VIEW_CHOICES(REGISTER);
        }
        case 3: {
            return VIEW_CHOICES(DETAIL);
        }
        case 4: {
            return VIEW_CHOICES(EXIT);
        }
        default: {
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}


VIEW_CHOICES LoginView::display() {
    cout << "Login view" << endl;
    cout << "Enter Username or type '$' to return to main menu " << endl;
    string username, password;
    cin >> username;
    if (username == "$") {
        return VIEW_CHOICES(SPLASH);
    }
    cout << "Enter Password" << endl;
    cin >> password;
    auto user = User::all().find(username);
    if (user != User::all().end()) {
        if (user->second.check_password(password)) {
            //cout << user->second.get_full_name();
            current_user = &(user->second);
            //cout << current_user->is_superuser();
            if (current_user->is_superuser()) {
                return VIEW_CHOICES(ADMIN_DASHBOARD);
            }
            else {
                return VIEW_CHOICES(USER_DASHBOARD);
            }
        }
        else {
            UserError("The password is incorrect!");
        }
    }
    else {
        UserError("Username doesn't exist");
    }
    return VIEW_CHOICES(LOGIN);
}

VIEW_CHOICES RegisterView::display() {
    if (!conference->get_seats_available()) {
        cout << "Registrations are closed!" << endl;
        //cout << "Press any key to go back to menu screen" << endl;
        return VIEW_CHOICES(SPLASH);
    }
    cout << "Enter Register view" << endl;
    string firstName, lastName, username, password, rpassword, email, contact;
    string address, city, state, country, pincode;
    char gender;
    username_exists :
    cout << "Enter Username: ";
    cin >> username;
    if (User::all().find(username) != User::all().end()) {
        UserError("This Username already exists!");
        goto username_exists;
    }
    cout << "Enter First name: ";
    cin >> firstName;
    cout << "Enter Last name: ";
    cin >> lastName;
    cout << "Enter Gender: ";
    cin >> gender;
    wrong_password :
    cout << "Enter Password: ";
    cin >> password;
    cout << "Re-enter Password: ";
    cin >> rpassword;
    if (password != rpassword) {
        UserError give_me_a_name("Both the passwords do not match!");
        goto wrong_password;
    }
    cout << "Enter E-mail";
    cin >> email;
    cout << "Enter Contact";
    cin >> contact;
    cout << "Enter Address";
    cin >> address;
    cout << "Enter City";
    cin >> city;
    cout << "Enter State";
    cin >> state;
    cout << "Enter Country";
    cin >> country;
    cout << "Enter Pincode";
    cin >> pincode;
    auto dor = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    User user(firstName, lastName, username, password, email, contact, std::ctime(&dor), address,
              city, state, country, pincode, gender);
    user.save();
    cout << "You are successfully registered!" << endl;
    cout << User::all().size() << endl;
    return VIEW_CHOICES(SPLASH);
}


VIEW_CHOICES UserDashboardView::display() {
    cout << "Hi " << current_user->get_full_name() << endl;
    user_dashboard:
    cout << "What do you want to do!" << endl;
    int choice;
    cout
            << "1. Registered Conferences\n2. User Profile\n3. All Conference Details\n4. Register for a Conference\n5. Make Payment\n6.Change Password\n7. Logout"
            << endl;
    cin >> choice;
    switch (choice) {
        case 1: {
            current_user->show_registered_conference_list();
            return VIEW_CHOICES(USER_DASHBOARD);
        }
        case 2: {
            return VIEW_CHOICES(PROFILE);
        }
        case 3: {
            return VIEW_CHOICES(DETAIL);
        }
        case 4: {
            cout << "Please enter the name of the conference you want to register for from the following!\n";
            for (auto &i : Conference::conference_list()) {
                cout << i.first << "\n";
            }
            string c_name;
            cin >> c_name;
            if (Conference::conference_list().find(c_name) != Conference::conference_list().end()) {
                cout << "Select the type of registration!\n";
                for (auto &i : Conference::conference_list().find(
                        c_name)->second.payment_details().get_registration_type_list()) {
                    cout << i.first << "\t" << i.second << endl;
                }
                string c_type;
                cin >> c_type;
                if (Conference::conference_list().find(
                        c_name)->second.payment_details().get_registration_type_list().find(c_type) !=
                    Conference::conference_list().find(
                            c_name)->second.payment_details().get_registration_type_list().end()) {
                    cout << "Do you really want to pay Rs " << Conference::conference_list().find(
                            c_name)->second.payment_details().get_registration_type_list().find(c_type)->second;
                    cout << "\nPress Y to continue.\n";
                    int flag;
                    cin >> flag;
                    if (flag != 'Y') {
                        //Error
                    }
                    else {
                        current_user->update_registered_conference_list(c_name, c_type);
                        Conference::conference_list().find(c_name)->second.update_registration_list(
                                current_user->get_username());
                        cout << "You have been successfully registered for the conference!\n";
                    }
                }
                else {
                    //Error
                }
            }
            else {
                //Error
            }
            return USER_DASHBOARD;
        }
        case 5: {
            return VIEW_CHOICES(PAYMENT);
        }
        case 6: {
            string password, new_password, re_enter_password;
            cout << "Enter Previous Password: ";
            cin >> password;
            if (current_user->get_password() == password) {
                cout << "Enter New Password: ";
                cin >> new_password;
                cout << "Re-enter New Password: ";
                cin >> re_enter_password;
                if (new_password == re_enter_password) {
                    current_user->set_password(new_password);
                    current_user->save();
                }
                else {
                    //Error
                }
            }
            else {
                //Error
            }
        }
        case 7: {
            return VIEW_CHOICES(SPLASH);
        }
        default: {
            cout << "Please select a valid option" << endl;
            goto user_dashboard;
        }
    }
}

VIEW_CHOICES AdminDashboardView::display() {
    cout << "Hi " << current_user->get_full_name() << endl;
    user_dashboard:
    cout << "What do you want to do!" << endl;
    int choice;
    cout
            << "1. User Profile\n2. Conference Details\n3. Registered Data\n4. Update Conference Details\n5. Make Superuser\n6. Remove Superuser\n7. Remove User\n8. Logout"
            << endl;
    cin >> choice;
    switch (choice) {
        case 1: {
            return VIEW_CHOICES(PROFILE);
        }
        case 2: {
            return VIEW_CHOICES(DETAIL);
        }
        case 3: {
            return VIEW_CHOICES(REGISTER_DETAILS);
        }
        case 4: {
            cout << "Please enter the name of the conference you want to update from the following!\n";
            for (auto &i : Conference::conference_list()) {
                cout << i.first << "\n";
            }
            string c_name;
            cin >> c_name;
            if (Conference::conference_list().find(c_name) != Conference::conference_list().end()) {
                cout << "Choose the detail to edit!\n";
                cout << "1. Name\n2. Date\n3. Time\n4. Venue\n";
                int i;
                cin >> i;
                switch (i) {
                    case 1: {
                        cout << "Enter the new name of the Conference: ";
                        string new_c_name;
                        cin >> new_c_name;
                        Conference::conference_list().find(c_name)->second.update_c_name(new_c_name);
                        break;
                    }
                    case 2: {
                        cout << "Enter the new date of the Conference: ";
                        string new_c_date;
                        cin >> new_c_date;
                        Conference::conference_list().find(c_name)->second.update_c_date(new_c_date);
                        break;
                    }
                    case 3: {
                        cout << "Enter the new time of the Conference: ";
                        string new_c_time;
                        cin >> new_c_time;
                        Conference::conference_list().find(c_name)->second.update_c_time(new_c_time);
                        break;
                    }
                    case 4: {
                        cout << "Enter the new venue of the Conference: ";
                        string new_c_venue;
                        cin >> new_c_venue;
                        Conference::conference_list().find(c_name)->second.update_c_venue(new_c_venue);
                        break;
                    }
                    default: {
                        //Error
                        break;
                    }
                }
            }
            else {
                //Error
            }
        }
        case 5: {
            cout << "Please enter the name of the user to grant superuser access: ";
            string username;
            cin >> username;
            auto user = User::all().find(username);
            if (user != User::all().end()) {
                if (user->second.is_superuser()) {
                    UserError("This user is already a superuser!");
                }
                else {
                    user->second.create_superuser(username);
                }
            }
            else {
                UserError("User doesn't exists!");
            }
            return ADMIN_DASHBOARD;
        }
        case 6: {
            cout << "Please enter the name of the user to revoke superuser access: ";
            string username;
            cin >> username;
            auto user = User::all().find(username);
            if (user != User::all().end()) {
                if (user->second.is_superuser()) {
                    user->second.remove_superuser(username);
                }
                else {
                    UserError("This user is already not a superuser!");
                }
            }
            else {
                UserError("User doesn't exists");
            }
        }
        case 7: {
            cout << "Please enter the name of the user to be removed: ";
            string username;
            cin >> username;
            auto user = User::all().find(username);
            if (user != User::all().end()) {
                User::all().erase(user);
            }
            else {
                UserError("User doesn't exists");
            }
        }
        case 8: {
            return SPLASH;
        }
        default: {
            cout << "Please select a valid option" << endl;
            goto user_dashboard;
        }
    }
}

VIEW_CHOICES ProfileView::display() {
    current_user->show_user_details();
    if (current_user->is_superuser()) {
        return ADMIN_DASHBOARD;
    }
    else {
        return USER_DASHBOARD;
    }
}

VIEW_CHOICES PaymentView::display() {
    current_user->registered_conference_list_payment();
    return USER_DASHBOARD;

}

VIEW_CHOICES ConferenceDetailView::display() {
    cout << "Conference Detail View\n\n";
    for (auto &it : Conference::conference_list()) {
        cout << "Name: \t\t\t\t\t\t" << it.second.get_c_name() << endl;
        cout << "Date: \t\t\t\t\t\t" << it.second.get_c_date() << endl;
        cout << "Time: \t\t\t\t\t\t" << it.second.get_c_time() << endl;
        cout << "Venue: \t\t\t\t\t\t" << it.second.get_c_venue() << endl;
        cout << "Current Seat Availability: \t" << it.second.get_seats_available() << "\n\n";
    }
    cout << "\n\n";
    if (current_user->get_username().empty()) {
        return VIEW_CHOICES(SPLASH);
    }
    else if (current_user->is_superuser()) {
        return VIEW_CHOICES(ADMIN_DASHBOARD);
    }
    else {
        return VIEW_CHOICES(USER_DASHBOARD);
    }
}

VIEW_CHOICES RegisterDetailView::display() {
    if (!current_user->is_superuser()) {
        cout << "\n\nExcess Denied\n\n";
        return VIEW_CHOICES(USER_DASHBOARD);
    }
    cout << "Registration Detail View\n\n";
    cout << "Enter the name of conference to view registration details\n";
    for (auto &i : Conference::conference_list()) {
        cout << i.first << "\n";
    }
    string c_name;
    cin >> c_name;
    if (Conference::conference_list().find(c_name) != Conference::conference_list().end()) {
        auto conference = Conference::conference_list().find(c_name)->second;
        cout << "Total Number of Registrations = " << conference.give_total_number_of_registrations() << endl;
        cout << "Total Number of Pending Registrations = " << conference.give_total_number_of_pending_registrations()
             << endl;
        cout << "Total Number of Authorized Registrations = " << conference.give_total_number_of_attendees() << endl;
        cout << "\nChoose any one of the options\n";
        show:
        cout << "1. Show Final Attendee List\n2. Show Registered User List\n3. Show Pending Payment User List\n"
             << "4. Show Registration Type List\nEnter any other number to go back to the Dashboard\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                conference.show_final_attendee_list();
                goto show;
            }
            case 2: {
                conference.show_registration_list();
                goto show;
            }
            case 3: {
                conference.show_pending_payment_user_list();
                goto show;
            }
            /*case 4: {
                cout << "\nEnter the type of list\n";
                string r_type;
                cin >> r_type;
                for(auto &i : conference.payment_details().get_registration_type_list()){
                    cout << i.first << "\t" << i.second << "\n";
                }
                goto show;
            }*/
            default: {
                return VIEW_CHOICES(ADMIN_DASHBOARD);
            }
        }
    }
    else {
        //Error
    }
    return VIEW_CHOICES(REGISTER_DETAILS);
}
