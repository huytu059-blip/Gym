//
// Created by FPT SHOP on 4/3/2026.
//

#ifndef GYM_GYMMANAGER_H
#define GYM_GYMMANAGER_H
#include <iostream>
#include <string>
#include <unordered_map>

#include "Member.h"
#include "Package.h"
#include "Registration.h"
#include "Trainer.h"
#include "../View/GymView.h"

//member
/*class GymManager :public GymView {
private:
    std::unordered_map<int, Member> Members;
    std::unordered_map<int,Package> Packages;
    std::unordered_map<int, Registration> Registations;
    std::unordered_map<int, Trainer> Trainers;
public:
        void memberScreen() ;
        void DisplayAllMembers();
        void Searchmembers();
        bool addMember(const Member& m);
        bool updateMember(int id, const Member& newData);
        bool deleteMemberById(int id);
        bool extendPackage(int memberId, int extraDays);
        const std::unordered_map<int, Member>& DisplayAllmembers() ;


};*/


#define GYM_GYMMANAGER_H

#include <string>
#include <unordered_map>

#include "Member.h"
#include "Package.h"
#include "Registration.h"
#include "Trainer.h"

class GymManager {
private:
    std::unordered_map<int, Member> Members;
    std::unordered_map<int, Package> Packages;
    std::unordered_map<int, Registration> Registations;
    std::unordered_map<int, Trainer> Trainers;

public:
    // menu
    void memberScreen();

    // member functions
    const std::unordered_map<int, Member>& DisplayAllMembers() const;
    std::unordered_map<int, Member> searchMembers(const std::string& keyWord) const;

    bool addMember(const Member& m);
    bool updateMember(int id, const Member& newData);
    bool deleteMemberById(int id);
    bool extendPackage(int memberId, int extraDays);
};




#endif //GYM_GYMMANAGER_H
