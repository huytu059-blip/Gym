#ifndef GYM_TRAINER_H
#define GYM_TRAINER_H

#include <string>
#include "Person.h"

class Trainer : public Person {
private:
    std::string expertise;

public:
    // constructor mặc định
    Trainer() {
        expertise = "";
    }

    // constructor đầy đủ
    Trainer(int trainer_id,
            std::string trainer_name,
            std::string trainer_expertise,
            std::string trainer_phonenumber)
        : Person(trainer_id, trainer_name, trainer_phonenumber) // 🔥 gọi cha
    {
        expertise = trainer_expertise;
    }

    // override từ Person
    int getId() override {
        return id;
    }

    std::string getName() override {
        return name;
    }

    std::string getNumberPhone() override {
        return numberPhone;
    }

    // riêng của Trainer
    std::string getExpertise() {
        return expertise;
    }

    void setExpertise(std::string exp) {
        this->expertise = exp; // ✅ fix
    }
};

#endif
