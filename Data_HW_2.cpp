
#include"Header.h"
#include <iostream>
#include<stack>
using namespace std;

void adder(PolyLinkedList&);

int main()
{
	stack <PolyLinkedList> PolyStack, temp;
	PolyLinkedList List;
	int cmd;
	PolyLinkedList X, Y;
	int x, y;
while (true) {
		cout << "\n1. Add Polynomials to PolyStack from keyboard data entry." << endl;
		cout << "2. Print all polynomials to the console." << endl;
		cout << "3. Test == operator for those two polynomials in PolyStack" << endl;
		cout << "4. Print to console, the number of terms" << endl;
		cout << "5. Print to console values of all polynomials when X = 2, X = 4, X = 5." << endl;
		cout << "6. Print the addition of 2 polynomials" << endl;
		cout << "7. Repeat the test you did for testing function insertFront" << endl;
		cout << "8. Repeat the test you did for testing function insertTail" << endl;
		cout << "9. Exit" << endl;

		cin >> cmd;

switch (cmd) {
 case 1:
			adder(List);
			PolyStack.push(List);
			break;



 case 2:
			temp = PolyStack;
			for (int i = 0; i < PolyStack.size(); i++) {
				cout << temp.top();
				cout << endl;
				temp.pop();
			}
		
			break;


 case 3:
			temp = PolyStack;
			if (temp.size() < 2) { cout << "\nEnter polynomials to cheak == \n"; continue; }
			X = temp.top();
			temp.pop();
			Y = temp.top();
			cout <<"\n" << (X == Y)<<endl;
			break;
 case 4:
			temp = PolyStack;
			for (int i = 0; i < PolyStack.size(); i++) {
				cout<<"#_of terms in Exp"<<i+1<<":" << temp.top().getSize()<<endl;
				temp.pop();
			}
			break;


 case 5:
			temp = PolyStack;
			cout << " * *at X = 2 * *";
			for (int i = 0; i < PolyStack.size(); i++) {
				cout << "\nthe value of Exp" << i+1 << ":" << temp.top().getValue(2);
				temp.pop();
			}
			cout << endl;

			temp = PolyStack;
			cout << " * *at X = 4 * *";
			for (int i = 0; i < PolyStack.size(); i++) {
				cout << "\nthe value of Exp" << i+1 << ":" << temp.top().getValue(4) ;
				temp.pop();
			}				          
			cout << endl;

			temp = PolyStack;
			cout << " * *at X = 5 * *";
			for (int i = 0; i < PolyStack.size(); i++) {
				cout << " \nthe value of Exp" << i +1<< ":" << temp.top().getValue(5) ;
				temp.pop();
			}
			cout << endl;
			break;



 case 6:	
			temp = PolyStack;

			X = temp.top();
			temp.pop();
			Y = temp.top();
			cout << addTwoPoly(X, Y);
			break;


 case 7:	
			cout << "Enter a term" << endl;
			cout << "coefficient :";
			cin >> x;
			cout << "power :";
			cin >> y;

			if (PolyStack.empty()) {
				PolyLinkedList SQ;
				PolyStack.push(SQ);
			}
			PolyStack.top().insertFront(x, y);
			break;


 case 8:
	        cout << "Enter a term" << endl;
			cout << "coefficient :";
			cin >> x;
			cout << "power :";
			cin >> y;
			if (PolyStack.empty()) {
				PolyLinkedList SQ;
				PolyStack.push(SQ);
			}
			PolyStack.top().insertTail(x, y);
			break;


 case 9:
			return 0;
			break;
			
		}
	}
}




void adder(PolyLinkedList& temp)
{
	int num, co, po;
	temp.reset();
	cout << "\nEnter the #_of terms:-  ";
	cin >> num;
	for (int i = 0; i < num; i++) {
		cout << "for the " << i + 1 << "th :-" << endl;
		cout << "Enter the coefficient : ";
		cin >> co;
		cout << "Enter the power : ";
		cin >> po;
		temp.insertInOrder(co, po);
	}
}
