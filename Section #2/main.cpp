#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "ContactManager.h"

using namespace std;
int main()
{
    ContactManager object;
    object.loadFromFile("all-contacts.txt");
    object.add("omar","01202527666");
    object.displayNumber("01006085394");
    //cout << object << endl;
    //Treap obj;
   // obj.Find()

    return 0;
}
