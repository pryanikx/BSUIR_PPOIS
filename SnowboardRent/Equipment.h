#pragma once
#include <string>
namespace Rent {
    class Equipment {
    public:
        Equipment(const std::string& brand, const std::string& model, const std::string& size);
        virtual ~Equipment();

        virtual std::wstring displayInfo() const;

        bool isAvailable() const;
        void setAvailability(bool available);

    private:
        std::string brand;
        std::string model;
        std::string size;
        bool available;
    };
}