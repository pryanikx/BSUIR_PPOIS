#include "CppUnitTest.h"
#include "../Project2/Equipment.cpp"
#include "../Project2/Boots.cpp"
#include "../Project2/Customer.cpp"
#include "../Project2/Helmet.cpp"
#include "../Project2/InventoryManager.cpp"
#include "../Project2/RentalShop.cpp"
#include "../Project2/RentalTransaction.cpp"
#include "../Project2/Snowboard.cpp"
#include "../Project2/Jacket.cpp"
#include "../Project2/Goggles.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Rent
{
    TEST_CLASS(EquipmentTest)
    {
    public:
        TEST_METHOD(DisplayInfoTest)
        {
            Equipment equipment("Brand", "Model", "Size");

            std::wstring result = equipment.displayInfo();

            Assert::AreNotEqual(result.find(L"Brand"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Model"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Size"), std::wstring::npos);
        }
    };

    TEST_CLASS(SnowboardTest)
    {
    public:
        TEST_METHOD(DisplayInfoTest)
        {
            Snowboard snowboard("Brand", "Model", "Size", 5);

            std::wstring result = snowboard.displayInfo();

            Assert::AreNotEqual(result.find(L"Brand"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Model"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Size"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Stiffness: 5"), std::wstring::npos);
        }
    };

    TEST_CLASS(BootsTest)
    {
    public:
        TEST_METHOD(DisplayInfoTest)
        {
            Boots boots("Brand", "Model", "Size", 3);

            std::wstring result = boots.displayInfo();

            Assert::AreNotEqual(result.find(L"Brand"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Model"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Size"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Stiffness Level: 3"), std::wstring::npos);
        }
    };

    TEST_CLASS(HelmetTest)
    {
    public:
        TEST_METHOD(DisplayInfoTest)
        {
            Helmet helmet("Brand", "Model", "Size", 4);

            std::wstring result = helmet.displayInfo();

            Assert::AreNotEqual(result.find(L"Brand"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Model"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Size"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Protection Level: 4"), std::wstring::npos);
        }
    };

    TEST_CLASS(CustomerTest)
    {
    public:
        TEST_METHOD(DisplayInfoTest)
        {
            Customer customer("Ivan", "Pernikov", "ivan.pernikov@gmail.com");

            std::wstring result = customer.displayInfo();

            Assert::AreNotEqual(result.find(L"Name: Ivan Pernikov"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Contact: ivan.pernikov@gmail.com"), std::wstring::npos);
        }
    };

    TEST_CLASS(RentalTransactionTest)
    {
    public:
        TEST_METHOD(DisplayInfoTest)
        {
            Equipment* equipment = new Snowboard("Brand", "Model", "Size", 5);
            Customer* customer = new Customer("Ivan", "Pernikov", "ivan.pernikov@gmail.com");
            RentalTransaction transaction(equipment, customer, L"2023-01-01", 7);

            std::wstring result = transaction.displayInfo();

            Assert::AreNotEqual(result.find(L"Rental Date: 2023-01-01, Duration: 7 days"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Brand: Brand, Model: Model, Size: Size"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Name: Ivan Pernikov, Contact: ivan.pernikov@gmail.com"), std::wstring::npos);
        }
    };


    TEST_CLASS(RentalShopTest)
    {
    public:
        TEST_METHOD(AddRemoveEquipmentTest)
        {
            RentalShop rentalShop;
            Equipment* equipment = new Equipment("Brand", "Model", "Size");

            rentalShop.addEquipment(equipment);
            std::vector<Equipment*> availableEquipment = rentalShop.getAvailableEquipment();
            rentalShop.removeEquipment(equipment);

            Assert::IsTrue(availableEquipment.size() == 1);
            Assert::IsTrue(availableEquipment[0]->isAvailable());
        }
    };


    TEST_CLASS(GogglesTest)
    {
    public:
        TEST_METHOD(DisplayInfoTest)
        {
            Goggles goggles("Brand", "Model", "Size", true);
            std::wstring result = goggles.displayInfo();
            Assert::AreNotEqual(result.find(L"Brand"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Model"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Size"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Anti-Fog: Yes"), std::wstring::npos);
        }
    };

    TEST_CLASS(JacketTest)
    {
    public:
        TEST_METHOD(DisplayInfoTest)
        {
            Jacket jacket("Brand", "Model", "Size", 4);
            std::wstring result = jacket.displayInfo();
            Assert::AreNotEqual(result.find(L"Brand"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Model"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Size"), std::wstring::npos);
            Assert::AreNotEqual(result.find(L"Warmth: 4"), std::wstring::npos);
        }
    };
}
