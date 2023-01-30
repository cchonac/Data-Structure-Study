#include<iostream>
#include<cstdlib>
using namespace std;

#define SIZE 10 //스택의 기본용량 정의 

class Stack {
private:
	int* arr;
	int top;
	int capacity;

public:
	Stack(int size = SIZE); //생성자
	~Stack();//소멸자

	void push(int);
	int pop();
	int peek();

	int size();
	bool isEmpty();
	bool isFull();

};
Stack::Stack(int size) { //Stack 초기화를 위한 생성자
	arr = new int[size];
	capacity = size;
	top = -1; //공백상태 일땐 top의 인덱스는 -1
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

	return arr[top--]; //stack 크기를 1만큼 줄이고 pop된 요소를 반환한다.
}

int Stack::peek() { //stack의 최상위 요소를 반환하는 함수
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
	return top == -1; //top이 -1이면 비어있다는 뜻이니까
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
