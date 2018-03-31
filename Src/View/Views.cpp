//
// Created by Shashank Mohabia on 2/16/2018.
//

#include "Views.h"

#define system_pause {                                          \
            cout << "Press Enter to continue!\n";               \
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); \
        }

#define cin_space(var) {                                                    \
            getline(cin, var);                                              \
        }

#define cin_no_space(var) {                                                 \
            getline(cin, var);                                              \
            while((var).find(' ') != std::string::npos){                    \
                cout << "Spaces are not allowed!\nPlease enter again: ";    \
                getline(cin, var);                                          \
            }                                                               \
        }

#define cin_email(var) {                                                    \
            getline(cin,var);                                               \
            while((var).find(" ") != std::string::npos){                    \
                cout << "Spaces are not allowed!\nPlease enter again: ";    \
                getline(cin, var);                                          \
            }                                                               \
            size_t foundat = (var).find("@");                               \
            size_t founddot = (var).find(".", foundat + 1);                 \
            while(foundat == 0 || foundat == std::string::npos || founddot == std::string::npos || founddot == (var).size() - 1){ \
                cout << "Enter a valid e-mail id: ";                        \
                getline(cin,var);                                           \
            }                                                               \
        }

#define cin_int(var, len) {                                                 \
            getline(cin,var);                                               \
            while((var).find(" ") != std::string::npos){                    \
                cout << "Spaces are not allowed!\nPlease enter again: ";    \
                getline(cin, var);                                          \
            }                                                               \
            while((var).size() != (len) || ((var).find_first_not_of( "0123456789" ) != string::npos)){    \
                cout << "Enter a valid mobile number: ";                    \
                getline(cin,var);                                           \
            }                                                               \
        }


VIEW_CHOICES Views::display() {
}

VIEW_CHOICES SplashView::display() {
    cout << "Splash view" << endl;
    cout << "choose 1 option" << endl;
    int choice;
    cout << "1. Login\n2. Register\n3. Details\n4. Exit" << endl;
    cin >> choice;
    cin.ignore();
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
    cin_no_space(username);
    if (username == "$") {
        return VIEW_CHOICES(SPLASH);
    }
    cout << "Enter Password" << endl;
    cin_space(password);
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
            UserError error = UserError("The password is incorrect!");
            cout << error.print_error() << endl;
        }
    }
    else {
        UserError error = UserError("User doesn't exists!");
        cout << error.print_error() << endl;
    }
    system_pause
    return VIEW_CHOICES(LOGIN);
}

VIEW_CHOICES RegisterView::display() {
    cout << "Enter Register view" << endl;
    string firstName, lastName, username, password, rpassword, email, contact;
    string address, city, state, country, pincode;
    char gender;
    username_exists :
    cout << "Enter Username: ";
    cin_no_space(username);
    if (User::all().find(username) != User::all().end()) {
        UserError error = UserError("This Username already exists!");
        cout << error.print_error() << endl;
        goto username_exists;
    }
    /*cout << username << endl;*/
    cout << "Enter First name: ";
    cin_no_space(firstName);
    /*cout << firstName << endl;*/
    cout << "Enter Last name: ";
    cin_no_space(lastName);
    /*cout << lastName << endl;*/
    cout << "Enter Gender[M/F/O]: ";
    cin >> gender;
    cin.ignore();
    wrong_password :
    cout << "Enter Password: ";
    cin_space(password);
    cout << "Re-enter Password: ";
    cin_space(rpassword);
    if (password != rpassword) {
        UserError error = UserError("Both the passwords do not match!");
        cout << error.print_error() << endl;
        goto wrong_password;
    }
    cout << "Enter E-mail: ";
    cin_email(email);
    /*cin >> email;
    cin.ignore();*/
    cout << "Enter Mobile No.(10 Digits): ";
    cin_int(contact, 10);
    cout << "Enter Address: ";
    cin_space(address);
    cout << "Enter City: ";
    cin_space(city);
    cout << "Enter State: ";
    cin_space(state);
    cout << "Enter Country: ";
    cin_space(country);
    cout << "Enter Pincode: ";
    cin_int(pincode, 6);
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
    cin.ignore();
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
            enter_name:
            cout << "Please enter the name of the conference you want to register for from the following!\n";
            for (auto &i : Conference::conference_list()) {
                cout << i.first << "\n";
            }
            string c_name;
            cin >> c_name;
            cin.ignore();
            if (Conference::conference_list().find(c_name) != Conference::conference_list().end()) {
                enter_type :
                cout << "Select the type of registration!\n";
                for (auto &i : Conference::conference_list().find(
                        c_name)->second.payment_details().get_registration_type_list()) {
                    cout << i.first << "\t" << i.second << endl;
                }
                string c_type;
                cin >> c_type;
                cin.ignore();
                if (Conference::conference_list().find(
                        c_name)->second.payment_details().get_registration_type_list().find(c_type) !=
                    Conference::conference_list().find(
                            c_name)->second.payment_details().get_registration_type_list().end()) {
                    cout << "Do you really want to pay Rs " << Conference::conference_list().find(
                            c_name)->second.payment_details().get_registration_type_list().find(c_type)->second;
                    cout << "\nPress Y to continue.\n";
                    char flag;
                    cin >> flag;
                    cin.ignore();
                    if (flag != 'Y') {
                        cout << "You have not been registered for the conference!\n";
                    }
                    else {
                        current_user->update_registered_conference_list(c_name, c_type);
                        Conference::conference_list().find(c_name)->second.update_registration_list(
                                current_user->get_username());
                        cout << "You have been successfully registered for the conference!\n";
                    }
                }
                else {
                    UserError error = UserError("The conference type entered doesn't exist!");
                    cout << error.print_error() << endl;
                    cout << "Press Y to re-enter the conference type: ";
                    char flag;
                    cin >> flag;
                    cin.ignore();
                    if (flag == 'Y') {
                        goto enter_type;
                    }
                    else {
                        cout << "You have not been registered for the conference!\n";
                    }
                }
            }
            else {
                UserError error = UserError("The conference name entered doesn't exist!");
                cout << error.print_error() << endl;
                cout << "Press Y to re-enter the conference name: ";
                char flag;
                cin >> flag;
                cin.ignore();
                if (flag == 'Y') {
                    goto enter_name;
                }
                else {
                    cout << "You have not been registered for the conference!\n";
                }
            }
            return USER_DASHBOARD;
        }
        case 5: {
            return VIEW_CHOICES(PAYMENT);
        }
        case 6: {
            string password, new_password, re_enter_password;
            enter_password:
            cout << "Enter Previous Password: ";
            cin >> password;
            cin.ignore();
            if (current_user->get_password() == password) {
                enter_new_password:
                cout << "Enter New Password: ";
                cin >> new_password;
                cin.ignore();
                cout << "Re-enter New Password: ";
                cin >> re_enter_password;
                cin.ignore();
                if (new_password == re_enter_password) {
                    current_user->set_password(new_password);
                    current_user->save();
                }
                else {
                    UserError error = UserError("Both the passwords do not match!");
                    cout << error.print_error() << endl;
                    goto enter_new_password;
                }
            }
            else {
                UserError error = UserError("Entered password is wrong!");
                cout << error.print_error() << endl;
                goto enter_password;
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
    admin_dashboard:
    cout << "What do you want to do!" << endl;
    int choice;
    cout << "1. User Profile\n2. Conference Details\n3. Registered Data\n4. Create Conference\n"
         << "5. Update Conference Details\n6. Make Superuser\n7. Remove Superuser\n8. Remove User\n9. Logout"
         << endl;
    cin >> choice;
    cin.ignore();
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
            cout << "Enter the details of the conference you want to create!\n";
            string name, date, venue, time;
            int seats;
            cout << "Name: ";
            cin >> name;
            cin.ignore();
            cout << "Date: ";
            cin >> date;
            cin.ignore();
            cout << "Venue: ";
            cin >> venue;
            cin.ignore();
            cout << "Time: ";
            cin >> time;
            cin.ignore();
            cout << "Number of available seats: ";
            cin >> seats;
            cin.ignore();
            Conference(name, date, venue, time);
            Conference::conference_list().find(name)->second.update_seat_available(seats);
            cout << "Successfully registered for conference!\n";
        }
        case 5: {
            cout << "Please enter the name of the conference you want to update from the following!\n";
            for (auto &i : Conference::conference_list()) {
                cout << i.first << "\n";
            }
            string c_name;
            cin >> c_name;
            cin.ignore();
            if (Conference::conference_list().find(c_name) != Conference::conference_list().end()) {
                cout << "Choose the detail to edit!\n";
                cout << "1. Name\n2. Date\n3. Time\n4. Venue\n";
                int i;
                cin >> i;
                cin.ignore();
                switch (i) {
                    case 1: {
                        cout << "Enter the new name of the Conference: ";
                        string new_c_name;
                        cin >> new_c_name;
                        cin.ignore();
                        Conference::conference_list().find(c_name)->second.update_c_name(new_c_name);
                        break;
                    }
                    case 2: {
                        cout << "Enter the new date of the Conference: ";
                        string new_c_date;
                        cin >> new_c_date;
                        cin.ignore();
                        Conference::conference_list().find(c_name)->second.update_c_date(new_c_date);
                        break;
                    }
                    case 3: {
                        cout << "Enter the new time of the Conference: ";
                        string new_c_time;
                        cin >> new_c_time;
                        cin.ignore();
                        Conference::conference_list().find(c_name)->second.update_c_time(new_c_time);
                        break;
                    }
                    case 4: {
                        cout << "Enter the new venue of the Conference: ";
                        string new_c_venue;
                        cin >> new_c_venue;
                        cin.ignore();
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
        case 6: {
            cout << "Please enter the name of the user to grant superuser access: ";
            string username;
            cin >> username;
            cin.ignore();
            auto user = User::all().find(username);
            if (user != User::all().end()) {
                if (user->second.is_superuser()) {
                    UserError error("This user is already a superuser!");
                    cout << error.print_error() << endl;
                }
                else {
                    user->second.create_superuser(username);
                }
            }
            else {
                UserError error("User doesn't exists!");
                cout << error.print_error() << endl;
            }
            system_pause
            return ADMIN_DASHBOARD;
        }
        case 7: {
            cout << "Please enter the name of the user to revoke superuser access: ";
            string username;
            cin >> username;
            cin.ignore();
            auto user = User::all().find(username);
            if (user != User::all().end()) {
                if (user->second.is_superuser()) {
                    user->second.remove_superuser(username);
                    cout << "Action successful\n";
                }
                else {
                    UserError("This user is already not a superuser!");
                }
            }
            else {
                UserError("User doesn't exists");
            }
            system_pause
            if(!current_user->is_superuser()){
                return USER_DASHBOARD;
            }
            else{
                return ADMIN_DASHBOARD;
            }
        }
        case 8: {
            cout << "Please enter the name of the user to be removed: ";
            string username;
            cin >> username;
            cin.ignore();
            auto user = User::all().find(username);
            if (user != User::all().end()) {
                User::all().erase(user);
            }
            else {
                UserError error("User doesn't exists");
                cout << error.print_error() << endl;
            }
            system_pause
            if(User::all().find(current_user->get_username()) != User::all().end()){
                return ADMIN_DASHBOARD;
            }
            else{
                return SPLASH;
            }
        }
        case 9: {
            return SPLASH;
        }
        default: {
            cout << "Please select a valid option" << endl;
            goto admin_dashboard;
        }
    }
}

VIEW_CHOICES ProfileView::display() {
    current_user->show_user_details();
    system_pause
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
    system_pause
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
    c_name:
    cout << "Enter the name of conference to view registration details from the following!\n";
    for (auto &i : Conference::conference_list()) {
        cout << i.first << "\n";
    }
    string c_name;
    cin >> c_name;
    cin.ignore();
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
        cin.ignore();
        switch (choice) {
            case 1: {
                conference.show_final_attendee_list();
                system_pause
                goto show;
            }
            case 2: {
                conference.show_registration_list();
                system_pause
                goto show;
            }
            case 3: {
                conference.show_pending_payment_user_list();
                system_pause
                goto show;
            }
            case 4: {
                cout << "\nEnter the type of list\n";
                string r_type;
                cin >> r_type;
                cin.ignore();
                for (auto &i : conference.payment_details().get_registration_type_list()) {
                    cout << i.first << "\t" << i.second << "\n";
                }
                system_pause
                goto show;
            }
            default: {
                return VIEW_CHOICES(ADMIN_DASHBOARD);
            }
        }
    }
    else {
        UserError error = UserError("Please enter a valid name from the list!");
        cout << error.print_error() << endl;
        system_pause
        goto c_name;
    }
}
