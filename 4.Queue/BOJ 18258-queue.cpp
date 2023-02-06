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

int main() {//cin과 c의 입력받는 것들, cout과 c의 출력받는 것들을 서로 순서를 구별할수 없게 만든다 대신 c++ 버퍼만 사용해서 속도는 빨라진다. 따라서 이걸 쓰게되면 c의 표준 입출력 문자와 같이 쓸수 없게 된다.
	ios::sync_with_stdio(false);//c++로 알고리즘을 풀때 실행속도를 높이기 위해,iostream과 stdio의 버퍼를 모두 사용하기 때문에 딜레이가 발생하는 것을 동기화를 비활성화 시켜준다.
	cin.tie(NULL); //cin과 cout의 묶음을 풀어준다
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
			cout << qu.pop() << '\n';//endl로 개행을 하면 개행문자출력과 출력버퍼를 비우는 역할까지 같이 하기 때문에 딜레이가 발생한다.
		}
		else if (command == "size") {
			cout << qu.size() << '\n';
		}
		else if (command == "empty") {
			cout << qu.empty() << '\n';

		}
		else if (command == "front") {
			cout << qu.front() << '\n';
		}
		else {
			cout << qu.back() << '\n';
		}
	}
	return 0;
}
