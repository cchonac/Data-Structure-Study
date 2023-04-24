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
void MaxHeap::upHeap() { //�� ���� ���Ŀ� ����Ǵ� �Լ�
	int curidx = arr_size; //�� �����ÿ��� arr[0]���� �ƹ����� �ȵ�.
	while (curidx / 2 > 0) { //��ȣ ���� 0�� 2�� ������ ��� 0�̶� ���ѷ��� ����
		if (arr[curidx] > arr[curidx / 2]) { //�ڽĳ�尡 �� ũ�� �ڸ� ��ȯ 
			intSwap(arr[curidx], arr[curidx / 2]);
		}
		else break;
		curidx /= 2;

	}
}
void MaxHeap::downHeap() {// ���� max ���̶� ���� ��� �� �ٲ� �� ����Ǵ� �Լ�
	int curidx = 1;
	while (curidx*2 <= arr_size) { //�ڱ� �ڽ��� �����ϸ� while��(heapify) ����
		int max = arr[curidx];
		int taridx = curidx; //�ڽĳ���� �� ū ��尡 ������ curidx�� �ʱ�ȭ���� idx
		if (arr[curidx] < arr[curidx * 2]) { //�ڽĳ�尡 �� ū��� ��ȯ 
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