//
// Created by FPT SHOP on 4/4/2026.
//

#ifndef GYM_PERSON_H
#define GYM_PERSON_H

class Person {
private:
    int id;
    std::string name;
    std::string phoneNumber;
public:

    Person() {
        int id = 0;
        std::string name = "";
        std::string phoneNumber = "";

    }
    Person(int id, std::string name, std::string phoneNumber) {
        this->id = id;
        this->name = name;
        this->phoneNumber = phoneNumber;
    };

    virtual int getId() { return id; }
    virtual std::string getName() { return name; }
    virtual std::string getPhoneNumber() { return phoneNumber; }

    void setId(int id) { this->id = id; }
    void setName(std::string name) { this->name = name; }
    void setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }

};


#endif //GYM_PERSON_H
