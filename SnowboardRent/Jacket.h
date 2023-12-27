
#pragma once
#include "Equipment.h"
namespace Rent {
    class Jacket : public Equipment {
    public:
        Jacket(const std::string& brand, const std::string& model, const std::string& size, int warmth);
        ~Jacket();

        int getWarmth() const;
        std::wstring displayInfo() const override;

    private:
        int warmth;
    };
}