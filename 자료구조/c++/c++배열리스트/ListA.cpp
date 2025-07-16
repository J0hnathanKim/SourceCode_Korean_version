#include <iostream>
#include "ListA.h"

using namespace std;

// 기본 생성자
listClass::listClass() : Count(0) {
    cout << "[생성자] 리스트 생성됨" << endl;
}

// 복사 생성자
listClass::listClass(const listClass& L) {
    Count = L.Count;
    for (int i = 0; i < Count; i++) {
        Data[i] = L.Data[i];
    }
    cout << "[복사 생성자] 리스트 복사됨" << endl;
}

// 소멸자
listClass::~listClass() {
    cout << "[소멸자] 리스트 삭제됨" << endl;
}

// 삽입 함수
void listClass::insert(int Position, int item) {
    if (Position < 1 || Position > Count + 1 || Count >= MAX) {
        cout << "삽입 위치 오류 또는 리스트 꽉참" << endl;
        return;
    }

    // 뒤로 한 칸씩 이동
    for (int i = Count - 1; i >= Position - 1; i--) {
        Data[i + 1] = Data[i]; // 한 칸씩 뒤로 밀기
    }
    Data[Position - 1] = item; // 삽입할 위치에 아이템 저장
    Count++;
}

// 삭제 함수
void listClass::Delete(int Position) {
    if (Position < 1 || Position > Count) {
        cout << "삭제 위치 오류" << endl;
        return;
    }

    // 삭제한 위치 이후의 요소들을 한 칸씩 앞으로 당기기
    for (int i = Position - 1; i < Count; i++) {
        Data[i] = Data[i + 1]; // 한 칸씩 앞으로 당기기
    }
    Count--;
}

// 값 검색 함수
void listClass::Retrieve(int Position, int& item) {
    if (Position < 1 || Position > Count) {
        cout << "검색 위치 오류" << endl;
        return;
    }
    item = Data[Position - 1]; // 해당 위치의 아이템 반환
}

// 리스트가 비었는지 확인
bool listClass::IsEmpty() {
    return Count == 0;
}

// 리스트의 길이 반환
int listClass::Length() {
    return Count;
}

// 리스트 내용 출력
void listClass::print() {
    cout << "리스트 내용: ";
    for (int i = 0; i < Count; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;
}
