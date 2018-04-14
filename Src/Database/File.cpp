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
    fstream file;
    file.open("user.dat", ios::out | ios::trunc | ios::binary);
    if (!file) {
        cout << "Error in creating file 'user.dat'\n";
    }
    for (auto &i : User::all()) {
        file.write((char *) &(i.second), sizeof(i.second));
    }
    file.close();
}
