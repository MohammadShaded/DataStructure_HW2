#include"Header.h"
#include<cmath>

PolyLinkedList::PolyLinkedList()
{
    HeadPtr = NULL;
}

void PolyLinkedList::insertInOrder(int c, int pwr)
{
    PolyNode* pt1 = HeadPtr, * pt2 = HeadPtr;
    PolyNode* A = new PolyNode;
    A->coefficient = c;
    A->power = pwr;

      if (pwr < 0) { cout << "this is not poly term"; return; }
        if (HeadPtr==NULL) {
            HeadPtr = A;
            A->Next = NULL;
            return;
        }

         if ( pt2->power < A->power) {
        A->Next = pt2;
        HeadPtr = A;
        return;

        }

       // if (pt2->coefficient = A->coefficient) {
       //// cout << "The Node cannot be added";
       // return;

       // }

    while (pt2 != NULL)
    {

        if (pt2->power == A->power) {
            //cout << "The Node cannot be added";
            return;
        }

        if (pt2->Next == NULL) { pt2->Next = A; A->Next = NULL; return; }


        pt1 = pt2;
        pt2 = pt2->Next;
        if (pt2->power < A->power) {
            pt1->Next = A;
            A->Next = pt2;
            return;
        }

       
    }
}

void PolyLinkedList::insertFront(int c, int pwr)
{
    PolyNode *A=new PolyNode;
    A->coefficient = c;
    A->power = pwr;

    if (HeadPtr == NULL) { 
        HeadPtr = A;
        A->Next = NULL;
        return; }

    if (HeadPtr->power < A->power) {
        A->Next = HeadPtr;
        HeadPtr = A;
        return;
    }
    else cout << "The Node cannot be added";
}

void PolyLinkedList::insertTail(int c, int pwr)
{
    PolyNode*tail,* A = new PolyNode;
    A->coefficient = c;
    A->power = pwr;
    tail = HeadPtr;
    if (HeadPtr == NULL) {
        HeadPtr = new PolyNode;
        int i= HeadPtr->coefficient=c;
        HeadPtr->power = pwr;
        return;
    }
    while (tail->Next != NULL) { 
        tail = tail->Next; }

    if (HeadPtr == NULL) { HeadPtr = A; A->Next = NULL; return; }
    if (tail->power > A->power) {
        A->Next = NULL;
        tail->Next = A;
        return;
    }
    else cout << "The Node cannot be added";

}

int PolyLinkedList::getSize()
{
    int c = 0;
    PolyNode* p=HeadPtr;
    while (p != NULL) {
        p = p->Next;
        c++;
    }
    return c;
}

int PolyLinkedList::getValue(int n)
{   
    PolyNode *p = HeadPtr;
    int sub = 0;
    while (p != NULL) {
        sub += ((p->coefficient) * (pow(n, p->power)));
        p = p->Next;
    }
    return sub;
}

void PolyLinkedList::reset()
{
    HeadPtr = NULL;
}



bool operator == (PolyLinkedList R, PolyLinkedList L)
{

    PolyNode* p1, * p2;
    p1 = L.HeadPtr;
    p2 = R.HeadPtr;
    if (R.getSize() != L.getSize())return false;
    while (p1 != NULL && p2 != NULL) {
        if ((p1->coefficient != p2->coefficient) || (p1->power != p2->power))return false;
        p1 = p1->Next;
        p2 = p2->Next;

    }
    return true;
}


PolyLinkedList addTwoPoly(PolyLinkedList  R, PolyLinkedList L)
{
    PolyLinkedList sum;
    PolyNode* p1, * p2,*p3;
    p1 = L.HeadPtr;
    p2 = R.HeadPtr;
    for (int i = 0; i < L.getSize(); i++) {

        sum.insertInOrder(0, p1->power);
        p1 = p1->Next;
    }
    for (int i = 0; i < R.getSize(); i++) {
        sum.insertInOrder(0, p2->power);
        p2 = p2->Next;
    }
    p1 = L.HeadPtr;
    p2 = R.HeadPtr;
    p3 = sum.HeadPtr;
    if (p1 == NULL) return R;
    if (p2 == NULL) return L;

    for (int i = 0; i < sum.getSize(); i++) {
        p1 = L.HeadPtr;
        p2 = R.HeadPtr;

        while (p2 != NULL) {
            if (p2->power == p3->power) { p3->coefficient += p2->coefficient; break; }
            p2 = p2->Next;
        }
        while (p1 != NULL) {
            if (p1->power == p3->power) { p3->coefficient += p1->coefficient; break; }
            p1 = p1->Next;
        }

        p3 = p3->Next;
    }


    return sum;
}

ostream& operator<<(ostream& out, PolyLinkedList L)
{
    PolyNode* A = L.HeadPtr;
    int n = L.getSize();
    for (int i = 0; i < n; i++) {

        out << A->coefficient << "x^" << A->power;
        if (i != n - 1)cout << "  +  ";
        A= A->Next;
    }
   
    return out;
}

 

