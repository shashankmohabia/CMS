//
// Created by Shashank Mohabia on 2/17/2018.
//

#ifndef CMS_MENU_H
#define CMS_MENU_H


#include "Views.h"

class Menu {
private:
    static Menu* instance;
    bool EXIT_CODE;
    enum VIEW_CHOICES _view_choices;
    Views* _current_view;

public:
    Menu();

    static Menu* getInstance();

    bool exitcode();

    void display();
};

#endif //CMS_MENU_H
