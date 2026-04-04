//
// Created by FPT SHOP on 4/3/2026.
//

#ifndef GYM_REGISTRATION_H
#define GYM_REGISTRATION_H
#include <string>


class Registration {
    int registrationId;
    string registrationDate;
    int memberId;
    int PackageId;
    string dateBegin;
    string dateEnd;
    double priceValue;
    void displayRegistration();
    void seacrhPackageActive(time);
    void statisticsQuanitymember(packageId);
    void totalPrice(time);
    void popularPackage();
    void displayMemberDeactivated();
    void autoUpdate();



};


#endif //GYM_REGISTRATION_H