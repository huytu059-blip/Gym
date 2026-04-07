#pragma once
#include <unordered_map>
#include <vector>
#include "Member.h"
#include "Registration.h"
#include "Trainer.h"

class ReportManager {
private:
    const std::unordered_map<int, Member>& Members;
    const std::unordered_map<int, Registration>& Reg;
    const std::unordered_map<int, Trainer>& Trainers;

public:
    ReportManager(const std::unordered_map<int, Member>& members,
                  const std::unordered_map<int, Registration>& reg,
                  const std::unordered_map<int, Trainer>& trainers);

    double getTotalRevenue() const;
    int countNewMembers() const;
    int countExpiredMembers() const;
    std::vector<Trainer> getTopTrainers(int topN) const;
};
