#include "RentalShop.h"
#include <algorithm>
#include <iostream>
namespace Rent {
    RentalShop::RentalShop() {}

    RentalShop::~RentalShop() {
        for (Equipment* equip : availableEquipment) {
            delete equip;
        }

        for (RentalTransaction* transaction : rentalTransactions) {
            delete transaction;
        }
    }

    void RentalShop::addEquipment(Equipment* equipment) {
        availableEquipment.push_back(equipment);
    }

    void RentalShop::removeEquipment(Equipment* equipment) {
        auto it = std::find(availableEquipment.begin(), availableEquipment.end(), equipment);

        if (it != availableEquipment.end()) {
            delete* it;
            availableEquipment.erase(it);
        }
    }

    void RentalShop::displayAvailableEquipment() const {
        std::cout << "Available Equipment:\n";
        for (const Equipment* equip : availableEquipment) {
            equip->displayInfo();
        }
    }

    void RentalShop::rentEquipment(Equipment* equipment, Customer* customer, const std::wstring& rentalDate, int duration) {
        equipment->setAvailability(false);
        rentalTransactions.push_back(new RentalTransaction(equipment, customer, rentalDate, duration));
    }

    const std::vector<Equipment*>& RentalShop::getAvailableEquipment() const {
        return availableEquipment;
    }
}