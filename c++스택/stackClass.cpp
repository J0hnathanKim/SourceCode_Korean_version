#include "stackClass.h"
#include <iostream>

stackClass::stackClass() {}

stackClass::stackClass(const stackClass& S) : L(S.L) {}

stackClass::~stackClass() {}

void stackClass::Push(int Item) {
    if (IsFull()) {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }
    L.Insert(1, Item);  // ������ top�� ����
}

int stackClass::Pop() {
    if (IsEmpty()) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;
    }
    int item;
    L.Retrieve(1, item);  // top�� �������� ��ȸ
    L.Delete(1);  // top�� ������ ����
    return item;
}

bool stackClass::IsEmpty() {
    return L.IsEmpty();
}

bool stackClass::IsFull() {
    return L.Length() == MAX;
}
