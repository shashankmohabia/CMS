//
// Created by Shashank Mohabia on 2/17/2018.
//

#include "Menu.h"

Menu::Menu() {
    EXIT_CODE = false;
    _view_choices = SPLASH;
    _current_view = new Views;
}

bool Menu::exitcode() {
    return EXIT_CODE;
}


void Menu::display() {
    delete(_current_view);
    switch (_view_choices) {
        case SPLASH: {
            _current_view = new SplashView;
            break;
        }
        case LOGIN: {
            _current_view = new LoginView;
            break;
        }
        case REGISTER: {
            _current_view = new RegisterView;
            break;
        }
        case DETAIL: {
            _current_view = new DetailView;
            break;
        }
        case EXIT: {
            EXIT_CODE = true;
            return;
        }
        default: {
            cout << "Invalid selection" << endl;
            break;
        }
    }

    _view_choices = _current_view->display();
}