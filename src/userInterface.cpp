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
        cout << "\n���� �����'������ ������:\n"
            << "1. ������ ����� �� �������\n"
            << "2. ������ ����� � ������\n"
            << "3. ����� �����\n"
            << "4. ��������� �����\n"
            << "5. ��������� ������ � �������\n"
            << "6. ��������� ������ � ����\n"
            << "0. �����\n"
            << "��� ����: ";
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
            cout << "������ ������: ";
            cin >> index;
            dll.insert(shop, index);
            break;
        }
        case 3: {
            int index;
            cout << "������ ������: ";
            cin >> index;
            dll.search(index);
            break;
        }
        case 4: {
            int index;
            cout << "������ ������: ";
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
            cout << "�����...\n";
            break;
        default:
            cout << "������� ����. ��������� �� ���.\n";
        }
    } while (choice != 0);
}

void PriorityQueueInterface(vector<Shop>& arr)
{
    PriorityQueue<Shop> pq;
    pq.buildMaxHeap(arr);

    int choice;
    do {
        cout << "\n���� ����� � �����������:\n"
            << "1. ������ �������\n"
            << "2. �������� ������������ �������\n"
            << "3. ������� ��������\n"
            << "0. �����\n"
            << "��� ����: ";
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
            cout << "�����...\n";
            break;
        default:
            cout << "������� ����. ��������� �� ���.\n";
        }
    } while (choice != 0);
}

void userInterface()
{
    string filename;
    cout << "������ ���� �� �����: ";
    cin >> filename;
    vector<Shop> arr = readArrayFromFile(filename);

    if (arr.empty()) {
        cout << "���� ������� ��� �� ����!\n";
        return;
    }

    searchAndDisplayProducts(arr);

    int choice;
    do {
        cout << "\n������ ��������� �����:\n"
            << "1. �����'����� ������\n"
            << "2. ����� � �����������\n"
            << "0. �����\n"
            << "��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            DoublyLinkedListInterface(arr);
            break;
        case 2:
            PriorityQueueInterface(arr);
            break;
        case 0:
            cout << "�����...\n";
            break;
        default:
            cout << "������� ����. ��������� �� ���.\n";
        }
    } while (choice != 0);
}
