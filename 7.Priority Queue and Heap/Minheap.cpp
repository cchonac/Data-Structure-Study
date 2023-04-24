#include<iostream>
using namespace std;
// �ڿ����� x ����, 0�̸� ���� ������ ����� ����, ����ִµ� 0������ 0���

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
	while (curidx * 2 <= arr_size) { //���� �� ��������
		int min = arr[curidx];
		int taridx = curidx;
		if (min > arr[curidx * 2]) { //�ڽĳ���� ���� �� ������
			min = arr[curidx * 2];
			taridx = curidx * 2;
		}
		if (curidx * 2 + 1 <= arr_size && min > arr[curidx * 2 + 1]) {
			min = arr[curidx * 2 + 1];
			taridx = curidx * 2 + 1;
		}
		if (taridx == curidx) break;//���� �ڽ� ������ �ڽ� �� ���ߴµ� min�� �ȹٲ�� break
		else {
			intSwap(arr[curidx], arr[taridx]); //���� ������ �� ���� ��ȯ�� �Ͼ�� ����
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
