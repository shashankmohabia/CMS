//
// Created by Shashank Mohabia on 2/16/2018.
//

#ifndef CMS_VIEWS_H
#define CMS_VIEWS_H

#include <iostream>
#include <ctime>
#include <chrono>
#include "../Auth/User.h"
#include "../Conference Details/Conference.h"
#include "../Registration/Payment.h"

using namespace std;

enum VIEW_CHOICES {
    SPLASH,
    LOGIN,
    REGISTER,
    DETAIL,
    USER_DASHBOARD,
    ADMIN_DASHBOARD,
    PROFILE,
    PAYMENT,
    REGISTER_DETAILS,
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

class ConferenceDetailView : public Views {
public:
    ConferenceDetailView() = default;

    VIEW_CHOICES display() override;

    ~ConferenceDetailView() override = default;
};

class ConferenceEditView : public Views {
public:
    ConferenceEditView() = default;

    VIEW_CHOICES display() override;

    ~ConferenceEditView() override = default;
};

class ConferenceCreateView : public Views {
public:
    ConferenceCreateView() = default;

    VIEW_CHOICES display() override;

    ~ConferenceCreateView() override = default;
};

class UserDashboardView : public Views {
public:
    UserDashboardView() = default;

    VIEW_CHOICES display() override;

    ~UserDashboardView() override = default;
};

class AdminDashboardView : public Views {
public:
    AdminDashboardView() = default;

    VIEW_CHOICES display() override;

    ~AdminDashboardView() override = default;
};

class ProfileView : public Views {
public:
    ProfileView() = default;

    VIEW_CHOICES display() override;

    ~ProfileView() override = default;
};

class ProfileUpdateView : public Views {
public:
    ProfileUpdateView() = default;

    VIEW_CHOICES display() override;

    ~ProfileUpdateView() override = default;
};

class PaymentView : public Views {
public:
    PaymentView() = default;

    VIEW_CHOICES display() override;

    ~PaymentView() override = default;
};

class RegisterDetailView : public Views {
public:
    RegisterDetailView() = default;

    VIEW_CHOICES display() override;

    ~RegisterDetailView() override = default;
};

class RegisterDetailEditView : public Views {
public:
    RegisterDetailEditView() = default;

    VIEW_CHOICES display() override;

    ~RegisterDetailEditView() override = default;
};

#endif //CMS_VIEWS_H
