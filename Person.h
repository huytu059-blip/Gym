//
// Created by FPT SHOP on 4/4/2026.
//

#ifndef GYM_PERSON_H
#define GYM_PERSON_H

class Person {
private:
    int id;
    std::string name;
    std::string PhoneNumber;
public:

    Person() {
        int id = 0;
        std::string name = "";
        std::string PhoneNumber = "";

    }
    Person(int id, std::string name, std::string PhoneNumber) {
        this->id = id;
        this->name = name;
        this->PhoneNumber = PhoneNumber;
    };

    int getId() { return id; }
    std::string getName() { return name; }
    std::string getPhoneNumber() { return PhoneNumber; }

    void setId(int id) { this->id = id; }
    void setName(std::string name) { this->name = name; }
    void setPhoneNumber(std::string PhoneNumber) { this->PhoneNumber = PhoneNumber; }

};


#endif //GYM_PERSON_H
