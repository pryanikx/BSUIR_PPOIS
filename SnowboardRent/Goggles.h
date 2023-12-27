#pragma once
#include "Equipment.h"

namespace Rent {
    class Goggles : public Equipment {
    public:
        Goggles(const std::string& brand, const std::string& model, const std::string& size, bool antiFog);
        ~Goggles();

        bool hasAntiFog() const;
        std::wstring displayInfo() const override;

    private:
        bool antiFog;
    };
}