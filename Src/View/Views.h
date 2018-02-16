//
// Created by Shashank Mohabia on 2/16/2018.
//

#ifndef CMS_VIEWS_H
#define CMS_VIEWS_H

#include <iostream>

using namespace std;

enum VIEW_CHOICES {
    SPLASH,
    LOGIN,
    REGISTER,
    DETAIL,
    EXIT
};

class Views {
public:
    Views() = default;

    virtual VIEW_CHOICES display();

    virtual ~Views() = default;
};


class SplashView : public Views {
public:
    SplashView() = default;

    VIEW_CHOICES display() override;

    ~SplashView() override = default;
};

class LoginView : public Views {
public:
    LoginView() = default;

    VIEW_CHOICES display() override;

    ~LoginView() override = default;
};

class RegisterView : public Views {
public:
    RegisterView() = default;

    VIEW_CHOICES display() override;

    ~RegisterView() override = default;
};

class DetailView : public Views {
public:
    DetailView() = default;

    VIEW_CHOICES display() override;

    ~DetailView() override = default;
};


#endif //CMS_VIEWS_H
