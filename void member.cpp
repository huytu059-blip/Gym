//
// Created by FPT SHOP on 4/3/2026.
//
/*
#include "GymManager.h"
#include "Member.h"


// Lấy toàn bộ danh sách member
std::unordered_map<int, Member>Members;

     std::unordered_map<int, Member>DisplayAllMember() {
        return Members; // trả bản copy
    };



// Tìm kiếm member theo keyword (name hoặc phone)
std::unordered_map<int, Member>searchMembers(const std::string& keyWord) {
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
bool addMember(const Member& m) {
    int id = m.getId();

    // Kiểm tra trùng lặp
    if (Members.find(id) != Members.end()) {
        return false; // Thất bại: ID đã tồn tại
    }

    // Thêm vào dữ liệu
    Members[id] = m;
    return true; // Thành công
}


bool updateMember(int id, const Member& newData) {
    auto it = Members.find(id);
    if (it == Members.end()) return false;

    it->second.setName(newData.getName());               //phải thâm hàm set ở member.h nữa
    it->second.setNumberPhone(newData.getNumberPhone());
    it->second.setGender(newData.getGender());

    return true;
}




    int deleteMembersByName(const std::string& name) {
        int count = 0;
        // Phải dùng iterator vì name không phải là Key của Map
        for (auto it = Members.begin(); it != Members.end(); ) {
            if (it->second.getName() == name) {
                it = Members.erase(it); // Xóa xong phải gán lại it để không bị "mất phương hướng"
                count++;
            } else {
                ++it;
            }
        }
        return count;
    }

bool
extendPackage(int memberId, int extraDays) {
    // 1. Tìm kiếm Member bằng ID
    auto it = Members.find(memberId);

    // 2. Kiểm tra nếu không tồn tại ID này
    if (it == Members.end()) {
        return false;
    }

    // 3. Kiểm tra tính hợp lệ của số ngày thêm vào
    if (extraDays <= 0) {
        return false;
    }

    // 4. Gọi hàm public từ đối tượng Member
    // it->second chính là đối tượng Member nằm trong Map
    it->second.extendDays(extraDays);

    return true;
}*/


/*
void memberScreen(){
   DisplayAllMember();*/

#include "GymManager.h"
#include <iostream>

// ===== Lấy toàn bộ danh sách =====
const std::unordered_map<int, Member>& GymManager::DisplayAllMembers() const {
    return Members;
}

// ===== Tìm kiếm =====
std::unordered_map<int, Member>
GymManager::searchMembers(const std::string& keyWord) const {
    std::unordered_map<int, Member> result;

    for (const auto& p : Members) {
        const Member& temp = p.second;

        if (temp.getName() == keyWord ||
            temp.getNumberPhone() == keyWord) {
            result.insert(p);
        }
    }

    return result;
}

// ===== Thêm =====
bool GymManager::addMember(const Member& m) {
    int id = m.getId();

    if (Members.find(id) != Members.end()) return false;

    Members[id] = m;
    return true;
}

// ===== Cập nhật =====
bool GymManager::updateMember(int id, const Member& newData) {
    auto it = Members.find(id);
    if (it == Members.end()) return false;

    it->second.setName(newData.getName());
    it->second.setNumberPhone(newData.getNumberPhone());
    it->second.setGender(newData.getGender());

    return true;
}

// ===== Xóa =====
bool GymManager::deleteMemberById(int id) {
    return Members.erase(id) > 0;
}

// ===== Gia hạn =====
bool GymManager::extendPackage(int memberId, int extraDays) {
    if (extraDays <= 0) return false;

    auto it = Members.find(memberId);
    if (it == Members.end()) return false;

    it->second.extendDays(extraDays);
    return true;
}

//===== MENU =====             phần này là phần view
void GymManager::memberScreen() {
    int choice;

    do {
        std::cout << "\n===== MEMBER MENU =====\n";
        std::cout << "1. Show all members\n";
        std::cout << "2. Search member\n";
        std::cout << "3. Add member\n";
        std::cout << "4. Update member\n";
        std::cout << "5. Delete member by ID\n";
        std::cout << "6. Extend package\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice) {

            case 1: {
                auto data = DisplayAllMembers();
                for (const auto& p : data) {
                    std::cout << p.second.getName() << std::endl;
                }
                break;
            }

            case 2: {
                std::string key;
                std::cout << "Enter keyword: ";
                std::cin >> key;

                auto result = searchMembers(key);
                for (const auto& p : result) {
                    std::cout << p.second.getName() << std::endl;
                }
                break;
            }

            case 3: {
                int id;
                std::string name, phone, gender;

                std::cout << "ID: "; std::cin >> id;
                std::cout << "Name: "; std::cin >> name;
                std::cout << "Phone: "; std::cin >> phone;
                std::cout << "Gender: "; std::cin >> gender;

                Member m(id, name, phone, gender);

                if (addMember(m))
                    std::cout << "Add success\n";
                else
                    std::cout << "ID existed\n";

                break;
            }

            case 4: {
                int id;
                std::cout << "Enter ID: ";
                std::cin >> id;

                std::string name, phone, gender;
                std::cout << "New name: "; std::cin >> name;
                std::cout << "New phone: "; std::cin >> phone;
                std::cout << "New gender: "; std::cin >> gender;

                Member m(0, name, phone, gender);

                if (updateMember(id, m))
                    std::cout << "Update success\n";
                else
                    std::cout << "Not found\n";

                break;
            }

            case 5: {
                int id;
                std::cout << "Enter ID: ";
                std::cin >> id;

                if (deleteMemberById(id))
                    std::cout << "Deleted\n";
                else
                    std::cout << "Not found\n";

                break;
            }

            case 6: {
                int id, days;
                std::cout << "Enter ID: ";
                std::cin >> id;
                std::cout << "Extra days: ";
                std::cin >> days;

                if (extendPackage(id, days))
                    std::cout << "Extended\n";
                else
                    std::cout << "Failed\n";

                break;
            }

            case 0:
                std::cout << "Exit...\n";
                break;

            default:
                std::cout << "Invalid choice\n";
        }

    } while (choice != 0);
}








