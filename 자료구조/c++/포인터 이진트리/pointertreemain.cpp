#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 새로운 노드 생성
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("메모리 할당 실패\n");
        return NULL;  // exit(1) 대신 NULL 반환
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 이진 탐색 트리에 삽입
Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// 중위 순회
void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// 전위 순회
void preOrderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// 후위 순회
void postTraversal(Node* root) {
    if (root == NULL) return;
    postTraversal(root->left);
    postTraversal(root->right);
    printf("%d ", root->data);
}

// 검색
Node* search(Node* root, int target) {
    if (root == NULL || root->data == target)
        return root;
    if (target < root->data)
        return search(root->left, target);
    else
        return search(root->right, target);
}

// 최소값 노드 찾기 (삭제 시 필요)
Node* findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// 삭제
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// 트리 전체 파괴
void destroyTree(Node* root) {
    if (root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

// 트리 비어있는지 확인
int isEmpty(Node* root) {
    return root == NULL;
}

// 테스트용 main
int main() {
    Node* root = NULL;

    // 삽입
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);

    printf("중위 순회: ");
    inOrderTraversal(root);
    printf("\n");

    printf("전위 순회: ");
    preOrderTraversal(root);
    printf("\n");

    printf("후위 순회: ");
    postTraversal(root);
    printf("\n");

    Node* found = search(root, 7);
    if (found)
        printf("찾음: %d\n", found->data);
    else
        printf("찾을 수 없음\n");

    root = deleteNode(root, 5);
    printf("5 삭제 후 중위 순회: ");
    inOrderTraversal(root);
    printf("\n");

    destroyTree(root);
    return 0;
}
