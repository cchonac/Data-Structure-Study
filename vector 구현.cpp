#include<iostream>
using namespace std;

class Vector {
private:
	int* v_arr;
	int v_capacity;
	int v_size;
	int v_fidx, v_lidx; //fidx:배열의 첫번째 원소, lidx:배열의 마지막 원소

public: //벡터의 첫 용량은 2이다.
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
		if (x >= v_size || empty()) { return -1; } //x가 v_size보다 크거나 같다면 그 인덱스x에 아직 값이없다는 것을 알 수 있다. 
		else return v_arr[(v_fidx + x) % v_capacity]; //원형배열을 써서 배열의 효용성을 높였다.
	} //원형 큐를 쓰는 이유: front,rear에서 큐의 데이터를 하나씩 dequeue 해주면 front의 값이 증가한다. 이때 큐의 가용범위가 줄어들어 이 단점을 보완하기 위한 것임.
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
		v_arr = newArr; //다시 선언 안해줘도 되네??
	}
	void doublingDown() {
		int* newArr = new int[v_capacity / 2]; //2로 줄여도 실제사이즈가 같거나 이보다 작을때 
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
			this->doublingUp(); //this를 안써주게 된다면? 
		}
		for (int i = v_size; i > idx; i--) {//뒤에서부터 앞으로 
			v_arr[(v_fidx + i) % v_capacity] = v_arr[(v_fidx + i - 1) % v_capacity];
			//한칸씩 뒤로 땡겨준다 삽입할 요소가 들어가기 위해 
		}
		v_arr[(v_fidx + idx) % v_capacity] = x;
		v_size++; //사이즈 +1
		v_lidx = (v_lidx + 1) % v_capacity; //맨 마지막 요소 값 인덱스 이동
	}
	void remove(int idx) {
		if (empty() || idx >= v_size) {
			cout << -1;
		}
		else {
			cout << v_arr[(v_fidx + idx) % v_capacity] << '\n';

			for (int i = idx; i < v_size - 1; i++) { //뒤에서 앞으로 땡기니까 v_size-1만큼 
				v_arr[(v_fidx + idx) % v_capacity] = v_arr[(v_fidx + idx + 1) % v_capacity];
			}//앞으로 땡겨준다 요소 하나가 삭제되었으니 
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
		v_arr[(v_lidx++) % v_capacity] = x; //v_lidx+1 일땐 안된다 
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