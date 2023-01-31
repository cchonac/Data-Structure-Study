#include<iostream>
#include<cstdlib>
using namespace std;
//Queue�� �⺻ �뷮 ����
#define SIZE 1000

class Queue {
	int *arr; //queue�� ��Ҹ� ������ array
	int capacity; //queue�� �ִ� �뷮
	int front; //�� �� ���
	int rear; //������ ��� 
	int count; //queue�� ����ũ��

public:
	Queue(int size = SIZE);
	~Queue();

	int dequeue();
	void enqueue(int x);
	int peek(); //queue���� �����ʰ� ť�� �ִ� �����Ҹ� ��ȯ�մϴ�.
	int size(); //ť�� �ִ� ����� �Ѽ��� ��ȯ�մϴ�.
	bool isEmpty();
	bool isFull();
};
Queue::Queue(int size) {
	arr = new int(size);
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;

}
Queue::~Queue() {
	delete[]arr;

}
//ť�� ��Ҹ� �����ԵǸ� �ڿ� �ִ� �����͵��� ��ĭ�� ������ ��ܿ´�
int Queue::dequeue() {
	if (isEmpty()) {
		cout << "underflow.\n";
		exit(EXIT_FAILURE);
	}
	int x = arr[front];
	cout << "Removing " << x << endl;
	front = (front + 1) % capacity;//ó�� �����°� 0��° �ε���, �״��������°� 1��° �ε���
	count--;//ť ����ũ�� 1��ŭ ����

	return x;
}

void Queue::enqueue(int item) {
	if (isFull()) {
		cout << "Overflow\n.";
		exit(EXIT_FAILURE);

	}
	cout << "Inserting " << item << endl;

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}
int Queue::peek() {
	if (isEmpty()) {
		cout << "ť�� ���� �����ϴ�." << endl;
		exit(EXIT_FAILURE);
	}
	return arr[front];
}
int Queue::size() {
	return count;
}
bool Queue::isEmpty() {
	return (size() == 0);
}
bool Queue::isFull() {
	return (size() == capacity);
}

int main() {
	Queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	cout << q.peek() << endl;
	q.dequeue();
	cout << q.peek() << endl;
	cout << "size: " << q.size() << endl;

	if (q.isEmpty()) {
		cout << "The queue is empty.\n";
	}
	else {
		cout << "The queue is not empty\n";
	}
}