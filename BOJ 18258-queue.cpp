#include<iostream>
using namespace std;
class Queue {
private:
	int* arr;
	int capacity; //queue의 최대용량
	int count; //queue의 현재 저장크기
	int q_front;
	int q_rear;
public:
	Queue(int size);
	~Queue();
	void push(int x);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
};
Queue::Queue(int size) :q_front(0), q_rear(0), count(0) {
	arr = new int[size];
	capacity = size;

}
Queue::~Queue() {
	delete[] arr;

}
void Queue::push(int x) {
	if (count == capacity) {
		cout << "Overflow.\n";
	}
	arr[q_rear] = x;
	q_rear = (q_rear + 1) % capacity;
	arr[q_rear] = x;
	count++;
}
int Queue::pop() {
	if (count == 0) {
		return -1;
	}
	int num = arr[q_front];
	q_front = (q_front + 1) % capacity;// 큐가 쌓일때 0,1,2,3,4(index)
	count--;
	return num;
}
int Queue::size() {
	return count;
}
bool Queue::empty() {
	if (count == 0) {
		return 1;
	}
	else return 0;
}
int Queue::front() {
	if (count == 0) { return -1; }
	else return arr[q_front];
}
int Queue::back() {
	if (count == 0) { return -1; }
	else return arr[q_rear];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	Queue qu(num);
	for (int i = 0; i < num; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			qu.push(x);
		}
		else if (command == "pop") {
			cout << qu.pop() << endl;
		}
		else if (command == "size") {
			cout << qu.size() << endl;
		}
		else if (command == "empty") {
			cout << qu.empty() << endl;

		}
		else if (command == "front") {
			cout << qu.front() << endl;
		}
		else {
			cout << qu.back() << endl;
		}
	}
	return 0;
}