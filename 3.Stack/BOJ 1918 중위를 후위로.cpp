#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<char>stk;
	string str;
	cin >> str;
	//for문을 문자열의 길이만큼 돌리면서 후위표기식으로 변환
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') { //연산자가 아니라면 출력 시킨다.
			cout << str[i];
		}
		else {
			if (str[i] == '(') {
				stk.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/') { //우선순위가 높은 연산자들
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) { //맨위에 자기랑 같은 우선순위의 연산자가 있다면 
					cout << stk.top(); //우선순위 연산자가 더 낮은게 나올때까지 연산 진행
					stk.pop();
				}
				stk.push(str[i]); //+,-만 있다면 str[i]도 스택에 push
			}
			else if (str[i] == '+' || str[i] == '-') { //+,-는 우선순위가 가장 낮다 그러므로 스택안에 들어있는걸 모두 연산해준다.
				while (!stk.empty() && stk.top() != '(') { // '('괄호일때는 아직 식의 연산이 끝나지 않은거니 고려사항에 넣은것
					cout << stk.top();
					stk.pop();
				}
				stk.push(str[i]);
			}
			else if (str[i] == ')') { // ')'가 나왔다는 것은 부분식이 완료되었다는 것이니 '(' 나오기 전까지 연산해준다
				while (!stk.empty() && stk.top() != '(') {
					cout << stk.top();
					stk.pop();
				}
				stk.pop(); // '('도 꺼내준다
			}
		}
	}//모든 내부연산이 끝난후 남은 나머지를 출력한다.
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
	return 0;
}