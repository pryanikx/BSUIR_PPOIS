#include "Snowboard.h"
#include <iostream>
#include <sstream>
namespace Rent {
    Snowboard::Snowboard(const std::string& brand, const std::string& model, const std::string& size, int stiffness)
        : Equipment(brand, model, size), stiffness(stiffness) {}

    Snowboard::~Snowboard() {}

    std::wstring Snowboard::displayInfo() const {
        std::wstringstream ss;
        ss << Equipment::displayInfo();
        ss << L"Stiffness: " << stiffness << std::endl;
        return ss.str();
    }
}