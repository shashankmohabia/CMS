//
// Created by Shashank Mohabia on 2/7/2018.
//

#ifndef CMS_INIT_H
#define CMS_INIT_H

#include "Auth/User.h"
#include "View/Menu.h"
#include "Conference Details/Conference.h"
#include "Registration/Payment.h"


class Init {
    static Init* instance;
public:

    static Init *getInstance();

    Init();

    void start();
};


#endif //CMS_INIT_H
