#include<iostream>
using namespace std;

class Vector {
private:
	int* v_arr;
	int v_capacity;
	int v_size;
	int v_fidx, v_lidx; //fidx:�迭�� ù��° ����, lidx:�迭�� ������ ����

public: //������ ù �뷮�� 2�̴�.
	Vector() :v_capacity(2), v_size(0), v_fidx(0), v_lidx(0) {
		v_arr = new int[2];
	}
	~Vector() {
		delete[]v_arr;
	}
	bool empty() {
		if (v_size == 0) { return 1; } //true
		else { return 0; } //false
	}
	int at(int x) {
		if (x >= v_size || empty()) { return -1; } //x�� v_size���� ũ�ų� ���ٸ� �� �ε���x�� ���� ���̾��ٴ� ���� �� �� �ִ�. 
		else return v_arr[(v_fidx + x) % v_capacity]; //�����迭�� �Ἥ �迭�� ȿ�뼺�� ������.
	} //���� ť�� ���� ����: front,rear���� ť�� �����͸� �ϳ��� dequeue ���ָ� front�� ���� �����Ѵ�. �̶� ť�� ��������� �پ��� �� ������ �����ϱ� ���� ����.
	void set(int idx, int x) {
		if (x >= v_size || empty()) { cout << -1; }
		else { v_arr[(v_fidx + idx) % v_capacity] = x; }

	}
	void doublingUp() {
		int* newArr = new int[v_capacity * 2];
		for (int i = 0; i < v_capacity; i++) {
			newArr[i] = v_arr[(v_fidx + i) % v_capacity];
		}
		v_capacity *= 2;
		v_fidx = 0;
		v_lidx = v_size;
		delete[] v_arr;
		v_arr = newArr; //�ٽ� ���� �����൵ �ǳ�??
	}
	void doublingDown() {
		int* newArr = new int[v_capacity / 2]; //2�� �ٿ��� ��������� ���ų� �̺��� ������ 
		for (int i = 0; i < v_size; i++) {
			newArr[i] = v_arr[(v_fidx + i) % v_capacity];
		}
		v_capacity /= 2;
		v_fidx = 0;
		v_lidx = v_size;
		delete[] v_arr;
		v_arr = newArr;

	}
	void insert(int idx, int x) {
		if (v_size == v_capacity) {
			this->doublingUp(); //this�� �Ƚ��ְ� �ȴٸ�? 
		}
		for (int i = v_size; i > idx; i--) {//�ڿ������� ������ 
			v_arr[(v_fidx + i) % v_capacity] = v_arr[(v_fidx + i - 1) % v_capacity];
			//��ĭ�� �ڷ� �����ش� ������ ��Ұ� ���� ���� 
		}
		v_arr[(v_fidx + idx) % v_capacity] = x;
		v_size++; //������ +1
		v_lidx = (v_lidx + 1) % v_capacity; //�� ������ ��� �� �ε��� �̵�
	}
	void remove(int idx) {
		if (empty() || idx >= v_size) {
			cout << -1;
		}
		else {
			cout << v_arr[(v_fidx + idx) % v_capacity] << '\n';

			for (int i = idx; i < v_size - 1; i++) { //�ڿ��� ������ ����ϱ� v_size-1��ŭ 
				v_arr[(v_fidx + idx) % v_capacity] = v_arr[(v_fidx + idx + 1) % v_capacity];
			}//������ �����ش� ��� �ϳ��� �����Ǿ����� 
			v_size--;
			if (v_lidx == 0) v_lidx = v_capacity;
			v_lidx = (v_lidx - 1) % v_capacity;

			if (v_size <= v_capacity / 2 && v_capacity > 2) {
				this->doublingDown();
			}


		}
	}
	void push_back(int x) {
		if (v_size == v_capacity) {
			this->doublingUp();
		}
		v_arr[(v_lidx++) % v_capacity] = x; //v_lidx+1 �϶� �ȵȴ� 
		v_size++;

	}
	int getSize() { return v_size; }
	void print() {
		if (empty()) {
			cout << -1 << '\n';
			return;
		}
		for (int i = 0; i < v_size; i++) {
			cout << v_arr[(v_fidx + i) % v_capacity] << " ";
		}

	}

};
int main() {
	int N;
	cin >> N;
	Vector vec;
	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;
		if (command == "at") {
			int num;
			cin >> num;
			cout << vec.at(num) << endl;
		}
		else if (command == "set") {
			int idx, num;
			cin >> idx >> num;
			vec.set(idx, num);
		}
		else if (command == "insert") {
			int idx, num;
			cin >> idx >> num;
			vec.insert(idx, num);
		}
		else if (command == "remove") {
			int idx;
			cin >> idx;
			vec.remove(idx);
		}
		else if (command == "push_back") {
			int x;
			cin >> x;
			vec.push_back(x);
		}
		else if (command == "getSize") {
			cout << vec.getSize() << endl;
		}
		else if (command == "empty") {
			cout << vec.empty() << endl;
		}
		else if (command == "print") {
			vec.print();
			cout << endl;
		}
		
	}
	return 0;
}