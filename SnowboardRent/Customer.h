#pragma once
#include <string>
namespace Rent {
    class Customer {
    public:
        Customer(const std::string& firstName, const std::string& lastName, const std::string& contactInfo);
        ~Customer();

        std::wstring displayInfo() const;

    private:
        std::string firstName;
        std::string lastName;
        std::string contactInfo;
    };
}