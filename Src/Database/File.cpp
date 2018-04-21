//
// Created by lakshya on 03/04/18.
//

#include <iostream>
#include "File.h"
#include "../Conference Details/Conference.h"
#include "../Auth/User.h"

void File::read_conference_list() {
    fstream file;
    file.open("con.dat", ios::in | ios::out | ios::binary);

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
                string user_file_name = read;
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
                            }
                            case 2: {
                                user.set_last_name(read);
                            }
                            case 3: {
                                user.set_username(read);
                            }
                            case 4: {
                                user.set_password(read);
                            }
                            case 5: {
                                user.set_email(read);
                            }
                            case 6: {
                                user.set_contact(read);
                            }
                            case 7: {
                                user.set_date_of_registration(read);
                            }
                            case 8: {
                                user.set_address(read);
                            }
                            case 9: {
                                user.set_city(read);
                            }
                            case 10: {
                                user.set_state(read);
                            }
                            case 11: {
                                user.set_country(read);
                            }
                            case 12: {
                                user.set_pincode(read);
                            }
                            case 13: {
                                user.set_gender(read[0]);
                            }
                            default:
                                break;
                        }
                        /*cout << read << "\n";*/
                    }
                }
                user.save();
                user_file.close();
                string user_reg_con_list_name = user.get_username();
                user_reg_con_list_name.append("_list.txt");
                ifstream user_reg_con_list(user_reg_con_list_name);
                string read_param_1, read_param_2;
                while (getline(user_reg_con_list, read_param_1) && getline(user_reg_con_list, read_param_2)) {
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
    fstream file;
    file.open("con.dat", ios::out | ios::trunc | ios::binary);
    if (!file) {
        cout << "Error in creating file 'con.dat'\n";
    }
    for (auto &i : Conference::conference_list()) {
        file.write((char *) &(i.second), sizeof(i.second));
    }
    file.close();
}

void File::write_user_list() {
    ofstream output("user.txt");
    if (output.is_open()) {
        for (auto &i : User::all()) {
            output << i.second.get_username() << "\n";
            string user_file_name = i.second.get_username();
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
            string user_reg_con_list_name = i.second.get_username();
            user_reg_con_list_name.append("_list.txt");
            ofstream user_reg_con_list(user_reg_con_list_name);
            for (auto &it : i.second.registered_conference_list()) {
                user_reg_con_list << it.first << "\n";
                user_reg_con_list << it.second << "\n";
            }
        }
        /*cout << "File opened\n";*/
        /*output << "This is a line\n";*/
        output.close();
    }
    else {
        cout << "Unable to open file";
    }
}
