#include<iostream>
using namespace std;
void intSwap(int& a, int& b) {
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}
class MaxHeap {
private:
	int* arr;
	int arr_size;
	int capacity;
public:
	MaxHeap(int c);
	void upHeap();
	void downHeap();
	void insert(int num);
	int removeMax();
};
MaxHeap::MaxHeap(int c) {
	capacity = c;
	arr = new int[capacity];
	arr_size = 0;
}
void MaxHeap::upHeap() { //값 삽입 이후에 실행되는 함수
	int curidx = arr_size; //힙 구현시에는 arr[0]에는 아무값도 안들어감.
	while (curidx / 2 > 0) { //등호 들어가면 0을 2로 나누면 계속 0이라 무한루프 생김
		if (arr[curidx] > arr[curidx / 2]) { //자식노드가 더 크면 자리 교환 
			intSwap(arr[curidx], arr[curidx / 2]);
		}
		else break;
		curidx /= 2;

	}
}
void MaxHeap::downHeap() {// 맨위 max 값이랑 말단 노드 값 바꾼 후 실행되는 함수
	int curidx = 1;
	while (curidx*2 <= arr_size) { //자기 자식이 존재하면 while문(heapify) 진행
		int max = arr[curidx];
		int taridx = curidx; //자식노드중 더 큰 노드가 있을때 curidx를 초기화해줄 idx
		if (arr[curidx] < arr[curidx * 2]) { //자식노드가 더 큰경우 교환 
			max = arr[curidx * 2];
			taridx = curidx * 2;
		}
		if (curidx * 2 + 1 <= arr_size && max < arr[curidx * 2 + 1]) {
			max = arr[curidx * 2 + 1];
			taridx = curidx * 2 + 1;
		}
		if (curidx == taridx)break;
		else {
			intSwap(arr[curidx], arr[taridx]);
			curidx = taridx;
		}
	}

}
void MaxHeap::insert(int num) {
	if (arr_size >= capacity) {
		return;
	}
	arr[++arr_size] = num;
	this->upHeap();
}

int MaxHeap::removeMax() {
	if (arr_size <= 0) {
		return 0;
	}

	int max_num = arr[1];
	arr[1] = arr[arr_size--];
	this->downHeap();
	return max_num;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	MaxHeap heap(N);
	while (N--) {
		int num;
		cin >> num;
		if (num == 0) {
			cout<<heap.removeMax()<<"\n";
		}
		else {
			heap.insert(num);
		}
	}
}