//
// Created by lakshya on 03/04/18.
//

#ifndef CMS_FILE_H
#define CMS_FILE_H

#include <fstream>

using namespace std;


class File {
public:
    static void read_conference_list();

    static void read_user_list();

    static void write_conference_list();

    static void write_user_list();
};


#endif //CMS_FILE_H
