#pragma once
#include <iostream>
#include <string>

class Shop
{
private:
    std::string name;
    std::string address;
    std::string product;
    int numbers;
    double value;

public:
    Shop();
    Shop(std::string name, std::string address, std::string product, int numbers, double value);
    Shop(const Shop& other)
        : name(other.name), address(other.address), product(other.product),
        numbers(other.numbers), value(other.value) {}
    std::string get_product();
    int get_numbers();
    bool operator<(const Shop& other);
    bool operator>(const Shop& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Shop& other);
    friend std::istream& operator>>(std::istream& is, Shop& other);
};
