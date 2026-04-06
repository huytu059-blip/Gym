//
// Created by FPT SHOP on 4/3/2026.
//

#include "GymManager.h"
#include "Member.h"
/*void GymManager::Display_all_members(std::unordered_map<int, Member> Members, std::string keyWord) {
    for (auto it = Members.begin(); it != Members.end(); it++){
        Member temp = it->second;
        std::cout << "ID: " << temp.getId() << std::endl;
        std::cout << "Name: " << temp.getName() << std::endl;
        std::cout << "Number Phone: " << temp.getNumberPhone() << std::endl;
}
};
void GymManager::Search_members (std::unordered_map<int, Member> Members, std::string keyWord) {
    for (auto it = Members.begin(); it != Members.end(); it++) {
        Member temp = it->second;
        if (temp.getName() == keyWord ||
            temp.getNumberPhone() == keyWord) {
            std::cout << "ID: " << temp.getId() << std::endl;
            std::cout << "Name: " << temp.getName() << std::endl;
            std::cout << "Number Phone: " << temp.getNumberPhone() << std::endl;
            }
    }
};*/
#include "GymManager.h"

// Lấy toàn bộ danh sách member
std::unordered_map<int, Member> GymManager::getAllMembers() const {
    return Members; // trả bản copy
}


// Tìm kiếm member theo keyword (name hoặc phone)
std::unordered_map<int, Member> GymManager::searchMembers(const std::string& keyWord) const {
    std::unordered_map<int, Member> result;

    for (const auto& p : Members) {
        const Member& temp = p.second;

        if (temp.getName() == keyWord ||
            temp.getNumberPhone() == keyWord) {
            result.insert(p); // giữ nguyên ID + Member
            }
    }

    return result;
}
void GymManager::addMember(const Member& m) {
    int id = m.getId();

    // Không cho trùng ID (chuẩn hệ thống thật)
    if (Members.find(id) == Members.end()) {
        Members.insert({id, m});
    }
    // Nếu muốn ghi đè thì dùng:
    // members[id] = m;
}
bool GymManager::addMember(const Member& m) {
    int id = m.getId();
    auto [it, inserted] = Members.emplace(id, m);
    return inserted;
}

bool GymManager::updateMember(int id, const Member& newData) {
    auto it = Members.find(id);
    if (it == Members.end()) return false;

    it->second.setName(newData.getName());
    it->second.setNumberPhone(newData.getNumberPhone());
    it->second.setAge(newData.getAge());

    return true;
}

bool GymManager::deleteMemberById(int id) {
    return Members.erase(id) > 0;
}

int GymManager::deleteMemberByName(const std::string& name) {
    int count = 0;

    for (auto it = Members.begin(); it != Members.end(); ) {
        if (it->second.getName() == name) {
            it = Members.erase(it);
            count++;
        } else {
            ++it;
        }
    }

    return count;
}

bool GymManager::extendPackage(int memberId, int extraDays) {
    auto it = Members.find(memberId);
    if (it == Members.end()) return false;

    it->second.extendDays(extraDays);
    return true;
}

const std::unordered_map<int, Member>& GymManager::getAllMembers() const {
    return Members;
}




