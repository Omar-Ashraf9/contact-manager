#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H
#include "LinkedList.h"
#include "Contact.h"
#include "Treap.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ContactManager
{
    friend class Contact;
private:
    LinkedList<Contact> contacts;
    Treap<string, Contact*> tree;/// for Task 2
public:
    ContactManager(){};
    bool loadFromFile(string fileName)
    {
        ifstream check(fileName,ios::in);
        string temp;
        if(check.is_open() && check.good())
        {
            while(getline(check,temp))
            {
                string number;
                string name;
                istringstream s(temp);
                s >> number;
                getline(s,name);
                add(name,number);
            }
            check.close();
            return true;
        }
        else
        {
            return false;
        }
    }
    void add(string name, string phone_number)
    {
        LinkedList<Contact>::Node* check;

        check = contacts.get(name);

        Contact object;
        object.name = name;
        if(check == NULL)
        {
            object.addPhoneNumber(phone_number);
            tree.Insert(phone_number, &(contacts.addSorted(object)->value));
        }
        else
        {
            check->value.addPhoneNumber(phone_number);
            tree.Insert(phone_number,&(check->value));
        }
    }

    void displayNumber(string phone_number)
    {
        Contact* c = tree.Find(phone_number);
        if (c == NULL)
        {
            cout << "can't find this number in call log" << endl;
            cout << phone_number <<endl;
            return;
        }
        else
        {
            cout << "This number belong to " ;
            cout << c->getName() <<endl;
        }

    }

    friend ostream& operator<<(ostream& o, ContactManager & c)
    {
        o << "The Existing names: " << c.contacts;
        return o;
    }
};

#endif // CONTACTMANAGER_H


