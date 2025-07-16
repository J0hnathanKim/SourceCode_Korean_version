#ifndef LISTA_H
#define LISTA_H

const int MAX = 100;

class listClass {
public:
    listClass();                             // 기본 생성자
    listClass(const listClass& L);           // 복사 생성자
    ~listClass();                            // 소멸자

    void insert(int Position, int item);     // 삽입
    void Delete(int Position);               // 삭제
    void Retrieve(int Position, int& item);  // 조회
    bool IsEmpty();                          // 비어 있는지 확인
    int Length();                            // 길이 반환
    void print();                            // 전체 출력

private:
    int Count;
    int Data[MAX];
};

#endif
