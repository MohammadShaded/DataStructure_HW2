#pragma once
#include <iostream>
using namespace std;

struct PolyNode {
    int coefficient;
    int power;
    PolyNode* Next;
};


class PolyLinkedList {
private:
    PolyNode* HeadPtr;
public:
    PolyLinkedList();
    void insertInOrder(int c, int pwr);
    void insertFront(int c, int pwr);
    void insertTail(int c, int pwr);
    int getSize();
    int getValue(int n);
    friend bool operator== (PolyLinkedList R, PolyLinkedList L);
    friend PolyLinkedList addTwoPoly(PolyLinkedList,PolyLinkedList);
    friend ostream& operator <<(ostream&, PolyLinkedList);
    void reset();
};

