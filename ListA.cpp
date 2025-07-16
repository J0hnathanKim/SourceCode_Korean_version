#include <iostream>
#include "ListA.h"

using namespace std;

// �⺻ ������
listClass::listClass() : Count(0) {
    cout << "[������] ����Ʈ ������" << endl;
}

// ���� ������
listClass::listClass(const listClass& L) {
    Count = L.Count;
    for (int i = 0; i < Count; i++) {
        Data[i] = L.Data[i];
    }
    cout << "[���� ������] ����Ʈ �����" << endl;
}

// �Ҹ���
listClass::~listClass() {
    cout << "[�Ҹ���] ����Ʈ ������" << endl;
}

// ���� �Լ�
void listClass::insert(int Position, int item) {
    if (Position < 1 || Position > Count + 1 || Count >= MAX) {
        cout << "���� ��ġ ���� �Ǵ� ����Ʈ ����" << endl;
        return;
    }

    // �ڷ� �� ĭ�� �̵�
    for (int i = Count - 1; i >= Position - 1; i--) {
        Data[i + 1] = Data[i]; // �� ĭ�� �ڷ� �б�
    }
    Data[Position - 1] = item; // ������ ��ġ�� ������ ����
    Count++;
}

// ���� �Լ�
void listClass::Delete(int Position) {
    if (Position < 1 || Position > Count) {
        cout << "���� ��ġ ����" << endl;
        return;
    }

    // ������ ��ġ ������ ��ҵ��� �� ĭ�� ������ ����
    for (int i = Position - 1; i < Count; i++) {
        Data[i] = Data[i + 1]; // �� ĭ�� ������ ����
    }
    Count--;
}

// �� �˻� �Լ�
void listClass::Retrieve(int Position, int& item) {
    if (Position < 1 || Position > Count) {
        cout << "�˻� ��ġ ����" << endl;
        return;
    }
    item = Data[Position - 1]; // �ش� ��ġ�� ������ ��ȯ
}

// ����Ʈ�� ������� Ȯ��
bool listClass::IsEmpty() {
    return Count == 0;
}

// ����Ʈ�� ���� ��ȯ
int listClass::Length() {
    return Count;
}

// ����Ʈ ���� ���
void listClass::print() {
    cout << "����Ʈ ����: ";
    for (int i = 0; i < Count; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;
}
