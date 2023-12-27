#include "Jacket.h"
#include <sstream>
namespace Rent {
    Jacket::Jacket(const std::string& brand, const std::string& model, const std::string& size, int warmth)
        : Equipment(brand, model, size), warmth(warmth) {}

    Jacket::~Jacket() {}

    int Jacket::getWarmth() const {
        return warmth;
    }

    std::wstring Jacket::displayInfo() const {
        std::wstringstream ss;
        ss << Equipment::displayInfo();
        ss << L"Warmth: " << warmth << std::endl;
        return ss.str();
    }
}