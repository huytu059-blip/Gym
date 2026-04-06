//
// Created by FPT SHOP on 4/3/2026.
//

#ifndef GYM_MEMBER_H
#define GYM_MEMBER_H
#include <string>


class PersonMember:public Person {
    std::string dateOfBirth;
    std::string gender;

    public:
    PersonMember() {
        dateOfBirth = " ";
        gender = " ";
    }
    PersonMember(int member_ID, std::string member_name, std::string member_phonenumber,std::string member_date, std::string member_gender) {
        this->id = member_ID;
        this->name = member_name;
        this->phoneNumber = member_phonenumber;
        this->dateOfBirth = member_date;
        this->gender = member_gender;

    }


   virtual std::string getDateOfBirth() { return dateOfBirth; }
   virtual std::string getGender() { return gender; }



    void setDateOfBirth(std::string date) {
        dateOfBirth = date;
    }
    void setGender(std::string gender) {
        gender = gender;
    }

};


#endif //GYM_MEMBER_H
