#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} ArrayList;

// 리스트 초기화
void init(ArrayList* list) {
    list->size = 0;
}

// pos 위치에 item 삽입
int insert(ArrayList* list, int pos, int item) {
    if (list->size >= MAX_SIZE) return 0; // 리스트가 가득 찼을 경우
    if (pos < 1 || pos > list->size + 1) return 0; // 잘못된 위치

    // 뒤로 한 칸씩 이동
    for (int i = list->size - 1; i >= pos - 1; i--) {
        list->data[i + 1] = list->data[i];
    }

    list->data[pos - 1] = item;
    list->size++;
    return 1;
}

// pos 위치의 값 삭제
int delete(ArrayList* list, int pos) {
    if (pos < 1 || pos > list->size) return 0; // 잘못된 위치

    // 삭제한 위치 이후의 요소들을 한 칸씩 앞으로 당기기
    for (int i = pos - 1; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
    return 1;
}

// pos 위치의 값 반환
int retrieve(ArrayList* list, int pos, int* item) {
    if (pos < 1 || pos > list->size) return 0; // 잘못된 위치

    item = list->data[pos - 1];
    return 1;
}

// 리스트가 비었는지 확인
int isEmpty(ArrayList* list) {
    return list->size == 0;
}

// 리스트의 길이 반환
int length(ArrayList* list) {
    return list->size;
}

// 리스트 내용 출력
void printList(ArrayList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    ArrayList list;
    init(&list); // 리스트 초기화

    // 삽입 예제
    insert(&list, 1, 10);  // 첫 번째 위치에 10 삽입
    insert(&list, 2, 20);  // 두 번째 위치에 20 삽입
    insert(&list, 2, 15);  // 두 번째 위치에 15 삽입 (중간 삽입)
    insert(&list, 4, 25);  // 네 번째 위치에 25 삽입

    // 리스트 출력
    printf("리스트 내용: ");
    printList(&list); // 출력: 10 15 20 25

    // 삭제 예제
    delete(&list, 3);  // 세 번째 위치 (20 삭제)
    printf("삭제 후: ");
    printList(&list); // 출력: 10 15 25

    // 값 검색 예제
    int item;
    if (retrieve(&list, 2, &item)) {
        printf("두 번째 위치의 값: %d\n", item); // 출력: 15
    }
    else {
        printf("잘못된 위치\n");
    }

    // 리스트 크기 확인
    printf("리스트의 길이: %d\n", length(&list)); // 출력: 3

    // 리스트가 비었는지 확인
    if (isEmpty(&list)) {
        printf("리스트가 비어있습니다.\n");
    }
    else {
        printf("리스트가 비어있지 않습니다.\n");
    }

    return 0;
}
