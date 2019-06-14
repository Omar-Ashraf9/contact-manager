/**#include "Treap.h"
#include <time.h>
#include <stdlib.h>

template<class T, class V>
Treap<T,V>::Node::Node(T k,V v)
{
    this->key = k;
    this->value = v;
    this->priority = rand() % 100;
    this->left = NULL;
    this->right = NULL;
}

template<class T, class V>
Treap<T,V>::Treap()
{
    root = NULL;
}
template<class T, class V>
V Treap<T,V> ::Find(T k)
{
    return Find(root,k);
}


template<class T, class V>
V Treap<T,V> ::Find(Node* root,T k)
{
    if(root == NULL || root->key == k)
        return root->value;
    if(root->key < k)
        return Find(root->right,k);
    if(root->key > k)
        return Find(root->left,k);
}

template<class T, class V>
void Treap<T,V> ::Insert(T k, V v)
{
    //Node::priority = rand()%100;
    return Insert(root,k,v);
}
template<class T, class V>
class Treap<T,V>::Node* Treap<T,V>::rotateRight(Node* Q)
{
    Node* leftNode = Q->left;
    Node* leftRightNode = Q->left->right;

    leftNode ->right = Q;
    Q->left = leftRightNode;

    Q = leftNode;
    return Q;
}

template<class T, class V>
class Treap<T,V>::Node* Treap<T,V>::rotateLeft(Node* P)
{
    Node* rightNode = P->right;
    Node* rightLeftNode = P->right->left;

    rightNode->left = P;
    P ->right = rightLeftNode;

    P = rightNode;
    return P;

}
template<class T, class V>
class Treap<T,V>::Node* Treap<T,V> :: balance(Node* root)
{
    if(root->left->priority > root->priority)
        return rotateRight(root);
    if(root->right->priority > root->priority)
        return rotateLeft(root);
    return root;
};

template<class T, class V>
class Treap<T,V>:: Node* Treap<T,V>::Insert(Node*& root, T k, V v)
{
    if(root == NULL)
    {
       root = new Node(k,v);
       return root;
    }
    if(root->key > k)
    {

        Insert(root->left,k,v);
        root = balance(root);
    }
    if(root->key < k)
    {

        Insert(root->right,k,v);
        root = balance(root);

    }
}**/





