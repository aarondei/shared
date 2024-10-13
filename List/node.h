#pragma once // avoid redeclaration issue caused by multiple file inclusions

struct Node {
    int elem;
    Node* prev;
    Node* next;
};