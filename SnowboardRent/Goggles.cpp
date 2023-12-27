#include "Goggles.h"
#include <sstream>
namespace Rent{
Goggles::Goggles(const std::string& brand, const std::string& model, const std::string& size, bool antiFog)
    : Equipment(brand, model, size), antiFog(antiFog) {}

Goggles::~Goggles() {}

bool Goggles::hasAntiFog() const {
    return antiFog;
}

std::wstring Goggles::displayInfo() const {
    std::wstringstream ss;
    ss << Equipment::displayInfo();
    ss << L"Anti-Fog: " << (antiFog ? L"Yes" : L"No") << std::endl;
    return ss.str();
}
}