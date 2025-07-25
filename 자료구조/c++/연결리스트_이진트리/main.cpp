#ifndef BST_H
#define BST_H

struct node {
    char Key;
    node* LChild;
    node* RChild;
};

typedef node* Nptr;

class BST {
public:
    BST();
    ~BST();
    void Insert(char Key);
    void Delete(char Key);
    void Search(char Key);
    void Preorder();
    void Inorder();
    void Postorder();

private:
    Nptr root;
    void Insert(char Key, Nptr& T);
    void Delete(char Key, Nptr& T);
    void Search(char Key, Nptr T);
    void SuccessorCopy(Nptr& T, char& Key);
    void DestroyTree(Nptr T);
    void Preorder(Nptr T);
    void Inorder(Nptr T);
    void Postorder(Nptr T);
};

#endif
