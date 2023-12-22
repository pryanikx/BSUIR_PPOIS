#pragma once
#include <vector>
#include "Equipment.h"
namespace Rent {
    class InventoryManager {
    public:
        InventoryManager();
        ~InventoryManager();

        Equipment* createSnowboard(const std::string& brand, const std::string& model, const std::string& size, int stiffness);
        Equipment* createBoots(const std::string& brand, const std::string& model, const std::string& size, int stiffnessLevel);
        Equipment* createHelmet(const std::string& brand, const std::string& model, const std::string& size, int protectionLevel);

    private:
        std::vector<Equipment*> allEquipment;
    };
}