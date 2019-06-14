/**#include "LinkedList.h"
#include "Contact.h"
template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}
template<class T>
LinkedList<T>::Node::Node(T v)
{
    value = v;
    next = NULL;
}

template<class T>
class LinkedList<T>::Node* LinkedList<T>::addSorted(T v)
{
    Node* Temp = new Node(v);

    Node* current;
    if(head == NULL || head->value >= v)
    {
        Temp->next = head;
        head = Temp;
    }else
    {
        current = head;
        while(current->next != NULL && current->next->value < v)
        {
            current = current->next;
        }
        Temp->next = current->next;
        current->next = Temp;
    }
}
template<class T>
class LinkedList<T>::Node* LinkedList<T>::get(T v)
{
    Node* current;
    current = head;
    while(current != NULL)
    {
        if(current->value == v)
        {
            return current;
        }else{
            current = current->next;
        }
    }
    return NULL;
}
template <class T>
class LinkedList<T>::Iterator LinkedList<T>::Begin()
{
    Iterator it(head);
    return it;
};


template class LinkedList<string>;
template class LinkedList<Contact>;**/
