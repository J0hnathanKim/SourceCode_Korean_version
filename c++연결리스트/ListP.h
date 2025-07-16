// ListP.h (C++ Interface by Linked List)

#ifndef LISTP_H
#define LISTP_H

typedef struct nodeRecord {
    int Data;
    struct nodeRecord* Next;
} node;

typedef node* Nptr;

class listClass {
public:
    listClass();
    listClass(const listClass& L);
    ~listClass();

    void Insert(int Position, int Item);
    void Delete(int Position);
    void Retrieve(int Position, int& Item);
    bool IsEmpty();
    int Length();

private:
    int Count;
    Nptr Head;
};

#endif
