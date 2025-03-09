#include <iostream>
#include <time.h>

template <typename T>
struct Node
{
    T data;
    Node* next;
};

void fillListINT(Node<int>*& L1);
void fillListCHAR(Node<char>*& L1);
void fillListFLOAT(Node<float>*& L1);
void fillListDOUBLE(Node<double>*& L1);

template <typename T>
void push(Node<T>*& head, T value);

template <typename T>
void clearMemory(Node<T>*& head);

template <typename T>
void findTwins(Node<T>* L1, Node<T>*& L2);

template <typename T>
void print(Node<T>* L1);

enum choice
{
    listCHAR = 1, listINT = 2, listFLOAT = 3, listDOUBLE = 4
};
int main()
{
    setlocale(LC_ALL, "ru");

    int choice = 0;
    std::cout << "Выберите тип данных для списков: 1 - char, 2 - int, 3 - float, 3 - double. Ваш выбор: ";
    std::cin >> choice;

    switch (choice)
    {
    case listINT:
    {
        Node<int>* L1 = nullptr;
        fillListINT(L1);
        Node<int>* L2 = nullptr;
        std::cout << "Список L1: ";
        print(L1);
        findTwins(L1, L2);
        std::cout << "Список L2 составленный из близнецов в списке L1: ";
        Node<int>* current = L2;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
        clearMemory(L1);
        clearMemory(L2);
        return 0;
    }
    case listCHAR:
    {
        Node<char>* L1 = nullptr;
        fillListCHAR(L1);
        Node<char>* L2 = nullptr;
        std::cout << "Список L1: ";
        print(L1);
        findTwins(L1, L2);
        std::cout << "Список L2 составленный из близнецов в списке L1: ";
        Node<char>* current = L2;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
        clearMemory(L1);
        clearMemory(L2);
        return 0;
    }
    case listFLOAT:
    {
        Node<float>* L1 = nullptr;
        fillListFLOAT(L1);
        Node<float>* L2 = nullptr;
        std::cout << "Список L1: ";
        print(L1);
        findTwins(L1, L2);
        std::cout << "Список L2 составленный из близнецов в списке L1: ";
        Node<float>* current = L2;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
        clearMemory(L1);
        clearMemory(L2);
        return 0;
    }
    case listDOUBLE:
    {
        Node<double>* L1 = nullptr;
        fillListDOUBLE(L1);
        Node<double>* L2 = nullptr;
        std::cout << "Список L1: ";
        print(L1);
        findTwins(L1, L2);
        std::cout << "Список L2 составленный из близнецов в списке L1: ";
        Node<double>* current = L2;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
        clearMemory(L1);
        clearMemory(L2);
        return 0;
    }
    default:
        std::cout << "Не верный выбор типа данных!" << std::endl;
        break;
    }
    return 0;
}

void fillListINT(Node<int>*& L1)
{
    srand(time(NULL));

    int hipotam;

    for (int i = 1; i <= 10; i++)
    {
        hipotam = rand() % 15;
        push(L1, hipotam);
    }
}
void fillListCHAR(Node<char>*& L1)
{
    srand(time(NULL));

    char hipotam;

    for (int i = 1; i <= 10; i++)
    {
        hipotam = 'A' + rand() % 26;
        push(L1, hipotam);
    }
}
void fillListFLOAT(Node<float>*& L1)
{
    srand(time(NULL));

    float hipotam;

    for (int i = 1; i <= 10; i++)
    {
        hipotam = (rand() % 1500) / 100.0 + 0.01;
        push(L1, hipotam);
    }
}
void fillListDOUBLE(Node<double>*& L1)
{
    srand(time(NULL));

    double hipotam;

    for (int i = 1; i <= 10; i++)
    {
        hipotam = (rand() % 1500) / 100.0 + 0.01;
        push(L1, hipotam);
    }
}

template <typename T>
void print(Node<T>* top)
{
    while (top)
    {
        std::cout << top->data << ' '; top = top->next;
    }
    std::cout << "\n";
}

template <typename T>
void push(Node<T>*& head, T value)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

template <typename T>
void clearMemory(Node<T>*& head)
{
    while (head != nullptr)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void findTwins(Node<T>* L1, Node<T>*& L2)
{
    Node<T>* current1 = L1;
    while (current1 != nullptr)
    {
        int count = 0;
        Node<T>* current2 = L1;
        while (current2 != nullptr)
        {
            if (current1->data == current2->data)
            {
                count++;
            }
            current2 = current2->next;
        }
        if (count == 2)
        {
            Node<T>* temp = L2;
            bool alreadyInL2 = false;
            while (temp != nullptr)
            {
                if (temp->data == current1->data)
                {
                    alreadyInL2 = true;
                    break;
                }
                temp = temp->next;
            }
            if (!alreadyInL2)
            {
                push(L2, current1->data);
            }
        }
        current1 = current1->next;
    }
}
