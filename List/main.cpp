#include <iostream>
#include <limits>
#include "functions.h"
#include "linkedList.h"
using namespace std;

int main()
{
    List* list = implementation();
    char op;
    int input, input2, output;

    do
    {
        clrscr();
        title(list);
        interface();
        cout << "Op: ";
        cin >> op;

        switch (op)
        {
            case 'a':
                cout << "Enter num: ";
                cin >> input;
                list->addLast(input);
                break;

            case 'b':
                cout << "Enter num: ";
                cin >> input;
                list->addFirst(input);
                break;

            case 'r':
                output = list->removeLast();
                if (output != numeric_limits<int>::min()) {
                    cout << "Removed: " << output << endl << endl;
                } 
                pause();
                break;
            
            case 't':
                output = list->removeFirst();
                if (output != numeric_limits<int>::min()) {
                    cout << "Removed: " << output << endl << endl;
                }
                pause();
                break;
            
            case '@':
                cout << "Enter pos and num: ";
                cin >> input >> input2;
                list->addAt(input, input2);
                break;

            case 'g':
                cout << "Enter pos: ";
                cin >> input;
                cout << "Node " << input << ": ";
                output = list->get(input);
                if (output != numeric_limits<int>::min()) {
                    cout << output << endl << endl;
                }
                pause();
                break;
            
            case 'm':
                output = list->getMiddle();
                cout << "Middle: ";
                if (output != numeric_limits<int>::min()) {
                    cout << output << endl << endl;
                }
                pause();
                break;

            case 's':
                cout << list->getSize() << " elements\n\n";
                pause();
                break;
            
            case 'p':
                list->print();
                pause();
                break;

            case '#':
                cout << "Reseting list\n";
                list->reset();
                list->print();
                pause();
                break;

            case 'x':
                cout << "Exiting...\n";
                delete list;
                return 0;

            default:
                cout << "Invalid operation\n";
                pause();
        }
    } while (true);
    
    return 0;
}