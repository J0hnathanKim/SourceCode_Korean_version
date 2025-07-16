// ListP.cpp (C++ ���� ����Ʈ ����)
#include "ListP.h"
#include<iostream>
using namespace std;
// ������
listClass::listClass() {
    Count = 0;  // ����Ʈ�� ũ�⸦ 0���� �ʱ�ȭ
    Head = NULL; // Head �����͸� NULL�� �ʱ�ȭ
}

// ����Ʈ�� ������� Ȯ���ϴ� �Լ�
bool listClass::IsEmpty() {
    return (Count == 0); // ����Ʈ�� ũ�Ⱑ 0�̸� true ��ȯ
}

// ����Ʈ�� ���̸� ��ȯ�ϴ� �Լ�
int listClass::Length() {
    return Count; // ����Ʈ�� ũ�⸦ ��ȯ
}

// Ư�� ��ġ�� �������� �����ϴ� �Լ�
void listClass::Insert(int Position, int Item) {
    if (Position < 1 || Position > Count + 1) {
        cout << "Position out of Range" << endl; // ��ȿ���� ���� ��ġ�� ���� �޽��� ���
        return;
    }

    Nptr NewNode = new node; // ���ο� ��带 �������� �Ҵ�
    NewNode->Data = Item; // �� ��忡 �����͸� ����
    NewNode->Next = NULL; // �� ����� Next �����͸� NULL�� ����

    if (Position == 1) { // ù ��° ��ġ�� �����ϴ� ���
        NewNode->Next = Head; // �� ����� Next �����͸� ���� Head�� ����
        Head = NewNode; // Head�� �� ���� ����
    }
    else { // ù ��° ��ġ�� �ƴ� ���
        Nptr Temp = Head;
        for (int i = 1; i < Position - 1; i++) {
            Temp = Temp->Next; // ������ ��ġ ���� ���� �̵�
        }
        NewNode->Next = Temp->Next; // �� ����� Next�� ���� ���� ����
        Temp->Next = NewNode; // ���� ����� Next�� �� ���� ����
    }

    Count++; // ����Ʈ ũ�� ����
}

// Ư�� ��ġ���� �������� �˻��ϴ� �Լ�
void listClass::Retrieve(int Position, int& Item) {
    if (Position < 1 || Position > Count) {
        cout << "Position out of Range" << endl; // ��ȿ���� ���� ��ġ�� ���� �޽��� ���
        return;
    }

    Nptr Temp = Head;
    for (int i = 1; i < Position; i++) {
        Temp = Temp->Next; // �˻��� ��ġ���� �̵�
    }
    Item = Temp->Data; // �ش� ��ġ�� �����͸� Item�� ����
}

// Ư�� ��ġ�� ��带 �����ϴ� �Լ�
void listClass::Delete(int Position) {
    Nptr Temp;

    if (IsEmpty()) {
        cout << "Deletion on Empty List"; // �� ����Ʈ���� ���� �� �޽��� ���
    }
    else if ((Position > Count) || (Position < 1)) {
        cout << "Position out of Range"; // ��ȿ���� ���� ��ġ�� ���� �޽��� ���
    }
    else {
        if (Position == 1) { // ù ��° ��带 �����ϴ� ���
            Nptr p = Head;
            Head = Head->Next; // Head�� �� ��° ���� �̵�
            delete p; // ù ��° ��带 ����
        }
        else { // ù ��° ��尡 �ƴ� ���
            Temp = Head;
            for (int i = 1; i < (Position - 1); i++) {
                Temp = Temp->Next; // ������ ��ġ �ٷ� �� ������ �̵�
            }
            Nptr p = Temp->Next;
            Temp->Next = p->Next; // ������ ��带 �ǳʶٰ� ����
            delete p; // ������ ��带 �޸𸮿��� ����
        }
        Count--; // ����Ʈ ũ�� ����
    }
}

// �Ҹ���
listClass::~listClass() {
    while (!IsEmpty()) {
        Delete(1); // ����Ʈ�� �� ������ ù ��° ��带 ����
    }
}

// ���� ������
listClass::listClass(const listClass& L) {
    Count = L.Count;
    if (L.Head == NULL) {
        Head = NULL; // ���� ����Ʈ�� ��� ������ �� ����Ʈ�� ��� ����
    }
    else {
        Head = new node; // ù ��° ��带 ���� ����
        Head->Data = L.Head->Data; // ù ��° ����� �����͸� ����
        Nptr Temp1 = Head;
        Nptr Temp2 = L.Head->Next;

        while (Temp2 != NULL) { // ���� ����Ʈ�� ���������� ����
            Temp1->Next = new node; // �� ��带 �����
            Temp1 = Temp1->Next;
            Temp1->Data = Temp2->Data; // �����͸� ����
            Temp2 = Temp2->Next; // ���� ���� �̵�
        }
        Temp1->Next = NULL; // ������ ����� Next�� NULL�� ����
    }
}
