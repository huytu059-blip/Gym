// #include <iostream>
// #include "Controller/GymController.h"
// #include <unordered_map>
// NEM LAM CAI DEO GI VOI FILE MAIN VAY TR
// int main() {
//     std::unordered_map<int, Member> Members;
//     std::unordered_map<int, Registration> Reg;

//     // Ví dụ thêm dữ liệu
//     Member m1(1, "Huy");
//     Member m2(2, "An");

//     Members.insert({m1.getMemberId(), m1});

//     Registration r1(1, "2025-01-01", "2025-12-31");
//     Registration r2(2, "2024-01-01", "2024-12-31");

//     Reg.insert({r1.getRegID(), r1});

//     std::string currentDate = "2025-06-01";

//     GymController controller;
//     controller.listActiveMembers(currentDate);

//     return 0;
// }

// #include "GymController.h"
#include "Controller/GymController.h"

int main() {
    GymController app;
    app.run();
    return 0;
}

