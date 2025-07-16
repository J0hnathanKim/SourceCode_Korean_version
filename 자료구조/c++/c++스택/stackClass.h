#ifndef STACKCLASS_H
#define STACKCLASS_H

#include "listClass.h"

class stackClass {
public:
    stackClass();                              // 생성자
    stackClass(const stackClass& S);            // 복사 생성자
    ~stackClass();                             // 소멸자

    void Push(int Item);                       // 스택 삽입
    int Pop();                                 // 스택 삭제 및 값 반환
    bool IsEmpty();                            // 스택이 비어있으면 True, 아니면 False
    bool IsFull();                             // 스택 원소가 MAX 개이면 True, 아니면 False

private:
    listClass L;                               // 내부 리스트로 스택 구성
    static const int MAX = 100;                // 최대 스택 크기 제한
};

#endif
