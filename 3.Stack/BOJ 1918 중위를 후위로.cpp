#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<char>stk;
	string str;
	cin >> str;
	//for���� ���ڿ��� ���̸�ŭ �����鼭 ����ǥ������� ��ȯ
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') { //�����ڰ� �ƴ϶�� ��� ��Ų��.
			cout << str[i];
		}
		else {
			if (str[i] == '(') {
				stk.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/') { //�켱������ ���� �����ڵ�
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) { //������ �ڱ�� ���� �켱������ �����ڰ� �ִٸ� 
					cout << stk.top(); //�켱���� �����ڰ� �� ������ ���ö����� ���� ����
					stk.pop();
				}
				stk.push(str[i]); //+,-�� �ִٸ� str[i]�� ���ÿ� push
			}
			else if (str[i] == '+' || str[i] == '-') { //+,-�� �켱������ ���� ���� �׷��Ƿ� ���þȿ� ����ִ°� ��� �������ش�.
				while (!stk.empty() && stk.top() != '(') { // '('��ȣ�϶��� ���� ���� ������ ������ �����Ŵ� ������׿� ������
					cout << stk.top();
					stk.pop();
				}
				stk.push(str[i]);
			}
			else if (str[i] == ')') { // ')'�� ���Դٴ� ���� �κн��� �Ϸ�Ǿ��ٴ� ���̴� '(' ������ ������ �������ش�
				while (!stk.empty() && stk.top() != '(') {
					cout << stk.top();
					stk.pop();
				}
				stk.pop(); // '('�� �����ش�
			}
		}
	}//��� ���ο����� ������ ���� �������� ����Ѵ�.
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
	return 0;
}