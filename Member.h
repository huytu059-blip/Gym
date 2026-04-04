//
// Created by FPT SHOP on 4/3/2026.
//

#ifndef GYM_MEMBER_H
#define GYM_MEMBER_H


class Member: public Person {
private :
    int memberId;
    string name;
    string dateofbirth;
    string gender;
    string numberPhone;
    public :
    void getMember();
    void isActive();
    searchInfoMember();
};


#endif //GYM_MEMBER_H