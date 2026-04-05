//
// Created by FPT SHOP on 4/3/2026.
//

#ifndef GYM_MEMBER_H
#define GYM_MEMBER_H
#include <string>


class Member: public Person {
private :
    int memberId;
    string name;
    string dateofbirth;
    string gender;
    std::string numberPhone;
    public :
    void getMember();
    void isActive();
    searchInfoMember();
public:
    Member(int ID, std::string Name)
    : memberId(ID), name(Name) {}

    int getMemberId() {
        return memberId;
    }

    std::string getName() {
        return name;
    }

    std::string getNumberPhone() {
        return numberPhone;
    }
};


#endif //GYM_MEMBER_H
