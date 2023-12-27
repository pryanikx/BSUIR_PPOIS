#pragma once
#include "Equipment.h"
#include "Customer.h"
namespace Rent {
    class RentalTransaction {
    public:
        RentalTransaction(Equipment* equipment, Customer* customer, const std::wstring& rentalDate, int duration);
        ~RentalTransaction() {}

        std::wstring displayInfo() const;

    private:
        Equipment* equipment;
        Customer* customer;
        std::wstring rentalDate;
        int duration;
    };
}