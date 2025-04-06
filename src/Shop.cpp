#include "Shop.h"

Shop::Shop() : name(""), address(""), product(""), numbers(0), value(0) {}
Shop::Shop(std::string name, std::string address, std::string product, int numbers, double value) :
    name(name), address(address), product(product), numbers(numbers), value(value) {
}

std::string Shop::get_product() { return product; }

int Shop::get_numbers() { return numbers; }
bool Shop::operator<(const Shop& other) { return value < other.value; }

bool Shop::operator>(const Shop& other) const
{
    return value > other.value; // Використовуйте релевантне поле для порівняння
}

std::ostream& operator<<(std::ostream& os, const Shop& other)
{
    os << "Store: " << other.name << std::endl
        << "Address: " << other.address << std::endl
        << "Product: " << other.product << std::endl
        << "Numbers: " << other.numbers << std::endl
        << "Value: " << other.value << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Shop& other)
{
    std::getline(is, other.name);

    std::getline(is, other.address);

    std::getline(is, other.product);

    is >> other.numbers;

    is >> other.value;

    // Очистка буфера після вводу чисел, щоб уникнути проблем із наступним введенням рядків
    is.ignore();

    return is;
}
