#pragma once
#include "Equipment.h"
namespace Rent {
    class Boots : public Equipment {
    public:
        Boots(const std::string& brand, const std::string& model, const std::string& size, int stiffnessLevel);
        virtual ~Boots();

        std::wstring displayInfo() const override;

    private:
        int stiffnessLevel;
    };
}
