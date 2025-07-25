#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    DestroyTree(root);
}

void BST::DestroyTree(Nptr T) {
    if (T != nullptr) {
        DestroyTree(T->LChild);
        DestroyTree(T->RChild);
        delete T;
    }
}

void BST::Insert(char Key) {
    Insert(Key, root);
}

void BST::Insert(char Key, Nptr& T) {
    if (T == nullptr) {
        T = new node{ Key, nullptr, nullptr };
    }
    else if (Key < T->Key) {
        Insert(Key, T->LChild);
    }
    else if (Key > T->Key) {
        Insert(Key, T->RChild);
    }
    // 중복은 무시
}

void BST::Search(char Key) {
    Search(Key, root);
}

void BST::Search(char Key, Nptr T) {
    if (T == nullptr) {
        cout << Key << " 존재하지 않음!" << endl;
    }
    else if (Key == T->Key) {
        cout << Key << " 존재함!" << endl;
    }
    else if (Key < T->Key) {
        Search(Key, T->LChild);
    }
    else {
        Search(Key, T->RChild);
    }
}

void BST::Delete(char Key) {
    Delete(Key, root);
}

void BST::Delete(char Key, Nptr& T) {
    if (T == nullptr) return;
    if (Key < T->Key) Delete(Key, T->LChild);
    else if (Key > T->Key) Delete(Key, T->RChild);
    else {
        if (T->LChild && T->RChild) {
            SuccessorCopy(T->RChild, T->Key);
            Delete(T->Key, T->RChild);
        }
        else {
            Nptr old = T;
            T = (T->LChild != nullptr) ? T->LChild : T->RChild;
            delete old;
        }
    }
}

void BST::SuccessorCopy(Nptr& T, char& Key) {
    while (T->LChild != nullptr) T = T->LChild;
    Key = T->Key;
}

void BST::Preorder() {
    Preorder(root);
    cout << endl;
}

void BST::Inorder() {
    Inorder(root);
    cout << endl;
}

void BST::Postorder() {
    Postorder(root);
    cout << endl;
}

void BST::Preorder(Nptr T) {
    if (T != nullptr) {
        cout << T->Key << " ";
        Preorder(T->LChild);
        Preorder(T->RChild);
    }
}

void BST::Inorder(Nptr T) {
    if (T != nullptr) {
        Inorder(T->LChild);
        cout << T->Key << " ";
        Inorder(T->RChild);
    }
}

void BST::Postorder(Nptr T) {
    if (T != nullptr) {
        Postorder(T->LChild);
        Postorder(T->RChild);
        cout << T->Key << " ";
    }
}