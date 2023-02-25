#include<iostream>
using namespace std;

class Array {
private:
	int* arr;
	int arrSize;

public:
	Array(int size) {
		arrSize = size;
		arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			arr[i] = 0;
		}

	}
	int at(int idx) {
		return arr[idx];
	}
	void add(int idx, int value) { ////맨 끝에 있던 배열 값은 사라지게 된다?
		if (idx > arrSize - 1) {// 범위 벗어나면 -1 출력  
			cout << -1 << endl;
		}
		else {
			for (int i = arrSize - 2; i >= idx; i--) { //여기서 -2를 하는 대신 
				arr[i + 1] = arr[i]; //밑에서 i+1부터 연산 들어간다
			}
			arr[idx] = value; 
		}
	}
	void remove(int idx) { //idx의 값을 지우고 왼쪽으로 하나씩 땡긴다. 마지막 원소에는 0이 들어간다
		for (int i = idx; i < arrSize - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[arrSize - 1] = 0;

	}
	void set(int idx, int value) {
		arr[idx] = value;
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

};

int main() {
	Array arr(5);
	arr.add(1, 100);
	arr.add(1, 400); //0 400 100 0 0
	arr.print();
	arr.remove(1);
	arr.print();


}