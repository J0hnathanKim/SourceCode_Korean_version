#include <iostream>
#include "ListP.h"

using namespace std;

int main() {
    listClass myList;

    // 리스트에 데이터 삽입
    cout << "Inserting elements into the list..." << endl;
    myList.Insert(1, 10); // 첫 번째 위치에 10 삽입
    myList.Insert(2, 20); // 두 번째 위치에 20 삽입
    myList.Insert(3, 30); // 세 번째 위치에 30 삽입

    // 리스트의 길이 출력
    cout << "Length of the list: " << myList.Length() << endl;

    // 리스트에서 데이터를 검색
    int item;
    myList.Retrieve(1, item); // 첫 번째 위치의 데이터를 가져옴
    cout << "Element at position 1: " << item << endl;

    myList.Retrieve(2, item); // 두 번째 위치의 데이터를 가져옴
    cout << "Element at position 2: " << item << endl;

    myList.Retrieve(3, item); // 세 번째 위치의 데이터를 가져옴
    cout << "Element at position 3: " << item << endl;

    // 리스트에서 데이터 삭제
    cout << "Deleting element at position 2..." << endl;
    myList.Delete(2); // 두 번째 위치의 데이터 삭제

    // 리스트의 길이 출력
    cout << "Length of the list after deletion: " << myList.Length() << endl;

    // 리스트에서 데이터 검색 (삭제 후 확인)
    cout << "Retrieving element at position 2 after deletion..." << endl;
    myList.Retrieve(2, item); // 두 번째 위치의 데이터를 가져옴
    cout << "Element at position 2: " << item << endl;

    return 0;
}
