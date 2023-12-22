#pragma once
#include "Equipment.h"
namespace Rent {
    class Helmet : public Equipment {
    public:
        Helmet(const std::string& brand, const std::string& model, const std::string& size, int protectionLevel);
        virtual ~Helmet();

        std::wstring displayInfo() const override;

    private:
        int protectionLevel;
    };
}