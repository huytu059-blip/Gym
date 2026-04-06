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

//member
class GymManager {
private:
    std::unordered_map<int, Member> Members;
    std::unordered_map<int,Package> Packages;
    std::unordered_map<int, Registration> Reg;
    std::unordered_map<int, Trainer> Trainers;
    public:
    void Display_all_members
    (std::unordered_map<int, Member> Members, std::string keyWord);
    void Search_members
    (std::unordered_map<int, Member> Members, std::string keyWord) ;
    bool addMember(const Member& m);
    bool updateMember(int id, const Member& newData);
    bool deleteMemberById(int id);
    int deleteMemberByName(const std::string& name);
    bool extendPackage(int memberId, int extraDays);
    const std::unordered_map<int, Member>& getAllMembers() const;
};








#endif //GYM_GYMMANAGER_H
