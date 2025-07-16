#include <iostream>
#include "ListP.h"

using namespace std;

int main() {
    listClass myList;

    // ����Ʈ�� ������ ����
    cout << "Inserting elements into the list..." << endl;
    myList.Insert(1, 10); // ù ��° ��ġ�� 10 ����
    myList.Insert(2, 20); // �� ��° ��ġ�� 20 ����
    myList.Insert(3, 30); // �� ��° ��ġ�� 30 ����

    // ����Ʈ�� ���� ���
    cout << "Length of the list: " << myList.Length() << endl;

    // ����Ʈ���� �����͸� �˻�
    int item;
    myList.Retrieve(1, item); // ù ��° ��ġ�� �����͸� ������
    cout << "Element at position 1: " << item << endl;

    myList.Retrieve(2, item); // �� ��° ��ġ�� �����͸� ������
    cout << "Element at position 2: " << item << endl;

    myList.Retrieve(3, item); // �� ��° ��ġ�� �����͸� ������
    cout << "Element at position 3: " << item << endl;

    // ����Ʈ���� ������ ����
    cout << "Deleting element at position 2..." << endl;
    myList.Delete(2); // �� ��° ��ġ�� ������ ����

    // ����Ʈ�� ���� ���
    cout << "Length of the list after deletion: " << myList.Length() << endl;

    // ����Ʈ���� ������ �˻� (���� �� Ȯ��)
    cout << "Retrieving element at position 2 after deletion..." << endl;
    myList.Retrieve(2, item); // �� ��° ��ġ�� �����͸� ������
    cout << "Element at position 2: " << item << endl;

    return 0;
}
