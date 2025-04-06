#include "searchAndDisplayProducts.h"

void searchAndDisplayProducts(const vector<Shop>& arr)
{
    string product;
    int quantity;
    cout << "¬вед≥ть назву товару: ";
    cin >> product;
    cout << "¬вед≥ть необх≥дну к≥льк≥сть: ";
    cin >> quantity;
    for (int i = 0; i < arr.size(); i++)
    {
        Shop shop = arr[i];
        if (shop.get_product() == product && quantity <= shop.get_numbers()) {
            cout << shop;
        }
    }
}