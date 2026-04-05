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

// Phần của Dũng
//
// Created by Administrator on 4/5/2026.
//

#ifndef GYM_REGISTRATION_H
#define GYM_REGISTRATION_H
#include <string>
#include <iostream>
#include "Package.h"


class Registration {
private:
    std::string regId;
    std::string memberId;
    int packageId;
    std::string startDate;
    std::string endDate;
    double price;
public:
    Registration(std::string regid, std::string memId, Package p, std::string start) {
        this->regId = regid;
        this->memberId = memId;
        this->startDate = start;
        packageId = p.getPackageID();
        price = p.getPrice();
        endDate = startDate;
    }
    std::string getRegId() const {
        return this->regId;
    }
    std::string getMemberId() const {
        return this->memberId;
    }
    int getPackageId() const {
        return this->packageId;
    }
    std::string getStartDate() const {
        return this->startDate;
    }
    std::string getEndDate() const {
        return this->endDate;
    }
    double getPrice() const {
        return this->price;
    }
    bool isActive(std::string currentDate) const {
        return currentDate <= endDate;
    }
};



#endif //GYM_REGISTRATION_H
