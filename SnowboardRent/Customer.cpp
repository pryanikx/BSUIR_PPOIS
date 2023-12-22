#include "Customer.h"
#include <iostream>
#include <sstream>
namespace Rent {
    Customer::Customer(const std::string& firstName, const std::string& lastName, const std::string& contactInfo)
        : firstName(firstName), lastName(lastName), contactInfo(contactInfo) {}

    Customer::~Customer() {}

    std::wstring Customer::displayInfo() const {
        std::wstringstream ss;
        ss << L"Name: " << std::wstring(firstName.begin(), firstName.end()) << L" " << std::wstring(lastName.begin(), lastName.end()) << L", Contact: " << std::wstring(contactInfo.begin(), contactInfo.end()) << std::endl;
        return ss.str();
    }
}