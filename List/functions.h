#include "list.h"
#include "linkedList.h"
#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;

void selection() {
    cout << "1. Singly\n2. Doubly\n\n";
    cout << "Enter: ";
}
List* implementation() {
    do {
        char select;
        selection();
        cin >> select;

        switch (select) {
            case '1':
                return new Singly();
            case '2':
                return new Doubly();
            default:
                cout << "Invalid type" << endl << endl;
        }
    } while (true);
}

void interface()
{
    cout << "a. add" << endl;
    cout << "b. add first" << endl;
    cout << "r. remove" << endl;
    cout << "t. remove first" << endl;

    cout << "@. add at" << endl;

    cout << "g. get num" << endl;
    cout << "m. get middle" << endl;

    cout << "s. size" << endl;
    cout << "p. print" << endl;
    cout << "#. reset list" << endl;
    cout << "x. exit" << endl << endl;

    return;
}

void title(List* list)
{
    // equivalent to instanceof in java
    if (dynamic_cast<Doubly*>(list))
    {
        cout << "DOUBLY LINKED LIST\n\n";
        return;
    }
        
    
    if (dynamic_cast<Singly*>(list))
    {
        cout << "SINGLY LINKED LIST\n\n";
        return;
    }
}
void clrscr()
{
    system("cls");
}
void pause()
{
    system("pause");
}