#pragma once
#include <iostream>

template<typename T>
class DoublyLinkedList
{
private:
    // Структура вузла двозв'язного списку
    struct Node
    {
        T data;       // Значення, яке зберігається у вузлі
        Node* prev;   // Вказівник на попередній вузол у списку
        Node* next;   // Вказівник на наступний вузол у списку

        // Конструктор вузла: приймає значення, ініціалізує вказівники як nullptr
        Node(T val);
    };

    Node* head; // Вказівник на перший вузол списку
    Node* tail; // Вказівник на останній вузол списку
    int Size;   // Поточний розмір списку

public:
    // Конструктор за замовчуванням: створює порожній список
    DoublyLinkedList();

    // Конструктор копіювання: створює новий список як копію іншого списку
    DoublyLinkedList(const DoublyLinkedList& other);

    // Додає елемент на початок списку
    void push_front(T val);

    // Вставляє елемент за певним індексом
    void insert(T val, int index);

    // Пошук елемента за індексом, повертає посилання на значення
    T& search(int index);

    // Видаляє елемент за індексом
    void removeAt(int index);

    // Додає елемент у кінець списку
    void push_back(T val);

    // Виводить список з початку до кінця
    void print();

    // Виводить список з кінця до початку
    void printEnd();

    // Деструктор: очищає список при видаленні об'єкта
    ~DoublyLinkedList();

    // Видаляє всі елементи зі списку
    void clear();

    // Повертає кількість елементів у списку
    int get_size();

    // Перевіряє, чи список порожній
    bool isEmpty() const;
};

// Реалізація конструктора вузла
template<typename T>
DoublyLinkedList<T>::Node::Node(T val) : data(val), prev(nullptr), next(nullptr) {}

// Реалізація конструктора списку
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), Size(0) {}

// Реалізація конструктора копіювання
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), Size(0)
{
    Node* current = other.head; // Починаємо з голови списку, який копіюємо
    while (current)
    {
        push_back(current->data); // Додаємо кожен елемент у новий список
        current = current->next;
    }
}

// Додає елемент у початок списку
template<typename T>
void DoublyLinkedList<T>::push_front(T val)
{
    Node* newNode = new Node(val); // Створюємо новий вузол

    if (!head)  // Якщо список порожній, новий елемент стає і головою, і хвостом
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head; // Новий вузол вказує на поточну голову
        head->prev = newNode; // Поточна голова вказує назад на новий вузол
        head = newNode; // Оновлюємо голову списку
    }
    Size++;
}

// Вставка елемента за індексом
template<typename T>
void DoublyLinkedList<T>::insert(T val, int index)
{
    if (index < 0 || index > Size) // Перевіряємо допустимість індексу
    {
        std::cerr << "Invalid index\n";
        return;
    }

    if (index == 0) // Вставка в початок списку
    {
        push_front(val);
        return;
    }

    if (index == Size) // Вставка в кінець списку
    {
        push_back(val);
        return;
    }

    // Вставка в середину списку
    Node* newNode = new Node(val); // Створюємо новий вузол
    Node* current;

    // Вибираємо оптимальну точку пошуку (з голови або хвоста)
    if (index < Size / 2)
    {
        // Якщо індекс ближчий до початку, шукаємо з голови
        current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
    }
    else
    {
        // Якщо індекс ближчий до кінця, шукаємо з хвоста
        current = tail;
        for (int i = Size - 1; i > index; i--)
        {
            current = current->prev;
        }
    }

    // Вставляємо новий вузол між current і current->next
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

    if (index < Size / 2) { // Рух від голови
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    }
    else { // Рух від хвоста
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
    if (index < 0 || index >= Size) { // Перевіряємо, чи індекс у допустимих межах
        std::cerr << "Invalid index\n";
        return;
    }

    Node* temp;

    if (index == 0) { // Видалення першого елемента
        temp = head;
        head = head->next; // Оновлюємо голову списку
        if (head)
            head->prev = nullptr; // Якщо список не порожній, від'єднуємо попередній вузол
        else
            tail = nullptr; // Якщо після видалення список порожній, оновлюємо `tail`
    }
    else if (index == Size - 1) { // Видалення останнього елемента
        temp = tail;
        tail = tail->prev; // Оновлюємо хвіст списку
        if (tail)
            tail->next = nullptr; // Якщо список не порожній, від'єднуємо наступний вузол
        else
            head = nullptr; // Якщо після видалення список порожній, оновлюємо `head`
    }
    else { // Видалення елемента всередині списку
        Node* current;

        // Вибираємо оптимальний напрямок пошуку
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
        temp->prev->next = temp->next; // Попередній вузол з'єднуємо з наступним
        temp->next->prev = temp->prev; // Наступний вузол з'єднуємо з попереднім
    }

    delete temp; // Видаляємо вузол з пам'яті
    Size--; // Зменшуємо розмір списку
}

template<typename T>
void DoublyLinkedList<T>::push_back(T val)
{
    Node* newNode = new Node(val); // Створюємо новий вузол

    if (!head) { // Якщо список порожній, новий елемент стає і головою, і хвостом
        head = tail = newNode;
    }
    else { // Додаємо вузол після поточного `tail`
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode; // Оновлюємо `tail`
    }
    Size++; // Збільшуємо розмір списку
}

template<typename T>
void DoublyLinkedList<T>::print()
{
    Node* current = head; // Починаємо з голови
    while (current)
    {
        std::cout << current->data << " "; // Виводимо поточний елемент
        current = current->next; // Переходимо до наступного вузла
    }
    std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::printEnd()
{
    Node* current = tail; // Починаємо з хвоста
    while (current)
    {
        std::cout << current->data << " "; // Виводимо поточний елемент
        current = current->prev; // Переходимо до попереднього вузла
    }
    std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
    while (head) // Поки список не порожній
    {
        Node* temp = head; // Тимчасовий вказівник на `head`
        head = head->next; // Зміщуємо `head` на наступний вузол
        delete temp; // Видаляємо вузол
    }
    tail = nullptr; // Очищаємо `tail`
    Size = 0; // Обнуляємо розмір списку
}

template<typename T>
int DoublyLinkedList<T>::get_size() { return Size; }


template<typename T>
bool DoublyLinkedList<T>::isEmpty() const { return head == nullptr; }

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() { clear(); }
