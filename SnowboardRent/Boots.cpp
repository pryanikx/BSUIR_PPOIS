#include "Boots.h"
#include <iostream>
#include <sstream>

Rent::Boots::Boots(const std::string& brand, const std::string& model, const std::string& size, int stiffnessLevel)
    : Equipment(brand, model, size), stiffnessLevel(stiffnessLevel) {}

Rent::Boots::~Boots() {}

std::wstring Rent::Boots::displayInfo() const {
    std::wstringstream ss;
    ss << Equipment::displayInfo();
    ss << L"Stiffness Level: " << stiffnessLevel << std::endl;
    return ss.str();
}