/**#include "Contact.h"
#include "LinkedList.h"
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

Contact::Contact()
{
    //ctor
}
Contact::Contact(string n)
{
    name = n;
}
void Contact::addPhoneNumber(string number)
{
    phone_numbers.addSorted(number);
}
string Contact::getName()
{
    return name;
}
bool Contact::operator<(const Contact & c)
{
    if(this->name < c.name)
    {
        return true;
    }else{
        return false;
    }
}
bool Contact::operator==(const Contact & c)
{
    if(this->name == c.name)
    {
        return true;
    }else{
        return false;
    }

}
bool Contact::operator>=(const Contact & c)
{
    if(this->name >= c.name)
    {
        return true;
    }else{
        return false;
    }
}
bool Contact::operator>(const Contact & c)
{
    if(this->name > c.name)
    {
        return true;
    }else{
        return false;
    }
}
**/
