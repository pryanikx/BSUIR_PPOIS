#pragma once
#include "Equipment.h"
namespace Rent {
    class Snowboard : public Equipment {
    public:
        Snowboard(const std::string& brand, const std::string& model, const std::string& size, int stiffness);
        virtual ~Snowboard();

        std::wstring displayInfo() const override;

    private:
        int stiffness;
    };
}