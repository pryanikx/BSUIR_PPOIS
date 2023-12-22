#pragma once
#include <vector>
#include "Equipment.h"
#include "RentalTransaction.h"
namespace Rent {
    class RentalShop {
    public:
        RentalShop();
        ~RentalShop();

        void addEquipment(Equipment* equipment);
        void removeEquipment(Equipment* equipment);
        void displayAvailableEquipment() const;
        void rentEquipment(Equipment* equipment, Customer* customer, const std::wstring& rentalDate, int duration);

        const std::vector<Equipment*>& getAvailableEquipment() const;

    private:
        std::vector<Equipment*> availableEquipment;
        std::vector<RentalTransaction*> rentalTransactions;
    };
}