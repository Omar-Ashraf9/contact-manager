#ifndef CONTACT_H
#define CONTACT_H
#include "LinkedList.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;


class Contact {

friend class ContactManager;

private:

	string name;
	LinkedList<string> phone_numbers;

public:

	Contact()
	{

	}
	Contact(string n)
	{
        name = n;
	}
	void addPhoneNumber(string number)
	{
        phone_numbers.addSorted(number);

	}
	string getName()
	{
	    return name;
	}
	bool operator<(const Contact & c)
	{
        if(this->name < c.name)
        {
            return true;
        }else{
            return false;
        }
	}
	bool operator==(const Contact & c)
	{
        if(this->name == c.name)
        {
            return true;
        }else{
            return false;
        }
	}
	bool operator>=(const Contact & c)
	{
        if(this->name >= c.name)
        {
            return true;
        }else{
            return false;
        }
	}
	bool operator>(const Contact & c)
	{
        if(this->name > c.name)
        {
            return true;
        }else{
            return false;
        }
	}
	friend ostream& operator<<(ostream& o, Contact & c)
	{
	    o << "The contact name is: " << c.name << endl;
	    o << "And it's numbers are: " << endl;
	    o << c.phone_numbers;

	    return o;
	}
};

#endif // CONTACT_H
