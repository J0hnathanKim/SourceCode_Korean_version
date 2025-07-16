// ListP.cpp (C++ 연결 리스트 구현)
#include "ListP.h"
#include<iostream>
using namespace std;
// 생성자
listClass::listClass() {
    Count = 0;  // 리스트의 크기를 0으로 초기화
    Head = NULL; // Head 포인터를 NULL로 초기화
}

// 리스트가 비었는지 확인하는 함수
bool listClass::IsEmpty() {
    return (Count == 0); // 리스트의 크기가 0이면 true 반환
}

// 리스트의 길이를 반환하는 함수
int listClass::Length() {
    return Count; // 리스트의 크기를 반환
}

// 특정 위치에 아이템을 삽입하는 함수
void listClass::Insert(int Position, int Item) {
    if (Position < 1 || Position > Count + 1) {
        cout << "Position out of Range" << endl; // 유효하지 않은 위치에 대해 메시지 출력
        return;
    }

    Nptr NewNode = new node; // 새로운 노드를 동적으로 할당
    NewNode->Data = Item; // 새 노드에 데이터를 저장
    NewNode->Next = NULL; // 새 노드의 Next 포인터를 NULL로 설정

    if (Position == 1) { // 첫 번째 위치에 삽입하는 경우
        NewNode->Next = Head; // 새 노드의 Next 포인터를 기존 Head로 설정
        Head = NewNode; // Head를 새 노드로 설정
    }
    else { // 첫 번째 위치가 아닌 경우
        Nptr Temp = Head;
        for (int i = 1; i < Position - 1; i++) {
            Temp = Temp->Next; // 삽입할 위치 이전 노드로 이동
        }
        NewNode->Next = Temp->Next; // 새 노드의 Next를 기존 노드와 연결
        Temp->Next = NewNode; // 이전 노드의 Next를 새 노드로 설정
    }

    Count++; // 리스트 크기 증가
}

// 특정 위치에서 아이템을 검색하는 함수
void listClass::Retrieve(int Position, int& Item) {
    if (Position < 1 || Position > Count) {
        cout << "Position out of Range" << endl; // 유효하지 않은 위치에 대해 메시지 출력
        return;
    }

    Nptr Temp = Head;
    for (int i = 1; i < Position; i++) {
        Temp = Temp->Next; // 검색할 위치까지 이동
    }
    Item = Temp->Data; // 해당 위치의 데이터를 Item에 저장
}

// 특정 위치의 노드를 삭제하는 함수
void listClass::Delete(int Position) {
    Nptr Temp;

    if (IsEmpty()) {
        cout << "Deletion on Empty List"; // 빈 리스트에서 삭제 시 메시지 출력
    }
    else if ((Position > Count) || (Position < 1)) {
        cout << "Position out of Range"; // 유효하지 않은 위치에 대해 메시지 출력
    }
    else {
        if (Position == 1) { // 첫 번째 노드를 삭제하는 경우
            Nptr p = Head;
            Head = Head->Next; // Head를 두 번째 노드로 이동
            delete p; // 첫 번째 노드를 삭제
        }
        else { // 첫 번째 노드가 아닌 경우
            Temp = Head;
            for (int i = 1; i < (Position - 1); i++) {
                Temp = Temp->Next; // 삭제할 위치 바로 전 노드까지 이동
            }
            Nptr p = Temp->Next;
            Temp->Next = p->Next; // 삭제할 노드를 건너뛰고 연결
            delete p; // 삭제할 노드를 메모리에서 해제
        }
        Count--; // 리스트 크기 감소
    }
}

// 소멸자
listClass::~listClass() {
    while (!IsEmpty()) {
        Delete(1); // 리스트가 빌 때까지 첫 번째 노드를 삭제
    }
}

// 복사 생성자
listClass::listClass(const listClass& L) {
    Count = L.Count;
    if (L.Head == NULL) {
        Head = NULL; // 원본 리스트가 비어 있으면 새 리스트도 비어 있음
    }
    else {
        Head = new node; // 첫 번째 노드를 새로 생성
        Head->Data = L.Head->Data; // 첫 번째 노드의 데이터를 복사
        Nptr Temp1 = Head;
        Nptr Temp2 = L.Head->Next;

        while (Temp2 != NULL) { // 원본 리스트를 순차적으로 돌며
            Temp1->Next = new node; // 새 노드를 만들고
            Temp1 = Temp1->Next;
            Temp1->Data = Temp2->Data; // 데이터를 복사
            Temp2 = Temp2->Next; // 다음 노드로 이동
        }
        Temp1->Next = NULL; // 마지막 노드의 Next를 NULL로 설정
    }
}
