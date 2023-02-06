#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int num;
	cin >> num;
	string str;
	cin >> str;
	double* numbers = new double[num];
	for (int i = 0; i < num; i++) {
		cin >> numbers[i];
	}
	double* stack = new double[int(str.size())] {0};
	int topidx = -1;
	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			stack[++topidx] = numbers[str[i] - 'A'];
		}
		else {
			double b = stack[topidx--];
			double a = stack[topidx--];
			if (str[i] == '+') {
				stack[++topidx] = a + b; /* stack[++topidx] 먼저 topidx 증가 시키고 값 넣어줘야함*/
			}
			else if (str[i] == '*') {
				stack[++topidx] = a * b;
			}
			else if (str[i] == '-') {
				stack[++topidx] = a - b;
			}
			else if (str[i] == '/') {
				stack[++topidx] = a / b;
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << stack[topidx];
	delete[]stack;
	delete[]numbers;

}
