//
// Created by Shashank Mohabia on 2/16/2018.
//

#include "Views.h"


VIEW_CHOICES Views::display() {
}

VIEW_CHOICES SplashView::display() {
    cout << "Splash view" << endl;
    cout << "choose 1 option" << endl;
    int choice;
    cout << "1. Login\n2. Register\n3. Details\n4. Exit" << endl;
    cin >> choice;
    switch (choice) {
        case 1: {
            return VIEW_CHOICES(LOGIN);
        }
        case 2: {
            return VIEW_CHOICES(REGISTER);
        }
        case 3: {
            return VIEW_CHOICES(DETAIL);
        }
        case 4: {
            return VIEW_CHOICES(EXIT);
        }
        default: {
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}


VIEW_CHOICES LoginView::display() {
    cout << "Login view" << endl;
    return VIEW_CHOICES(EXIT);
}

VIEW_CHOICES RegisterView::display() {
    cout << "Register view" << endl;
    return VIEW_CHOICES(EXIT);
}

VIEW_CHOICES DetailView::display() {
    cout << "Detail view" << endl;
    return VIEW_CHOICES(EXIT);
}

