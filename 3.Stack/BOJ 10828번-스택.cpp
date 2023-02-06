#include<iostream>
using namespace std;
class Stack {
private:
	int* array;
	int capacity;
	int stack_top;
public:
	Stack(int);
	~Stack();
	void push(int);
	int pop();
	int size();
	bool empty();
	int top();

};
Stack::Stack(int size) {
	array = new int[size];
	capacity = size;
	stack_top = -1;
}
Stack::~Stack() {
	delete[]array;

}
void Stack::push(int x) {
	if (capacity == stack_top + 1) return; //***
	array[++stack_top] = x;
}
int Stack::pop() {
	if (stack_top == -1) return -1;
	return array[stack_top--];//*** 스택의 맨 위 값을 반환해주고 top의 인덱스를 하나 줄인다.

}
int Stack::size() {
	return stack_top + 1; 
}
bool Stack::empty() {
	if (stack_top == -1) return 1;
	else return 0;
}
int Stack::top() {
	if (stack_top < 0) return -1;
	else return array[stack_top];

}
int main() {
	string cmd;
	int N;
	cin >> N;
	Stack st(N);
	for (int i = 0; i < N; ++i) {
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			st.push(num);
		}
		else if (cmd == "pop") {
			cout<<st.pop()<<endl;
		}
		else if (cmd == "size") {
			cout<<st.size()<<endl;
		}
		else if (cmd == "empty") {
			cout<<st.empty()<<endl;
		}
		else if (cmd == "top") {
			cout<<st.top()<<endl;
		}
	}
	return 0;
}