//
// Created by FPT SHOP on 4/3/2026.
//

#ifndef GYM_TRAINER_H
#define GYM_TRAINER_H

class Trainer:public Person {
    private:
    std::string trainer_expertise;
    public:
    Trainer() {

        trainer_expertise = " ";

    }
    Trainer(int trainer_id, std::string trainer_name, std::string trainer_expertise, std::string trainer_phonenumber) {
        this->id = trainer_id;
        this->name = trainer_name;
        this->trainer_expertise = trainer_expertise;
        this->phoneNumber = trainer_phonenumber;

    }

   virtual std::string get_trainer_expertise() {return trainer_expertise;}

    void set_trainer_expertise(std::string trainer_expertise) {
        trainer_expertise = trainer_expertise;
    }

};


#endif //GYM_TRAINER_H
