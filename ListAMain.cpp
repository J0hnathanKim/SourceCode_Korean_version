#include <iostream>
#include "ListA.h"

using namespace std;

int main() {
    cout << "[1] ����Ʈ L1 ���� �� �� ����" << endl;
    listClass L1;
    for (int i = 1; i <= 5; i++) {
        L1.insert(i, i * 10); // 10, 20, 30, 40, 50
    }
    L1.print();

    cout << "\n[2] ����Ʈ L2 = L1; (���� ������ ȣ���)" << endl;
    listClass L2 = L1; // ���� ������ ȣ��
    L2.print();

    cout << "\n[3] L1�� �� �߰� (L2�� ���� ����� ��)" << endl;
    L1.insert(6, 60);
    L1.print();
    L2.print(); // �״������ Ȯ��

    cout << "\n[4] L1 �Ҹ� ���� (main �Լ� ���� ��)" << endl;
    return 0;
}
