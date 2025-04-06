#include "userInterface.h"
#include "readArrayFromFile.h"
#include"searchAndDisplayProducts.h"

void DoublyLinkedListInterface(vector<Shop>& arr)
{
    DoublyLinkedList<Shop> dll;
    for (int i = 0; i < arr.size(); i++)
    {
        dll.push_back(arr[i]);
    }


    int choice;
    do {
        cout << "\nМеню двозв'язного списку:\n"
            << "1. Додати вузол на початок\n"
            << "2. Додати вузол у список\n"
            << "3. Пошук вузла\n"
            << "4. Видалення вузла\n"
            << "5. Виведення списку з початку\n"
            << "6. Виведення списку з кінця\n"
            << "0. Вихід\n"
            << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Shop shop;
            cin >> shop;
            dll.push_front(shop);
            break;
        }
        case 2: {
            int index;
            Shop shop;
            cin >> shop;
            cout << "Введіть індекс: ";
            cin >> index;
            dll.insert(shop, index);
            break;
        }
        case 3: {
            int index;
            cout << "Введіть індекс: ";
            cin >> index;
            dll.search(index);
            break;
        }
        case 4: {
            int index;
            cout << "Введіть індекс: ";
            cin >> index;
            dll.removeAt(index);
            break;
        }
        case 5:
            dll.print();
            break;
        case 6:
            dll.printEnd();
            break;
        case 0:
            cout << "Вихід...\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);
}

void PriorityQueueInterface(vector<Shop>& arr)
{
    PriorityQueue<Shop> pq;
    pq.buildMaxHeap(arr);

    int choice;
    do {
        cout << "\nМеню черги з пріоритетами:\n"
            << "1. Додати елемент\n"
            << "2. Видалити максимальний елемент\n"
            << "3. Вивести елементи\n"
            << "0. Вихід\n"
            << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Shop shop;
            cin >> shop;
            pq.insert(shop);
            break;
        }
        case 2:
            pq.extractMax();
            break;
        case 3:
            pq.printHeap();
            break;
        case 0:
            cout << "Вихід...\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);
}

void userInterface()
{
    string filename;
    cout << "Вкажіть шлях до файлу: ";
    cin >> filename;
    vector<Shop> arr = readArrayFromFile(filename);

    if (arr.empty()) {
        cout << "Файл порожній або не існує!\n";
        return;
    }

    searchAndDisplayProducts(arr);

    int choice;
    do {
        cout << "\nОберіть структуру даних:\n"
            << "1. Двозв'язний список\n"
            << "2. Черга з пріоритетами\n"
            << "0. Вихід\n"
            << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            DoublyLinkedListInterface(arr);
            break;
        case 2:
            PriorityQueueInterface(arr);
            break;
        case 0:
            cout << "Вихід...\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);
}
