//
// Created by FPT SHOP on 4/3/2026.
//

#ifndef GYM_PACKAGE_H
#define GYM_PACKAGE_H


class Package {
private:
    int packageId;
    string packageName;
    string time;
    double packagePrice;
    public:
    void registrationPackage();
    void cancelPackage();
    void extendPackage();

};


#endif //GYM_PACKAGE_H