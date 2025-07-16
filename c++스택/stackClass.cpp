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
    L.Insert(1, Item);  // 스택의 top에 삽입
}

int stackClass::Pop() {
    if (IsEmpty()) {
        std::cout << "Stack Underflow" << std::endl;
        return -1;
    }
    int item;
    L.Retrieve(1, item);  // top의 아이템을 조회
    L.Delete(1);  // top의 아이템 삭제
    return item;
}

bool stackClass::IsEmpty() {
    return L.IsEmpty();
}

bool stackClass::IsFull() {
    return L.Length() == MAX;
}
