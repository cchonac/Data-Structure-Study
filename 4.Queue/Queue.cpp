#include<iostream>
#include<cstdlib>
using namespace std;
//Queue의 기본 용량 정의
#define SIZE 1000

class Queue {
	int *arr; //queue의 요소를 저장할 array
	int capacity; //queue의 최대 용량
	int front; //맨 앞 요소
	int rear; //마지막 요소 
	int count; //queue의 현재크기

public:
	Queue(int size = SIZE);
	~Queue();

	int dequeue();
	void enqueue(int x);
	int peek(); //queue에서 빼지않고 큐에 있는 전면요소를 반환합니다.
	int size(); //큐에 있는 요소의 총수를 반환합니다.
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
//큐가 요소를 빼내게되면 뒤에 있던 데이터들이 한칸씩 앞으로 당겨온다
int Queue::dequeue() {
	if (isEmpty()) {
		cout << "underflow.\n";
		exit(EXIT_FAILURE);
	}
	int x = arr[front];
	cout << "Removing " << x << endl;
	front = (front + 1) % capacity;//처음 나가는건 0번째 인덱스, 그다음나가는건 1번째 인덱스
	count--;//큐 실제크기 1만큼 감소

	return x;
}

void Queue::enqueue(int item) {
	if (isFull()) {
		cout << "Overflow\n.";
		exit(EXIT_FAILURE);

	}
	cout << "Inserting " << item << endl;

	rear = (rear + 1) % capacity; //capacity로 나머지를 구하는 건 용량을 넘어서는 원형 구조라고 생각하고 큐가 구성될때까지 감안
	arr[rear] = item;
	count++;
}
int Queue::peek() {
	if (isEmpty()) {
		cout << "큐에 값이 없습니다." << endl;
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
