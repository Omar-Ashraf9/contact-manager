#ifndef TREAP_H_
#define TREAP_H_
#include <iostream>
using namespace std;
template<class T, class V>
class Treap
{
public:
    class Node
    {
    public:
        Node *left, *right;
        T key;/// number ta2reeban
        V value;///contact name
        int priority;

        Node(T k, V v)
        {
            this->key = k;
            this->value = v;
            this->priority = rand() % 100;
            this->left = NULL;
            this->right = NULL;
        }
        friend ostream& operator<<(ostream &o, Treap<T, V>::Node root)
        {
            o << root.value <<endl;
            return o;
        };
    };
private:
    Node* root;

    Node* rotateRight(Node* Q)
    {
        Node* leftNode = Q->left;
        Node* leftRightNode = Q->left->right;

        leftNode ->right = Q;
        Q->left = leftRightNode;

        Q = leftNode;
        return Q;
    }
    Node* rotateLeft(Node* P)
    {
        Node* rightNode = P->right;
        Node* rightLeftNode = P->right->left;

        rightNode->left = P;
        P ->right = rightLeftNode;

        P = rightNode;
        return P;
    }
    Node* balance(Node* root)
    {
        if(root->left != NULL && root->left->priority > root->priority)
            return rotateRight(root);
        if(root->right != NULL && root->right->priority > root->priority)
            return rotateLeft(root);
        return root;
    }
    Node* Insert(Node* root, T k, V v)
    {
        if(root == NULL)
        {
            return new Node(k,v);
        }
        if(root->key > k)
        {

            root->left = Insert(root->left,k,v);
            root = balance(root);
        }else
        {
            root->right=Insert(root->right,k,v);
            root = balance(root);
        }
        return root;
    }
    V Find(Node* root, T k)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(root->key == k)
        {
            return root->value;
        }
        if(root->key < k)
            return Find(root->right,k);
        if(root->key > k)
            return Find(root->left,k);
    }
public:
    Treap()
    {
        root = NULL;
    }
    void Insert(T k, V v)
    {
        root = Insert(root,k,v);
    }
    V Find(T k)
    {
        return Find(root,k);
    }
    friend ostream& assist(ostream& object, Node* root)
    {
        if(root != NULL)
        {
            if(root->left != NULL)
            {
                assist(object,root->left);
            }

            object << root->value << endl;

            if(root->right != NULL)
            {
                assist(object,root->right);
            }

        }
        else
        {
            object << "The tree is empty!" << endl;
        }
        return object;
    }
    friend ostream& operator<<(ostream &o, Treap<T, V> tree)
    {
        o << assist(o,tree.root);
        return o;
    }
};

#endif /* TREAP_H_ */
