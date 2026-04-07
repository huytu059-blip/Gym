#include "ReportManager.h"
#include <algorithm>

ReportManager::ReportManager(
    const std::unordered_map<int, Member>& members,
    const std::unordered_map<int, Registration>& reg,
    const std::unordered_map<int, Trainer>& trainers)
    : Members(members), Reg(reg), Trainers(trainers) {}



double ReportManager::getTotalRevenue() const {
    double total = 0;

    for (const auto& [id, r] : Reg) {
        total += r.getAmount();
    }

    return total;
}



int ReportManager::countNewMembers() const {
    int count = 0;

    for (const auto& [id, m] : Members) {
        if (m.isNew()) {
            count++;
        }
    }

    return count;
}



int ReportManager::countExpiredMembers() const {
    int count = 0;

    for (const auto& [id, m] : Members) {
        if (m.isExpired()) {
            count++;
        }
    }

    return count;
}



std::vector<Trainer> ReportManager::getTopTrainers(int topN) const {
    std::vector<Trainer> result;

    for (const auto& [id, t] : Trainers) {
        result.push_back(t);
    }

    std::sort(result.begin(), result.end(), [](const Trainer& a, const Trainer& b) {
        return a.getActiveClients() > b.getActiveClients();
    });

    if ((int)result.size() > topN) {
        result.resize(topN);
    }

    return result;
}
