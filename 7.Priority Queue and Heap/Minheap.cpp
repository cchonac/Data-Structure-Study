#include<iostream>
using namespace std;
// 자연수면 x 삽입, 0이면 제일 작은값 출력후 제거, 비어있는데 0들어오면 0출력

void intSwap(int& a, int& b) {
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

class MinHeap {
private:
	int* arr;
	int arr_size;
	int capacity;
public:
	MinHeap(int c);
	void upHeap();
	void downHeap();
	void insert(int num);
	int removeMin();

};

MinHeap::MinHeap(int c) {
	capacity = c;
	arr = new int[capacity];
	arr_size = 0;

}
void MinHeap::upHeap() {
	int curidx = arr_size;
	while (curidx / 2 > 0) {
		if (arr[curidx] < arr[curidx / 2]) {
			intSwap(arr[curidx], arr[curidx / 2]);
		}
		else break;

		curidx /= 2;
	}
}
void MinHeap::downHeap() {
	int curidx = 1;
	while (curidx * 2 <= arr_size) { //힙을 다 돌때까지
		int min = arr[curidx];
		int taridx = curidx;
		if (min > arr[curidx * 2]) { //자식노드의 값이 더 작으면
			min = arr[curidx * 2];
			taridx = curidx * 2;
		}
		if (curidx * 2 + 1 <= arr_size && min > arr[curidx * 2 + 1]) {
			min = arr[curidx * 2 + 1];
			taridx = curidx * 2 + 1;
		}
		if (taridx == curidx) break;//왼쪽 자식 오른쪽 자식 다 비교했는데 min이 안바뀌면 break
		else {
			intSwap(arr[curidx], arr[taridx]); //실제 힙에서 두 값의 교환이 일어나는 순간
			curidx = taridx;
		}
	}
}
void MinHeap::insert(int num) {
	if (arr_size >= capacity) {
		return;
	}
	arr[++arr_size] = num;
	this->upHeap();
}
int MinHeap::removeMin() {
	if (arr_size < 1) {
		return 0;
	}
	int result = arr[1];
	arr[1] = arr[arr_size--];
	this->downHeap();

	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	MinHeap heap(N);
	while (N--) {
		int num;
		cin >> num;
		if (num == 0) {
			cout<<heap.removeMin()<<"\n";
		}
		else {
			heap.insert(num);
		}
	}

}
