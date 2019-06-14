#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <iostream>
using namespace std;

template<class T>
class LinkedList
{
public:
/// inner class.
    class Node
    {
        friend class LinkedList;
    public:
        T value;
        Node* next;
        Node(T v)
        {
            value = v;
            next = NULL;
        }
    };
////////////////////////////////////////////


public:
    Node* head;
    LinkedList()
    {
        head = NULL;
    }
    Node* addSorted(T v)
    {
        Node* Temp = new Node(v);

        Node* current;
        if(head == NULL || head->value >= v)
        {
            Temp->next = head;
            head = Temp;
        }
        else
        {
            current = head;
            while(current->next != NULL && current->next->value < v)
            {
                current = current->next;
            }
            Temp->next = current->next;
            current->next = Temp;
        }
        return Temp;
    }
    Node* get(T v)
    {
        Node* current;
        current = head;
        while(current != NULL)
        {
            if(current->value == v)
            {
                return current;
            }
            else
            {
                current = current->next;
            }
        }
        return NULL;
    }
    /// operator overloading for printing
    friend ostream& operator <<(ostream& o, LinkedList<T> & c)
    {
        Node* p = c.head;
        while(p != NULL)
        {
            o <<  p->value << endl;
            p = p->next;
        }
        return o;
    }
};

#endif // LINKEDLIST_H
