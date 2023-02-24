/*//selection sort
#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < N - 1; i++) { //i가 N-1번 반복
		int minIdx = i;
		for (int j = i + 1; j < N; j++) { //j가 N-1번 반복
			minIdx = (arr[minIdx] > arr[j] ? j : minIdx); //삼항연산자
		}
		if (minIdx == i)continue;

		int temp = arr[minIdx];
		arr[minIdx] = arr[i];
		arr[i] = temp;
	}
	for (int k = 0; k < N; k++) {
		cout << arr[k] << '\n';
	}
}*/

//insertion sort
#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++) {
		int key = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (key < arr[j]) //key보다 왼쪽에 있는 값이 더 클경우 값 교환
			{	arr[j + 1] = arr[j];
				arr[j] = key;
			}
			else break; //key의 값이 전 값보다 더 크면 바로 for문 나옴
		}
	}
	for (int k = 0; k < N; k++) {
		cout << arr[k] << "\n";
	}
	delete[]arr;
}