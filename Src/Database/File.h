//
// Created by lakshya on 03/04/18.
//

#ifndef CMS_FILE_H
#define CMS_FILE_H

#include <fstream>

using namespace std;


class File {

    void read_conference_list();

    void read_user_list();

    void write_conference_list();

    void write_user_list();
};


#endif //CMS_FILE_H
