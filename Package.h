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
    std::string Datecurrent;
    void displayRegistration();
    void statisticsQuanitymember(packageId);
    void seacrhPackageActive(time);
    void totalPrPackage();
    void popularyMemberDeactivated();
    void displaice(time);
    void autoUpdate();

public:
    Registration(int ID, std::string Begin, std::string End)
    :registrationId(ID), dateBegin(Begin), dateEnd(End) {}

    std::string getdateBegin() {
        return dateBegin;
    }

    std::string getdateEnd() {
        return dateEnd;
    }

    int getMemberId() {
        return memberId;
    }

    int getRegID() {
        return registrationId;
    }

    std::string getdateCurrent() {
        return Datecurrent;
    }


};


#endif //GYM_REGISTRATION_H
