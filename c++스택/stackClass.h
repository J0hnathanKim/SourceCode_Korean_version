#ifndef STACKCLASS_H
#define STACKCLASS_H

#include "listClass.h"

class stackClass {
public:
    stackClass();                              // ������
    stackClass(const stackClass& S);            // ���� ������
    ~stackClass();                             // �Ҹ���

    void Push(int Item);                       // ���� ����
    int Pop();                                 // ���� ���� �� �� ��ȯ
    bool IsEmpty();                            // ������ ��������� True, �ƴϸ� False
    bool IsFull();                             // ���� ���Ұ� MAX ���̸� True, �ƴϸ� False

private:
    listClass L;                               // ���� ����Ʈ�� ���� ����
    static const int MAX = 100;                // �ִ� ���� ũ�� ����
};

#endif
