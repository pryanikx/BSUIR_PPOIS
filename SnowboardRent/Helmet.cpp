#include "Helmet.h"
#include <iostream>
#include <sstream>
namespace Rent {
    Helmet::Helmet(const std::string& brand, const std::string& model, const std::string& size, int protectionLevel)
        : Equipment(brand, model, size), protectionLevel(protectionLevel) {}

    Helmet::~Helmet() {}

    std::wstring Helmet::displayInfo() const {
        std::wstringstream ss;
        ss << Equipment::displayInfo();
        ss << L"Protection Level: " << protectionLevel << std::endl;
        return ss.str();
    }
}