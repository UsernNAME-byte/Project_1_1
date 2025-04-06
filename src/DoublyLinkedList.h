#pragma once
#include <iostream>

template<typename T>
class DoublyLinkedList
{
private:
    // ��������� ����� �����'������ ������
    struct Node
    {
        T data;       // ��������, ��� ���������� � ����
        Node* prev;   // �������� �� ��������� ����� � ������
        Node* next;   // �������� �� ��������� ����� � ������

        // ����������� �����: ������ ��������, �������� ��������� �� nullptr
        Node(T val);
    };

    Node* head; // �������� �� ������ ����� ������
    Node* tail; // �������� �� ������� ����� ������
    int Size;   // �������� ����� ������

public:
    // ����������� �� �������������: ������� ������� ������
    DoublyLinkedList();

    // ����������� ���������: ������� ����� ������ �� ���� ������ ������
    DoublyLinkedList(const DoublyLinkedList& other);

    // ���� ������� �� ������� ������
    void push_front(T val);

    // �������� ������� �� ������ ��������
    void insert(T val, int index);

    // ����� �������� �� ��������, ������� ��������� �� ��������
    T& search(int index);

    // ������� ������� �� ��������
    void removeAt(int index);

    // ���� ������� � ����� ������
    void push_back(T val);

    // �������� ������ � ������� �� ����
    void print();

    // �������� ������ � ���� �� �������
    void printEnd();

    // ����������: ����� ������ ��� �������� ��'����
    ~DoublyLinkedList();

    // ������� �� �������� � ������
    void clear();

    // ������� ������� �������� � ������
    int get_size();

    // ��������, �� ������ �������
    bool isEmpty() const;
};

// ��������� ������������ �����
template<typename T>
DoublyLinkedList<T>::Node::Node(T val) : data(val), prev(nullptr), next(nullptr) {}

// ��������� ������������ ������
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), Size(0) {}

// ��������� ������������ ���������
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), Size(0)
{
    Node* current = other.head; // �������� � ������ ������, ���� �������
    while (current)
    {
        push_back(current->data); // ������ ����� ������� � ����� ������
        current = current->next;
    }
}

// ���� ������� � ������� ������
template<typename T>
void DoublyLinkedList<T>::push_front(T val)
{
    Node* newNode = new Node(val); // ��������� ����� �����

    if (!head)  // ���� ������ �������, ����� ������� ��� � �������, � �������
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head; // ����� ����� ����� �� ������� ������
        head->prev = newNode; // ������� ������ ����� ����� �� ����� �����
        head = newNode; // ��������� ������ ������
    }
    Size++;
}

// ������� �������� �� ��������
template<typename T>
void DoublyLinkedList<T>::insert(T val, int index)
{
    if (index < 0 || index > Size) // ���������� ����������� �������
    {
        std::cerr << "Invalid index\n";
        return;
    }

    if (index == 0) // ������� � ������� ������
    {
        push_front(val);
        return;
    }

    if (index == Size) // ������� � ����� ������
    {
        push_back(val);
        return;
    }

    // ������� � �������� ������
    Node* newNode = new Node(val); // ��������� ����� �����
    Node* current;

    // �������� ���������� ����� ������ (� ������ ��� ������)
    if (index < Size / 2)
    {
        // ���� ������ ������� �� �������, ������ � ������
        current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
    }
    else
    {
        // ���� ������ ������� �� ����, ������ � ������
        current = tail;
        for (int i = Size - 1; i > index; i--)
        {
            current = current->prev;
        }
    }

    // ���������� ����� ����� �� current � current->next
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next)
        current->next->prev = newNode;

    current->next = newNode;
    Size++;
}


template<typename T>
T& DoublyLinkedList<T>::search(int index)
{
    if (index < 0 || index >= Size) {
        throw std::out_of_range("Invalid index");
    }

    Node* current;

    if (index < Size / 2) { // ��� �� ������
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    }
    else { // ��� �� ������
        current = tail;
        for (int i = Size - 1; i > index; i--) {
            current = current->prev;
        }
    }

    return current->data;
}

template<typename T>
void DoublyLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= Size) { // ����������, �� ������ � ���������� �����
        std::cerr << "Invalid index\n";
        return;
    }

    Node* temp;

    if (index == 0) { // ��������� ������� ��������
        temp = head;
        head = head->next; // ��������� ������ ������
        if (head)
            head->prev = nullptr; // ���� ������ �� �������, ��'������ ��������� �����
        else
            tail = nullptr; // ���� ���� ��������� ������ �������, ��������� `tail`
    }
    else if (index == Size - 1) { // ��������� ���������� ��������
        temp = tail;
        tail = tail->prev; // ��������� ���� ������
        if (tail)
            tail->next = nullptr; // ���� ������ �� �������, ��'������ ��������� �����
        else
            head = nullptr; // ���� ���� ��������� ������ �������, ��������� `head`
    }
    else { // ��������� �������� �������� ������
        Node* current;

        // �������� ����������� �������� ������
        if (index < Size / 2) {
            current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
        }
        else {
            current = tail;
            for (int i = Size - 1; i > index; i--) {
                current = current->prev;
            }
        }

        temp = current;
        temp->prev->next = temp->next; // ��������� ����� �'������ � ���������
        temp->next->prev = temp->prev; // ��������� ����� �'������ � ���������
    }

    delete temp; // ��������� ����� � ���'��
    Size--; // �������� ����� ������
}

template<typename T>
void DoublyLinkedList<T>::push_back(T val)
{
    Node* newNode = new Node(val); // ��������� ����� �����

    if (!head) { // ���� ������ �������, ����� ������� ��� � �������, � �������
        head = tail = newNode;
    }
    else { // ������ ����� ���� ��������� `tail`
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode; // ��������� `tail`
    }
    Size++; // �������� ����� ������
}

template<typename T>
void DoublyLinkedList<T>::print()
{
    Node* current = head; // �������� � ������
    while (current)
    {
        std::cout << current->data << " "; // �������� �������� �������
        current = current->next; // ���������� �� ���������� �����
    }
    std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::printEnd()
{
    Node* current = tail; // �������� � ������
    while (current)
    {
        std::cout << current->data << " "; // �������� �������� �������
        current = current->prev; // ���������� �� ������������ �����
    }
    std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
    while (head) // ���� ������ �� �������
    {
        Node* temp = head; // ���������� �������� �� `head`
        head = head->next; // ������ `head` �� ��������� �����
        delete temp; // ��������� �����
    }
    tail = nullptr; // ������� `tail`
    Size = 0; // ��������� ����� ������
}

template<typename T>
int DoublyLinkedList<T>::get_size() { return Size; }


template<typename T>
bool DoublyLinkedList<T>::isEmpty() const { return head == nullptr; }

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() { clear(); }
