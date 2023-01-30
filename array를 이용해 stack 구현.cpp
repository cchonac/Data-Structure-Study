/*#include<iostream>
#include<cstdlib>
using namespace std;

#define SIZE 10 //������ �⺻�뷮 ���� 

class Stack {
private:
	int* arr;
	int top;
	int capacity;

public:
	Stack(int size = SIZE); //������
	~Stack();//�Ҹ���

	void push(int);
	int pop();
	int peek();

	int size();
	bool isEmpty();
	bool isFull();

};
Stack::Stack(int size) { //Stack �ʱ�ȭ�� ���� ������
	arr = new int[size];
	capacity = size;
	top = -1; //������� �϶� top�� �ε����� -1
}
Stack::~Stack() {
	delete[] arr;

}
void Stack::push(int x) {
	if (isFull()) {
		cout << "Overflow\n";
		exit(EXIT_FAILURE);
	}
	cout << "Inserting " << x << endl;
	arr[++top] = x;
}

int Stack::pop() {
	if (isEmpty()) {
		cout << "Underflow\n";
		exit(EXIT_FAILURE);
	}
	cout << "Removing" << peek() << endl;

	return arr[top--]; //stack ũ�⸦ 1��ŭ ���̰� pop�� ��Ҹ� ��ȯ�Ѵ�.
}

int Stack::peek() { //stack�� �ֻ��� ��Ҹ� ��ȯ�ϴ� �Լ�
	if (!isEmpty()) {
		return arr[top];
	}
	else {
		exit(EXIT_FAILURE);
	}
}

int Stack::size() {
	return top + 1;
}

bool Stack::isEmpty() {
	return top == -1; //top�� -1�̸� ����ִٴ� ���̴ϱ�
}

bool Stack::isFull() {
	return top == capacity - 1; //or return size()==capacity
}
int main() {
	Stack pt(5);
	pt.push(1);
	pt.push(2);
	cout << pt.peek() << endl;
	pt.push(6);
	cout << pt.peek() << endl;
	pt.pop();
	cout << pt.size() << endl;
	pt.push(3);
	pt.push(4);
	pt.push(10);
	if (pt.isFull())cout << "true" << endl;
	else cout << "fasle" << endl;

}
*/