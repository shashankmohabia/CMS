//
// Created by lakshya on 03/04/18.
//

#include <iostream>
#include <chrono>
#include "File.h"
#include "../Conference Details/Conference.h"
#include "../Auth/User.h"

void File::read_conference_list() {
    ifstream input("conference.txt");
    string read;
    if (input.is_open()) {
        while (getline(input, read)) {
            if (read.empty()) {
                cout << "Gotcha!" << "\n";
            }
            else {
                string con_file_name = "Conference/";
                con_file_name.append(read);
                con_file_name.append(".txt");
                ifstream con_file(con_file_name);
                Conference conference;
                int count = 0;
                while (getline(con_file, read)) {
                    if (read.empty()) {
                        cout << "Gotcha!" << "\n";
                    }
                    else {
                        switch (count++) {
                            case 0: {
                                conference.update_c_name(read);
                                break;
                            }
                            case 1: {
                                conference.update_c_date(read);
                                break;
                            }
                            case 2: {
                                conference.update_c_time(read);
                                break;
                            }
                            case 3: {
                                conference.update_c_venue(read);
                                break;
                            }
                            case 4: {
                                conference.update_seat_available(stoi(read));
                                break;
                            }
                            default:
                                break;
                        }
                    }
                }
                con_file.close();
                string registration_list_name = "Conference/Registration_List/";
                registration_list_name.append(conference.get_c_name());
                registration_list_name.append(".txt");
                ifstream registration_list(registration_list_name);
                while (getline(registration_list, read)) {
                    Conference::conference_list().find(
                            conference.get_c_name())->second.get_registration_list().push_back(read);
                }
                registration_list.close();
                string payment_done_list_name = "Conference/Payment_Done_List/";
                payment_done_list_name.append(conference.get_c_name());
                payment_done_list_name.append(".txt");
                ifstream payment_done_list(payment_done_list_name);
                while (getline(registration_list, read)) {
                    Conference::conference_list().find(
                            conference.get_c_name())->second.get_payment_done_list().push_back(read);
                }
                payment_done_list.close();
                string payment_file_name = "Conference/Payment/";
                payment_file_name.append(conference.get_c_name());
                payment_file_name.append(".txt");
                ifstream payment_file(payment_file_name);
                string read_param_1, read_param_2;
                while (getline(payment_file, read_param_1) && getline(payment_file, read_param_2)) {
                    Conference::conference_list().find(
                            conference.get_c_name())->second.payment_details().add_registration_type(read_param_1,
                                                                                                     stoi(read_param_2));
                }
                payment_file.close();
            }
        }
        input.close();
    }
    else {
        cout << "Unable to open file";
    }
}

void File::read_user_list() {
    ifstream input("user.txt");
    string read;
    if (input.is_open()) {
        while (getline(input, read)) {
            if (read.empty()) {
                cout << "Gotcha!" << "\n";
            }
            else {
                /*cout << read << '\n';*/
                string user_file_name = "User/";
                user_file_name.append(read);
                user_file_name.append(".txt");
                ifstream user_file(user_file_name);
                User user;
                int count = 0;
                while (getline(user_file, read)) {
                    if (read.empty()) {
                        cout << "Gotcha!" << "\n";
                    }
                    else {
                        switch (count++) {
                            case 0: {
                                if (read == "1") {
                                    user.create_superuser();
                                }
                                break;
                            }
                            case 1: {
                                user.set_first_name(read);
                                break;
                            }
                            case 2: {
                                user.set_last_name(read);
                                break;
                            }
                            case 3: {
                                user.set_username(read);
                                break;
                            }
                            case 4: {
                                user.set_password(read);
                                break;
                            }
                            case 5: {
                                user.set_email(read);
                                break;
                            }
                            case 6: {
                                user.set_contact(read);
                                break;
                            }
                            case 7: {
                                user.set_date_of_registration(read);
                                break;
                            }
                            case 8: {
                                user.set_address(read);
                                break;
                            }
                            case 9: {
                                user.set_city(read);
                                break;
                            }
                            case 10: {
                                user.set_state(read);
                                break;
                            }
                            case 11: {
                                user.set_country(read);
                                break;
                            }
                            case 12: {
                                user.set_pincode(read);
                                break;
                            }
                            case 13: {
                                user.set_gender(read[0]);
                                break;
                            }
                            default:
                                break;
                        }
                        /*cout << read << "\n";*/
                    }
                }
                user.save();
                user_file.close();
                string user_reg_con_list_name = "User/lists/";
                user_reg_con_list_name.append(user.get_username());
                user_reg_con_list_name.append(".txt");
                ifstream user_reg_con_list(user_reg_con_list_name);
                string read_param_1, read_param_2;
                while (getline(user_reg_con_list, read_param_1) && getline(user_reg_con_list, read_param_2)) {
                    /*cout << read_param_1 << endl << read_param_2 << endl;*/
                    User::all().find(user.get_username())->second.update_registered_conference_list(
                            read_param_1, read_param_2);
                }
                user_reg_con_list.close();
            }
        }
        input.close();
    }
    else {
        cout << "Unable to open file";
    }
}

void File::write_conference_list() {
    ofstream output("conference.txt");
    if (output.is_open()) {
        for (auto &i : Conference::conference_list()) {
            output << i.second.get_c_name() << "\n";
            string con_file_name = "Conference/";
            con_file_name.append(i.second.get_c_name());
            con_file_name.append(".txt");
            ofstream con_file(con_file_name);
            con_file << i.second.get_c_name() << "\n";
            con_file << i.second.get_c_date() << "\n";
            con_file << i.second.get_c_time() << "\n";
            con_file << i.second.get_c_venue() << "\n";
            con_file << i.second.get_seats_available() << "\n";
            con_file.close();
            string registration_list_name = "Conference/Registration_List/";
            registration_list_name.append(i.second.get_c_name());
            registration_list_name.append(".txt");
            ofstream registration_list(registration_list_name);
            for (auto &it : i.second.get_registration_list()) {
                registration_list << it << "\n";
            }
            registration_list.close();
            string payment_done_list_name = "Conference/Payment_Done_List/";
            payment_done_list_name.append(i.second.get_c_name());
            payment_done_list_name.append(".txt");
            ofstream payment_done_list(payment_done_list_name);
            for (auto &it : i.second.get_payment_done_list()) {
                payment_done_list << it << "\n";
            }
            payment_done_list.close();
            string payment_file_name = "Conference/Payment/";
            payment_file_name.append(i.second.get_c_name());
            payment_file_name.append(".txt");
            ofstream payment_file(payment_file_name);
            for (auto &it : i.second.payment_details().get_registration_type_list()) {
                payment_file << it.first << "\n";
                payment_file << it.second << "\n";
            }
            payment_file.close();
        }
    }
    else {
        cout << "Unable to open file";
    }
}

void File::write_user_list() {
    ofstream output("user.txt");
    if (output.is_open()) {
        for (auto &i : User::all()) {
            output << i.second.get_username() << "\n";
            string user_file_name = "User/";
            user_file_name.append(i.second.get_username());
            /*string user_file_name = i.second.get_username();*/
            user_file_name.append(".txt");
            ofstream user_file(user_file_name);
            user_file << i.second.is_superuser() << "\n";
            user_file << i.second.get_first_name() << "\n";
            user_file << i.second.get_last_name() << "\n";
            user_file << i.second.get_username() << "\n";
            user_file << i.second.get_password() << "\n";
            user_file << i.second.get_email() << "\n";
            user_file << i.second.get_contact() << "\n";
            user_file << i.second.get_date_of_registration() << "\n";
            user_file << i.second.get_address() << "\n";
            user_file << i.second.get_city() << "\n";
            user_file << i.second.get_state() << "\n";
            user_file << i.second.get_country() << "\n";
            user_file << i.second.get_pincode() << "\n";
            user_file << i.second.get_gender() << "\n";
            user_file.close();
            string user_reg_con_list_name = "User/lists/";
            user_reg_con_list_name.append(i.second.get_username());
            user_reg_con_list_name.append(".txt");
            ofstream user_reg_con_list(user_reg_con_list_name);
            for (auto &it : i.second.registered_conference_list()) {
                user_reg_con_list << it.first << "\n";
                user_reg_con_list << it.second << "\n";
            }
            user_reg_con_list.close();
        }
        /*cout << "File opened\n";*/
        /*output << "This is a line\n";*/
        output.close();
    }
    else {
        cout << "Unable to open file";
    }
}
