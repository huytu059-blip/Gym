#ifndef GYM_MEMBER_H
#define GYM_MEMBER_H

#include <string>
#include "Person.h"

class Member : public Person {
private:
    std::string dateOfBirth;
    std::string gender;

public:
    // constructor mặc định
    Member() {
        dateOfBirth = "";
        gender = "";
    }

    // constructor đầy đủ
    Member(int member_ID,
                 std::string member_name,
                 std::string member_phonenumber,
                 std::string member_date,
                 std::string member_gender)
        : Person(member_ID, member_name, member_phonenumber) // 🔥 gọi constructor cha
    {
        dateOfBirth = member_date;
        gender = member_gender;
    }

    // override các hàm pure virtual
    int getId() override {
        return id;
    }

    std::string getName() override {
        return name;
    }

    std::string getNumberPhone() override {
        return numberPhone;
    }

    std::string getDateOfBirth() {
        return dateOfBirth;
    }

    std::string getGender() {
        return gender;
    }

    void setDateOfBirth(std::string date) {
        dateOfBirth = date;
    }

    void setGender(std::string gender) {
        this->gender = gender; // ✅ fix lỗi
    }
};

#endif
