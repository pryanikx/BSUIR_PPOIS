#include "InventoryManager.h"
#include "Snowboard.h"
#include "Boots.h"
#include "Helmet.h"
namespace Rent {
    InventoryManager::InventoryManager() {}

    InventoryManager::~InventoryManager() {
        for (Equipment* equip : allEquipment) {
            delete equip;
        }
    }

    Equipment* InventoryManager::createSnowboard(const std::string& brand, const std::string& model, const std::string& size, int stiffness) {
        Equipment* snowboard = new Snowboard(brand, model, size, stiffness);
        allEquipment.push_back(snowboard);
        return snowboard;
    }

    Equipment* InventoryManager::createBoots(const std::string& brand, const std::string& model, const std::string& size, int stiffnessLevel) {
        Equipment* boots = new Boots(brand, model, size, stiffnessLevel);
        allEquipment.push_back(boots);
        return boots;
    }

    Equipment* InventoryManager::createHelmet(const std::string& brand, const std::string& model, const std::string& size, int protectionLevel) {
        Equipment* helmet = new Helmet(brand, model, size, protectionLevel);
        allEquipment.push_back(helmet);
        return helmet;
    }
}