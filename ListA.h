#ifndef LISTA_H
#define LISTA_H

const int MAX = 100;

class listClass {
public:
    listClass();                             // �⺻ ������
    listClass(const listClass& L);           // ���� ������
    ~listClass();                            // �Ҹ���

    void insert(int Position, int item);     // ����
    void Delete(int Position);               // ����
    void Retrieve(int Position, int& item);  // ��ȸ
    bool IsEmpty();                          // ��� �ִ��� Ȯ��
    int Length();                            // ���� ��ȯ
    void print();                            // ��ü ���

private:
    int Count;
    int Data[MAX];
};

#endif