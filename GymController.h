//
// Created by FPT SHOP on 4/3/2026.
//

#ifndef GYM_GYMCONTROLLER_H
#define GYM_GYMCONTROLLER_H
#include <unordered_map>
#include "../Model/Member.h"
#include "../Model/Package.h"
#include "../Model/Registration.h"
#include "../Model/Trainer.h"
#include <string>
#include <iostream>
#include <vector>
#include "Controller/Exceptions.h"
class GymController {
    std::unordered_map<int, Member> Members;
    std::unordered_map<int,Package> Packages;
    std::unordered_map<int, Registration> Reg;
    std::unordered_map<int, Trainer> Trainers;
public:
    bool isActive(std::string end, std::string current) {
        return (current < end);
    }

    void listActiveMembers(std::string& currentDate) {
        std::cout << "Danh Sach Nguoi Con Han Goi Tap\n";
        for (auto it = Reg.begin(); it != Reg.end(); it++) {
            Registration reg = it->second;

            if (isActive(reg.getdateEnd(), currentDate)) {
                int ID = reg.getMemberId();

                if (Members.find(ID) == Members.end()) {
                    throw NotFoundException();
                }
                std::cout << "ID: " << Members.at(ID).getMemberId();
                std::cout <<" - Name: " << Members.at(ID).getName();
            }
        }
    }
};

    void searchMember(std::unordered_map<int, Member> Members, std::string keyWord) {
        for (auto it = Members.begin(); it != Members.end(); it++) {
            Member temp = it->second;
            if (temp.getName() == keyWord ||
                temp.getNumberPhone() == keyWord) {
                std::cout << "ID: " << temp.getMemberId() << std::endl;
                std::cout << "Name: " << temp.getName() << std::endl;
                std::cout << "Number Phone: " << temp.getNumberPhone() << std::endl;
            }
        }
    }


#endif //GYM_GYMCONTROLLER_H
