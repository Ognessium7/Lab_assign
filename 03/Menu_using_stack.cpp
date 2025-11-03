#include <iostream>
using namespace std;
#define MAXLEN 100

class Stack {

private:
	int element[MAXLEN];
	int topIndex;
	
public:
	Stack() {
		topIndex = -1;
	}

	void push(int x) {
		if (isFull()) {
			cout << "OVERFLOW" << endl;
		} else {
			element[topIndex++] = x;
		}
	}

	void pop() {
		if (isEmpty()) {
			cout << "UNDERFLOW" << endl;
		} else {
			topIndex--;
		}
	}

	int top() {
		if (isEmpty()) {
			cout << "Empty stack" << endl;
			return -1;
		} else {
			return element[topIndex];
		}
	}

	bool isEmpty() {
		return topIndex == -1;
	}

	bool isFull() {
		return topIndex == MAXLEN - 1;
	}

	void print() {
		if (isEmpty()) {
			cout << "Stack is empty." << endl;
		} else {
			for (int i = topIndex; i >= 0; i--) {
				cout << element[i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	int choice = 0;
	Stack S;

	cout << "*********Stack operations using array*********" << endl;
	cout << "----------------------------------------------" << endl;

	while (choice != 4) {
		cout << "Chose one from the below options..." << endl;
		cout << "\n1.Push\n2.Pop\n3.Show\n4.Exit" << endl;
		cout << "\n Enter your choice \n";
		cin >> choice;

		switch (choice) {
		case 1: {
			int el;
			cout << "Enter an element to enter into stack \n";
			cin >> el;
			S.push(el);
			break;
		}
		case 2: {
			S.pop();
			break;
		}
		case 3: {
			S.print();
			break;
		}
		case 4: {
			cout << "Exiting...." << endl;
			break;
		}
		default: {
			cout << "Please Enter valid choice " << endl;
			break;
		}
		}
	}

	return 0;
}
