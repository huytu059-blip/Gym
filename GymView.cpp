//
// Created by FPT SHOP on 4/3/2026.
//

#include "GymView.h"

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

void drawBox(std::string title) {
    std::cout << "===========================================\n";
    std::cout << "   " << title << std::endl;
    std::cout << "===========================================\n";
}
void chosse() {
    int choice;
    std::cout << "===========================================\n";
    std::cout << "👉 Chọn: ";
    std::cin>> choice;
}
// 1. Quản lý hội viên (Member)
// 2. Quản lý gói tập (Membership Package)
// 3. Check-in / Check-out
// 4. Huấn luyện viên (Trainer)
// 5. Thanh toán & hóa đơn
// 6. Thống kê - báo cáo
// 7. Cài đặt hệ thống
// 0. Đăng xuất
void GymView::mainScreen() const {
    system("cls");
    drawBox("Gym Management");
    std::cout << "[1] Member\n";
    std::cout << "[2] Package\n";
    std::cout << "[3] Check-in\n";
    std::cout << "[4] Trainer\n";
    std::cout << "[5] Payment\n";
    std::cout << "[6] Report\n";
    std::cout << "[7] Settings\n";
    std::cout << "[8] General\n";
    std::cout << "[0] Exit\n";
    chosse();
}

void GymView::generalScreen() const {
//     📊 TỔNG QUAN:
// - Số hội viên: 152
// - Gói tập đang hoạt động: 98
// - Doanh thu hôm nay: 5,200,000 VND
// - PT đang làm việc: 6
    system("cls");
    drawBox("General Infomation");
    std::cout << "Total Members:\n";
    std::cout << "Package is active\n";
    std::cout << "Payment today\n";
    std::cout << "Total Trainer\n";
    std::cout << "[0] Exit\n";
    chosse();
}

void GymView::memberScreen() const {
    system("cls");
    drawBox("Member Management");
    std::cout << "[1] Display all members\n";
    std::cout << "[2] Search members\n";
    std::cout << "[3] Add members\n";
    std::cout << "[4] Update members\n";
    std::cout << "[5] gia han goi tap\n";
    std::cout << "[6] Delete members\n";
    std::cout << "[0] Exit\n";
    chosse();
}

void GymView::packageScreen() const {
    system("cls");
    drawBox("Package Management");
    std::cout << "[1] Add Package\n";
    std::cout << "[2] Display All Package\n";
    std::cout << "[3] Update Package\n";
    std::cout << "[4] Delete Package\n";
    std::cout << "[0] Exit\n";
    chosse();
}

void GymView::checkScreen() const {   //Trọng đang viết nhé, đéo bt dùng đc ko nma đang vt
    system("cls");
    drawBox("Check-in System");
    std::cout << "[1] Check-in\n";
    std::cout << "[2] Check-out\n";
    std::cout << "[3] History\n";
    std::cout << "[0] Exit\n";
    chosse();
}

//CHECKSCREEN
#ifndef CHECK_LOGIC_H
#define CHECK_LOGIC_H

#include <map>
#include <vector>

class CheckScreen {
private:
    std::map<int, bool> checkStatus; // id -> trạng thái

public:

    // check-in
    bool checkIn(int member_ID) {
        if (checkStatus[member_ID] == true) {
            return false; // đã check-in trước đó
        }

        checkStatus[member_ID] = true;
        return true;
    }

    // check-out
    bool checkOut(int member_ID) {
        if (checkStatus[member_ID] == false) {
            return false; // chưa check-in
        }

        checkStatus[member_ID] = false;
        return true;
    }

    // lấy trạng thái của 1 hội viên
    bool getStatus(int member_ID) {
        return checkStatus[id];
    }

    // lấy toàn bộ danh sách trạng thái
    std::vector<std::pair<int,bool>> getAllStatus() {
        std::vector<std::pair<int,bool>> result;

        for (auto &p : checkStatus) {
            result.push_back(p);
        }

        return result;
    }
};

#endif
//////////

void GymView::trainerScreen() const {
    system("cls");
    drawBox("Trainer Management");
    std::cout << "[1] Add PT\n";
    std::cout << "[2] Display All PT\n";
    std::cout << "[3] phan cong hoi vien\n";
    std::cout << "[4] Lich tap\n";
    std::cout << "[5] Delete PT\n";
    std::cout << "[0] Exit\n";
}

void GymView::paymentsScreen() const {
    system("cls");
    drawBox("Payments Management");
    std::cout << "[1] Thanh toan goi tap\n";
    std::cout << "[2] In hoa don\n";
    std::cout << "[3] Lich su giao dich\n";
    std::cout << "[4] Doanh thu theo thang/ ngay\n";
    std::cout << "[0] Exit\n";
    chosse();
}
void GymView::reportScreen() const {    
    system("cls");
    drawBox("Report Management");
    std::cout << "[1] Doanh thu\n";
    std::cout << "[2] so hoi vien moi\n";
    std::cout << "[3] So hoi vien het han\n";
    std::cout << "[4] top pt hoat dong\n";
    std::cout << "[0] Exit\n";
    chosse();
}
//////////
void GymView::settingsScreen() const {    //Trọng
    system("cls");
    drawBox("Settings Management");
    std::cout << "[1] tao tai khoan nhan vien\n";
    std::cout << "[2] phan quyen\n";
    std::cout << "[3] sao luu du lieu\n";
    std::cout << "[0] Exit\n";
}

//Thiết lập giao diện
#ifndef SETTINGS_LOGIC_H
#define SETTINGS_LOGIC_H

#include <map>
#include <string>
#include <vector>

class SettingsScreen {
private:
    std::map<std::string, std::string> accounts;
    // username -> role

public:

    // tạo tài khoản
    bool createAccount(const std::string& member_name, const std::string& role) {
        if (accounts.find(member_name) != accounts.end()) {
            return false; // đã tồn tại
        }

        accounts[member_name] = role;
        return true;
    }

    // thay đổi quyền
    bool setRole(const std::string& member_name, const std::string& role) {
        if (accounts.find(member_name) == accounts.end()) {
            return false; // không tồn tại
        }

        accounts[member_name] = role;
        return true;
    }

    // lấy role của user
    std::string getRole(const std::string& member_name) const {
        auto it = accounts.find(member_name);
        if (it != accounts.end()) {
            return it->second;
        }
        return "";
    }

    // lấy toàn bộ danh sách tài khoản
    std::vector<std::pair<std::string,std::string>> getAllAccounts() const {
        std::vector<std::pair<std::string,std::string>> result;

        for (auto &p : accounts) {
            result.push_back(p);
        }

        return result;
    }

    // backup (logic đơn giản)
    bool backupData() {
        return true;
    }
};

#endif
