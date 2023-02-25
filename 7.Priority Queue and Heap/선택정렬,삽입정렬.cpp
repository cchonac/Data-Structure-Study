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
	
	for (int i = 0; i < N - 1; i++) { //i�� N-1�� �ݺ�
		int minIdx = i;
		for (int j = i + 1; j < N; j++) { //j�� N-1�� �ݺ�
			minIdx = (arr[minIdx] > arr[j] ? j : minIdx); //���׿�����
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
			if (key < arr[j]) //key���� ���ʿ� �ִ� ���� �� Ŭ��� �� ��ȯ
			{	arr[j + 1] = arr[j];
				arr[j] = key;
			}
			else break; //key�� ���� �� ������ �� ũ�� �ٷ� for�� ����
		}
	}
	for (int k = 0; k < N; k++) {
		cout << arr[k] << "\n";
	}
	delete[]arr;
}