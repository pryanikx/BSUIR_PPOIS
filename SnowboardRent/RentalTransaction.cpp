#include "RentalTransaction.h"
#include <sstream>
namespace Rent {
    RentalTransaction::RentalTransaction(Equipment* equipment, Customer* customer, const std::wstring& rentalDate, int duration)
        : equipment(equipment), customer(customer), rentalDate(rentalDate), duration(duration) {}

    std::wstring RentalTransaction::displayInfo() const {
        std::wstringstream ss;
        ss << L"Rental Date: " << rentalDate << L", Duration: " << duration << L" days" << std::endl;
        ss << equipment->displayInfo();
        ss << customer->displayInfo();
        return ss.str();
    }
}