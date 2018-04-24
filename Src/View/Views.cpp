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
            size_t founddot = (var).find(".", foundat + 2);                 \
            while(foundat == 0 || foundat == std::string::npos || founddot == std::string::npos || founddot == (var).size() - 1){ \
                cout << "Enter a valid e-mail id: ";                        \
                getline(cin,var);                                           \
                foundat = (var).find("@");                                  \
                founddot = (var).find(".", foundat + 2);                    \
            }                                                               \
        }

#define cin_int(var, len, name) {                                           \
            getline(cin,var);                                               \
            while((var).find(" ") != std::string::npos || (var).size() != (len) || ((var).find_first_not_of( "0123456789" ) != string::npos)){                    \
                if((var).size() != (len) || ((var).find_first_not_of( "0123456789" ) != string::npos)){ \
                    cout << "Enter a valid " << name << ": ";               \
                    getline(cin,var);                                       \
                }                                                           \
                else{                                                       \
                    cout << "Spaces are not allowed!\nPlease enter again: ";    \
                    getline(cin, var);                                          \
                }                                                           \
            }                                                               \
        }

#define cin_no_int(var, name) {                                             \
            getline(cin,var);                                               \
            while(((var).find_first_not_of( "0123456789" ) == string::npos)){    \
                cout << "Enter a valid " << (name) << ": ";                   \
                getline(cin,var);                                           \
            }                                                               \
        }

#define cin_date(var) {                                                 \
            cin_int(var, 6, "date");                                                \
            while((var).size() != 6 || stoi((var).substr(2,2)) <= 0 || stoi((var).substr(2,2)) > 12 || stoi((var).substr(0,2)) <= 0 || stoi((var).substr(0,2)) > 31){    \
                cout << "Enter a valid date in the specified format";   \
                cin_int(var, 6, "date");                                                \
            }   \
        }

#define cin_time(var) {                                                 \
            cin_int(var, 4, "time");                                                \
            while((var).size() != 4 || stoi((var).substr(2,2)) < 0 || stoi((var).substr(2,2)) > 59 || stoi((var).substr(0,2)) < 0 || stoi((var).substr(0,2)) > 23){    \
                cout << "Enter a valid time in the specified format";   \
                cin_int(var, 4, "time");                                                \
            }   \
        }

#define cin_no_int_no_space(var, name) {                                        \
            getline(cin,var);                                                   \
            while((var).find(" ") != std::string::npos || ((var).find_first_not_of( "0123456789" ) == string::npos)){   \
                if(((var).find_first_not_of( "0123456789" ) == string::npos)){  \
                    cout << "Enter a valid " << (name) << ": ";                   \
                    getline(cin,var);                                           \
                }                                                               \
                else{                                                           \
                    cout << "Spaces are not allowed!\nPlease enter again: ";    \
                    getline(cin, var);                                          \
                }                                                               \
            }                                                                   \
        }


VIEW_CHOICES Views::display() {
}

VIEW_CHOICES SplashView::display() {
    cout << "Splash view" << endl;
    cout << "choose 1 option" << endl;
    string input;
    int choice;
    cout << "1. Login\n2. Register\n3. Details\n4. Exit" << endl;
    cin_space(input);
    if (input != "1" && input != "2" && input != "3" && input != "4") {
        choice = 0;
    }
    else {
        choice = stoi(input);
    }
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
            cout << "Please select a valid option!" << endl;
            system_pause
            return VIEW_CHOICES(SPLASH);
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
    string gender;
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
    cin_no_int(firstName, "first name");
    /*cout << firstName << endl;*/
    cout << "Enter Last name: ";
    cin_no_int(lastName, "last name");
    /*cout << lastName << endl;*/
    wrong_gender:
    cout << "Enter Gender[M/F/O]: ";
    cin_space(gender);
    if ((gender[0] != 'M' && gender[0] != 'F' && gender[0] != 'O' && gender[0] != 'm' && gender[0] != 'f' &&
         gender[0] != 'o') || gender.size() != 1) {
        UserError error("Please enter from given options only!");
        cout << error.print_error() << endl;
        goto wrong_gender;
    }
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
    if (password.size() < 6) {
        UserError error = UserError("The password is too small! Please enter a password of atleast 6 digits.");
        cout << error.print_error() << endl;
        goto wrong_password;
    }
    cout << "Enter E-mail: ";
    cin_email(email);
    /*cin >> email;
    cin.ignore();*/
    cout << "Enter Mobile No.(10 Digits): ";
    cin_int(contact, 10, "mobile number");
    cout << "Enter Address: ";
    cin_space(address);
    cout << "Enter City: ";
    cin_no_int(city, "city name");
    cout << "Enter State: ";
    cin_no_int(state, "state name");
    cout << "Enter Country: ";
    cin_no_int(country, "country name");
    cout << "Enter Pincode: ";
    cin_int(pincode, 6, "pincode");
    auto dor = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    User user(firstName, lastName, username, password, email, contact, std::ctime(&dor), address,
              city, state, country, pincode, gender[0]);
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
            << "1. Registered Conferences\n2. User Profile\n3. All Conference Details\n4. Register for a Conference\n5. Make Payment\n6. Change Password\n7. Logout"
            << endl;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1: {
            current_user->show_registered_conference_list();
            system_pause
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
                cout << i.first << "\t" << i.second.get_seats_available() << "\n";
            }
            string c_name;
            cin_space(c_name);
            if (Conference::conference_list().find(c_name) != Conference::conference_list().end()) {
                auto conference = Conference::conference_list().find(c_name)->second;
                time_t curr_date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                struct std::tm a = {0, stoi(conference.get_c_time().substr(2, 2)),
                                    stoi(conference.get_c_time().substr(0, 2)),
                                    stoi(conference.get_c_date().substr(0, 2)),
                                    stoi(conference.get_c_date().substr(2, 2)) - 1,
                                    stoi(conference.get_c_date().substr(4, 2)) + 100};
                time_t conf_date = mktime(&a);
                if (curr_date != (std::time_t) (-1) && conf_date != (std::time_t) (-1)) {
                    auto difference = static_cast<int>(std::difftime(conf_date, curr_date) / (60 * 60 * 24));
                    if (difference < 7) {
                        cout << "The registrations are closed for this conference\n";
                        system_pause
                        if (current_user->is_superuser()) {
                            return ADMIN_DASHBOARD;
                        }
                        else {
                            return USER_DASHBOARD;
                        }
                    }
                }
                if (Conference::conference_list().find(c_name)->second.get_seats_available() == 0) {
                    cout << "The registrations are closed for this confernce\n";
                    system_pause
                    if (current_user->is_superuser()) {
                        return ADMIN_DASHBOARD;
                    }
                    else {
                        return USER_DASHBOARD;
                    }
                }
                if (Conference::conference_list().find(c_name)->second.get_user_registration_status(
                        current_user->get_username())) {
                    cout << "You are already registered for this conference\n";
                    system_pause
                    if (current_user->is_superuser()) {
                        return ADMIN_DASHBOARD;
                    }
                    else {
                        return USER_DASHBOARD;
                    }
                }
                enter_type :
                auto rt_list = Conference::conference_list().find(
                        c_name)->second.payment_details().get_registration_type_list();
                cout << "Select the type of registration!\n";
                for (auto &i : rt_list) {
                    cout << i.first << "\t" << i.second << endl;
                }
                string c_type;
                cin_space(c_type);
                cout << c_type << "\n";
                bool check = false;
                for (auto &i : rt_list) {
                    if (i.first == c_type) {
                        check = true;
                        break;
                    }
                }
                if (check) {
                    cout << "Do you really want to register!";
                    cout << "\nPress Y to continue.\n";
                    char flag;
                    cin >> flag;
                    cin.ignore();
                    if (flag != 'Y') {
                        cout << "You have not been registered for the conference!\n";
                    }
                    else {
                        User::all().find(current_user->get_username())->second.update_registered_conference_list(c_name,
                                                                                                                 c_type);
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
            system_pause
            if (current_user->is_superuser()) {
                return ADMIN_DASHBOARD;
            }
            else {
                return USER_DASHBOARD;
            }
        }
        case 5: {
            return VIEW_CHOICES(PAYMENT);
        }
        case 6: {
            string password, new_password, re_enter_password;
            enter_password:
            cout << "Enter Previous Password: ";
            cin_space(password);
            if (current_user->get_password() == password) {
                enter_new_password:
                cout << "Enter New Password: ";
                cin_space(new_password);
                cout << "Re-enter New Password: ";
                cin_space(re_enter_password);
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
            current_user = nullptr;
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
            wrong_conference_name:
            cout << "Name: ";
            cin_space(name);
            if (Conference::conference_list().find(name) != Conference::conference_list().end()) {
                cout << "Please enter a unique name for conference. The name is already taken!\n";
                goto wrong_conference_name;
            }
            cout << "Date(DDMMYY): ";
            cin_date(date);
            cout << "Venue: ";
            cin_space(venue);
            cout << "Time(hhmm): ";
            cin_time(time);
            wrong_seats:
            cout << "Number of available seats: ";
            cin >> seats;
            cin.ignore();
            if (seats < 0) {
                cout << "Enter a non-negative integer\n";
                system_pause
                goto wrong_seats;
            }
            Conference(name, date, venue, time);
            Conference::conference_list().find(name)->second.update_seat_available(seats);
            string s = "Hi";
            while (s != "$") {
                string type;
                wrong_type:
                cout << "Enter the type of conference";
                cin_space(type);
                if (type.empty()) {
                    cout << "Please enter a valid type";
                    goto wrong_type;
                }
                cout << "Enter the amount for this type";
                int amount;
                cin >> amount;
                cin.ignore();
                Conference::conference_list().find(name)->second.payment_details().add_registration_type(type, amount);
                cout << "Press $ to exit or any other key to continue";
                cin_space(s);
            }
            cout << "Conference successfully created!\n";
            goto admin_dashboard;
        }
        case 5: {
            cout << "Please enter the name of the conference you want to update from the following!\n";
            wrong_c_name:
            for (auto &i : Conference::conference_list()) {
                cout << i.first << "\n";
            }
            string c_name;
            cin_space(c_name);
            if (Conference::conference_list().find(c_name) != Conference::conference_list().end()) {
                cout << "Choose the detail to edit!\n";
                cout << "1. Name\n2. Date\n3. Time\n4. Venue\nAny other number to go back to admin dashboard";
                int i;
                cin >> i;
                cin.ignore();
                switch (i) {
                    case 1: {
                        cout << "Enter the new name of the Conference: ";
                        string new_c_name;
                        cin_space(c_name);
                        Conference::conference_list().find(c_name)->second.update_c_name(new_c_name);
                        Conference::conference_list().insert(pair<string, Conference>(new_c_name,
                                                                                      Conference::conference_list().find(
                                                                                              c_name)->second));
                        Conference::conference_list().erase(c_name);
                        break;
                    }
                    case 2: {
                        cout << "Enter the new date of the Conference: ";
                        string new_c_date;
                        cin_date(new_c_date);
                        Conference::conference_list().find(c_name)->second.update_c_date(new_c_date);
                        break;
                    }
                    case 3: {
                        cout << "Enter the new time of the Conference: ";
                        string new_c_time;
                        cin_time(new_c_time);
                        Conference::conference_list().find(c_name)->second.update_c_time(new_c_time);
                        break;
                    }
                    case 4: {
                        cout << "Enter the new venue of the Conference: ";
                        string new_c_venue;
                        cin_space(new_c_venue);
                        Conference::conference_list().find(c_name)->second.update_c_venue(new_c_venue);
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
            else {
                cout << "Please enter a valid conference name from the following!\n";
                goto wrong_c_name;
            }
            goto admin_dashboard;
        }
        case 6: {
            wrong_username_grant:
            cout << "Enter the name of the user to grant superuser access or enter $ to go back to dashboard: ";
            string username;
            cin_no_space(username);
            if (username == "$") {
                return ADMIN_DASHBOARD;
            }
            auto user = User::all().find(username);
            if (user != User::all().end()) {
                if (user->second.is_superuser()) {
                    UserError error("This user is already a superuser!");
                    cout << error.print_error() << endl;
                    goto wrong_username_grant;
                }
                else {
                    user->second.create_superuser(username);
                }
            }
            else {
                UserError error("User doesn't exists!");
                cout << error.print_error() << endl;
                goto wrong_username_grant;
            }
            system_pause
            return ADMIN_DASHBOARD;
        }
        case 7: {
            wrong_username_revoke:
            cout << "Enter the name of the user to revoke superuser access or enter $ to go back to dashboard: ";
            string username;
            cin_no_space(username);
            if (username == "$") {
                return ADMIN_DASHBOARD;
            }
            auto user = User::all().find(username);
            if (user != User::all().end()) {
                if (user->second.is_superuser()) {
                    user->second.remove_superuser(username);
                    cout << "Action successful\n";
                }
                else {
                    UserError error("This user is already not a superuser!");
                    cout << error.print_error() << endl;
                    goto wrong_username_revoke;
                }
            }
            else {
                UserError error("User doesn't exists!");
                cout << error.print_error() << endl;
                goto wrong_username_revoke;
            }
            system_pause
            if (!current_user->is_superuser()) {
                return USER_DASHBOARD;
            }
            else {
                return ADMIN_DASHBOARD;
            }
        }
        case 8: {
            wrong_username_remove:
            cout << "Please enter the name of the user to be removed: ";
            string username;
            cin_no_space(username);
            auto user = User::all().find(username);
            if (user != User::all().end()) {
                User::all().erase(user);
            }
            else {
                UserError error("User doesn't exists");
                cout << error.print_error() << endl;
                goto wrong_username_remove;
            }
            system_pause
            if (User::all().find(current_user->get_username()) != User::all().end()) {
                return ADMIN_DASHBOARD;
            }
            else {
                return SPLASH;
            }
        }
        case 9: {
            current_user = nullptr;
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
    system_pause
    if (current_user->is_superuser()) {
        return ADMIN_DASHBOARD;
    }
    else {
        return USER_DASHBOARD;
    }

}

VIEW_CHOICES ConferenceDetailView::display() {
    cout << "Conference Detail View\n\n";
    for (auto &it : Conference::conference_list()) {
        auto conference = it.second;
        struct std::tm a = {0, stoi(conference.get_c_time().substr(2, 2)),
                            stoi(conference.get_c_time().substr(0, 2)),
                            stoi(conference.get_c_date().substr(0, 2)),
                            stoi(conference.get_c_date().substr(2, 2)) - 1,
                            stoi(conference.get_c_date().substr(4, 2)) + 100};
        time_t conf_date = mktime(&a);
        cout << "Name: \t\t\t\t\t\t" << conference.get_c_name() << endl;
        cout << "Date and Time: \t\t\t\t" << ctime(&conf_date);
        cout << "Venue: \t\t\t\t\t\t" << conference.get_c_venue() << endl;
        cout << "Current Seat Availability: \t" << conference.get_seats_available() << endl;
        cout << "Types\t";
        for (auto &i : Conference::conference_list().find(
                conference.get_c_name())->second.payment_details().get_registration_type_list()) {
            cout << i.first << "\t";
        }
        cout << "\nAmount\t";
        for (auto &i : Conference::conference_list().find(
                conference.get_c_name())->second.payment_details().get_registration_type_list()) {
            cout << i.second << "\t";
        }
        cout << "\n\n";
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
        cout << "\n\nAccess Denied\n\n";
        return VIEW_CHOICES(USER_DASHBOARD);
    }
    cout << "Registration Detail View\n\n";
    c_name:
    cout << "Enter the name of conference to view registration details from the following!\n";
    for (auto &i : Conference::conference_list()) {
        cout << i.first << "\n";
    }
    string c_name;
    cin_space(c_name);
    if (Conference::conference_list().find(c_name) != Conference::conference_list().end()) {
        auto conference = Conference::conference_list().find(c_name)->second;
        if (conference.give_total_number_of_registrations() != 0) {
            cout << "Total Number of Registrations = " << conference.give_total_number_of_registrations() << endl;
        }
        else {
            cout << "No registrations\n";
        }
        if (conference.give_total_number_of_pending_registrations() != 0) {
            cout << "Total Number of Pending Registrations = "
                 << conference.give_total_number_of_pending_registrations() << endl;
        }
        else {
            cout << "No pending registrations\n";
        }
        if (conference.give_total_number_of_attendees() != 0) {
            cout << "Total Number of Authorized Registrations = " << conference.give_total_number_of_attendees()
                 << endl;
        }
        else {
            cout << "No authorized registrations\n";
        }
        cout << "\nChoose any one of the options\n";
        show:
        cout << "1. Show Final Attendee List\n2. Show Registered User List\n3. Show Pending Payment User List\n"
             << "\nEnter any other number to go back to the Dashboard\n";
        string input;
        cin_space(input);
        if (input[0] != '1' && input[0] != '2' && input[0] != '3') {
            input = "0";
        }
        switch (stoi(input)) {
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