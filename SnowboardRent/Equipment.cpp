#include "Equipment.h"
#include <iostream>
#include <sstream>

namespace Rent {
    Equipment::Equipment(const std::string& brand, const std::string& model, const std::string& size)
        : brand(brand), model(model), size(size), available(true) {}

    Equipment::~Equipment() {}

    std::wstring Equipment::displayInfo() const {
        std::wstringstream ss;
        ss << L"Brand: " << std::wstring(brand.begin(), brand.end()) << L", Model: " << std::wstring(model.begin(), model.end()) << L", Size: " << std::wstring(size.begin(), size.end()) << std::endl;
        ss << L"Status: " << (available ? L"Available" : L"Rented") << std::endl;
        return ss.str();
    }


    bool Equipment::isAvailable() const {
        return available;
    }

    void Equipment::setAvailability(bool available) {
        this->available = available;
    }
}