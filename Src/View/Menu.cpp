//
// Created by Shashank Mohabia on 2/17/2018.
//

#include "Menu.h"

Menu* Menu::instance = nullptr;

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
            _current_view = new ConferenceDetailView;
            break;
        }
        case USER_DASHBOARD: {
            _current_view = new UserDashboardView;
            break;
        }
        case ADMIN_DASHBOARD: {
            _current_view = new AdminDashboardView;
            break;
        }
        case PROFILE: {
            _current_view = new ProfileView;
            break;
        }
        case PAYMENT: {
            _current_view = new PaymentView;
            break;
        }
        case REGISTER_DETAILS: {
            _current_view = new RegisterDetailView;
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

Menu *Menu::getInstance() {
    if(instance == nullptr){
        instance = new Menu;
        return instance;
    }
    return instance;
}
