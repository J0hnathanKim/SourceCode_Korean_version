#include "listClass.h"
#include <iostream>

listClass::listClass() {
    Count = 0;
    Head = nullptr;
}

listClass::listClass(const listClass& L) {
    Count = L.Count;
    if (L.Head == nullptr) {
        Head = nullptr;
    }
    else {
        Nptr temp = L.Head;
        Head = new node;
        Head->Data = temp->Data;
        Head->Next = nullptr;
        Nptr last = Head;
        temp = temp->Next;

        while (temp != nullptr) {
            Nptr newNode = new node;
            newNode->Data = temp->Data;
            newNode->Next = nullptr;
            last->Next = newNode;
            last = newNode;
            temp = temp->Next;
        }
    }
}

listClass::~listClass() {
    Nptr temp;
    while (Head != nullptr) {
        temp = Head;
        Head = Head->Next;
        delete temp;
    }
}

void listClass::Insert(int Position, int Item) {
    if (Position < 1 || Position > Count + 1) {
        std::cout << "Position out of range." << std::endl;
        return;
    }

    Nptr newNode = new node;
    newNode->Data = Item;

    if (Position == 1) {
        newNode->Next = Head;
        Head = newNode;
    }
    else {
        Nptr temp = Head;
        for (int i = 1; i < Position - 1; ++i) {
            temp = temp->Next;
        }
        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
    Count++;
}

void listClass::Delete(int Position) {
    if (Position < 1 || Position > Count) {
        std::cout << "Position out of range." << std::endl;
        return;
    }

    Nptr temp;
    if (Position == 1) {
        temp = Head;
        Head = Head->Next;
    }
    else {
        Nptr prev = Head;
        for (int i = 1; i < Position - 1; ++i) {
            prev = prev->Next;
        }
        temp = prev->Next;
        prev->Next = temp->Next;
    }

    delete temp;
    Count--;
}

void listClass::Retrieve(int Position, int& Item) {
    if (Position < 1 || Position > Count) {
        std::cout << "Position out of range." << std::endl;
        return;
    }

    Nptr temp = Head;
    for (int i = 1; i < Position; ++i) {
        temp = temp->Next;
    }
    Item = temp->Data;
}

bool listClass::IsEmpty() {
    return Count == 0;
}

int listClass::Length() {
    return Count;
}
