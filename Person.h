#ifndef GYM_PERSON_H
#define GYM_PERSON_H

#include <string>

class Person {
protected: // 🔥 đổi từ private → protected
    int id;
    std::string name;
    std::string numberPhone;

public:
    Person() {}

    Person(int id, std::string name, std::string numberPhone) {
        this->id = id;
        this->name = name;
        this->numberPhone = numberPhone;
    }

    // virtual destructor (chuẩn OOP)
    virtual ~Person() {}

    // getter (pure virtual)
    virtual int getId() = 0;
    virtual std::string getName() = 0;
    virtual std::string getNumberPhone() = 0;
};

#endif
