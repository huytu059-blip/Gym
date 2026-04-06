//
// Created by FPT SHOP on 4/4/2026.
//

#ifndef GYM_PERSON_H
#define GYM_PERSON_H

class Person {
    private:
    int id;
    std::string name;
    std::string numberPhone;
    public:
    Person(int id, std::string name, std::string numberPhone) {
        this->id = id;
        this->name = name;
        this->numberPhone = numberPhone;
    };
    virtual void getId() =0;
    virtual void getName() =0;
    virtual void getNumberPhone()=0;

};

#endif //GYM_PERSON_H
