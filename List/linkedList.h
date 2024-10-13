#pragma once
#include "node.h"
#include "list.h"
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

class Singly : public List {
    protected:
        Node* head;
        Node* tail;
        int size;

    public:
        Singly() {
            head = tail = nullptr;
            size = 0;
        }
        ~Singly() {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            head = tail = nullptr;
            size = 0;
        }

        void addFirst(int num) {
            Node* n = new Node;
            n->elem = num;
            n->next = head;

            if (!head) {
                head = tail = n;
            }
            else {
                n->next = head;
                head = n;
            }
            size++;
        }
        void addLast(int num) {
            Node* n = new Node;
            n->elem = num;
            n->next = nullptr;

            if (!head) {
                head = tail = n;
            }
            else {
                tail->next = n;
                tail = n;
            }
            size++;
        }
        int removeFirst() {
            if (!head) {
                cout << "(empty)\n";
                return numeric_limits<int>::min();
                // least possible int
            }
                
            int ret = head->elem;
            Node* temp = head;
            
            if (head == tail) {
                delete temp;
                head = tail = nullptr;
            }
            else {
                head = head->next;
                delete temp;
            }
            size--;
            return ret;
        }
        int removeLast() {
            if (!head) {
                cout << "(empty)\n";
                return numeric_limits<int>::min();
            }

            int ret = tail->elem;
            Node* temp = tail;

            if (head == tail) {
                delete temp;
                head = tail = nullptr;
            }
            else {
                Node* curr = head;
                while (curr->next != tail) {
                    curr = curr->next;
                }

                tail = curr;
                tail->next = nullptr;
                delete temp;
            }
            size--;
            return ret;
        }
        
        void addAt(int num, int pos) {
            return;
        }
        //int removeNum(int num);
        //int removePos(int pos);
        //int removeAll(int num);

        int getSize() {
            return size;
        }
        int get(int pos) {
            if (!head || pos < 1 || pos >= size +1) {
                return numeric_limits<int>::min();
            }
            
            Node* curr = head;
            int i = 1;
            while (i != pos) {
                curr = curr->next;
                i++;
            }
            return curr->elem;
        }
        int getMiddle() {
            if (!head) {
                return numeric_limits<int>::min();
            }

            Node* fast = head;
            Node* mid = head;
            Node* slow = nullptr;

            while (fast && fast->next) {
                slow = mid;
                mid = mid->next;
                fast = fast->next->next;
            }

            if (!fast) {
                return (mid->elem + slow->elem) / 2;
            }
            else {
                return mid->elem;
            }
        }
        
        void print() {
            if (!head) {
                cout << "(empty)\n";
                return;
            }

            Node* curr = head;
            bool first = true;
            while (curr) {
                if (!first) {
                    cout << " -> ";
                }

                cout << curr->elem;
                curr = curr->next;
                first = false;
            }
            cout << endl << endl;
        }   
        void reset() {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            head = tail = nullptr;
            size = 0;
        }
};

class Doubly : public Singly {
    private:
        void removeNode(Node* n) {
            Node* pred = n->prev;
            Node* succ = n->next;
            pred->next = succ;
            succ->prev = pred;
            delete n;
            size--;
        }
        void addBetween(Node* pred, Node* succ, int num) {
            Node* n = new Node;
            n->elem = num;
            n->prev = pred;
            n->next = succ;
            pred->next = n;
            succ->prev = n;
            size++;
        }

    public:
        Doubly() {
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        ~Doubly() {
            Node* curr = head->next;
            while (curr != tail) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            delete head;
            delete tail;
            head = tail = nullptr;
            size = 0;
        }

        void addFirst(int num) {
            Node* n = new Node;
            n->elem = num;
            n->prev = head;
            n->next = head->next;

            head->next->prev = n;
            head->next = n;
            size++;
        }
        void addLast(int num) {
            Node* n = new Node;
            n->elem = num;
            n->next = tail;
            n->prev = tail->prev;

            tail->prev->next = n;
            tail->prev = n;
            size++;
        }
        int removeFirst() {
            if (head->next == tail) {
                cout << "(empty)\n";
                return numeric_limits<int>::min();
            }

            int ret = head->next->elem;

            Node* temp = head->next;
            head->next = temp->next;
            temp->next->prev = head;

            delete temp;
            size--;
            return ret;
        }
        int removeLast() {
            if (tail->prev == head) {
                cout << "(empty)\n";
                return numeric_limits<int>::min();
            }

            int ret = tail->prev->elem;

            Node* temp = tail->prev;
            tail->prev = temp->prev;
            temp->prev->next = tail;

            delete temp;
            size--;
            return ret;
        }

        void addAt(int pos, int num) {
            if (pos < 1 || pos > size +1) {
                cout << "Invalid position\n";
                return;
            }

            Node* n = new Node;
            n->elem = num;

            // start head
            if (pos <= ceil(size / 2.0)) {
                Node* curr = head->next;

                for (int i = 1; i < pos; i++) {
                    curr = curr->next;
                }

                n->next = curr;
                n->prev = curr->prev;
                curr->prev->next = n;
                curr->prev = n;
            }
            else {
                Node* curr = tail->prev;

                for (int i = size; i > pos; i--) {
                    curr = curr->prev;
                }

                n->next = curr;
                n->prev = curr->prev;
                curr->prev->next = n;
                curr->prev = n;
            }
            size++;
        }

        void print() {
            if (head->next == tail) {
                cout << "(empty)\n";
                return;
            }

            Node* curr = head->next;
            bool first = true;
            while (curr != tail) {
                if (!first) {
                    cout << " -> ";
                }

                cout << curr->elem;
                curr = curr->next;
                first = false;
            }
            cout << endl;

            curr = tail->prev;
            first = true;
            while (curr != head) {
                if (!first) {
                    cout << " <- ";
                }

                cout << curr->elem;
                curr = curr->prev;
                first = false;
            }

            cout << endl << endl;
        }
        void reset() {
            Node* curr = head->next;
            while (curr != tail) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            delete tail;
            head = tail = nullptr;
            size = 0;
        }
};