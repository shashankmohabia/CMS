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
    fstream file;
    file.open("user.dat", ios::in | ios::out | ios::binary);

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
        /*for (auto &i : User::all()) {
            output << i.second.get_username() << "\n";
            ofstream user_file(i.second.get_username());
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
            ofstream user_reg_con_list(i.second.get_username().c_str() + '_list');
            for (auto &it : i.second.registered_conference_list()){
                user_reg_con_list << it.first << "\n";
                user_reg_con_list << it.second << "\n";
            }
        }*/
        output << "This is a line\n";
        output.close();
    }
    else {
        cout << "Unable to open file";
    }
}
