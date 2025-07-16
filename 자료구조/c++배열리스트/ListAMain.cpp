#include <iostream>
#include "ListA.h"

using namespace std;

int main() {
    cout << "[1] 리스트 L1 생성 및 값 삽입" << endl;
    listClass L1;
    for (int i = 1; i <= 5; i++) {
        L1.insert(i, i * 10); // 10, 20, 30, 40, 50
    }
    L1.print();

    cout << "\n[2] 리스트 L2 = L1; (복사 생성자 호출됨)" << endl;
    listClass L2 = L1; // 복사 생성자 호출
    L2.print();

    cout << "\n[3] L1에 값 추가 (L2는 영향 없어야 함)" << endl;
    L1.insert(6, 60);
    L1.print();
    L2.print(); // 그대로인지 확인

    cout << "\n[4] L1 소멸 예정 (main 함수 종료 시)" << endl;
    return 0;
}
